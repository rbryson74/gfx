#include "sim_extmem.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "gfx/legato/legato.h"
#include "gfx/legato/generated/le_gen_assets.h"

#if LE_STREAMING_ENABLED == 1

leStream* _stream;
uint32_t _address;  // address
uint32_t _size;  // dest size
uint8_t* _buf;

static uint32_t memWaitCounter = 0;

// virtual peripheral storage devices
uint8_t spi[1024 * 1000 * 2]; // 2 MB
uint8_t sqi[1024 * 1000 * 2]; // 2 MB

static void decodeHexFile(const char* path, uint8_t* buffer);

uint16_t highAddress;

void sim_ExtMemInitialize()
{
    memset(spi, 0, sizeof(spi));
    memset(sqi, 0, sizeof(sqi));
    
    decodeHexFile("./spi.hex", spi);
    decodeHexFile("./sqi.hex", sqi);
}

extern uint8_t leGenPalette0_data[6];

static void memoryRead()
{
    //printf("mem request: %i\n", requests++);
    if(_stream->desc->location == 1)
    {
        if(_stream->desc == (leStreamDescriptor*)&mchpLogo_mask)
        {
            memcpy(_buf,
                   &((uint8_t*) mchpLogo_mask.buffer.pixels)[_address],
                   _size);
        }
        /*else if(_stream->desc == (leStreamDescriptor*)mchpLogo_mask.palette)
        {
            memcpy(_buf,
                   &((uint8_t*) leGenPalette0_data)[_address],
                   _size);
        }*/
    }
    else if(_stream->desc->location == 2)
    {
        memcpy(_buf, &spi[_address], _size);
    }
    else if(_stream->desc->location == 3)
    {
        memcpy(_buf, &sqi[_address], _size);
    }

    leStream_DataReady(_stream);
}

leResult leApplication_MediaOpenRequest(leStream* strm)
{
    return LE_SUCCESS;
}

leResult leApplication_MediaReadRequest(leStream* strm,
                                        uint32_t address,  // address
                                        uint32_t size,  // dest size
                                        uint8_t* buf)
{
    _stream = strm;
    _address = address;
    _size = size;
    _buf = buf;

    memWaitCounter = 2;

    return LE_SUCCESS;
}

void leApplication_MediaCloseRequest(leStream* strm)
{
    int i = 0;
}

void sim_ExtMemUpdate()
{
    if(_stream == NULL)
        return;
        
    memWaitCounter--;
    
    if(memWaitCounter == 0)
    {
        memoryRead();

        _stream = NULL;
    }
}

static uint8_t getByte(uint8_t* buf)
{
    char data[3];
    
    data[0] = buf[0];
    data[1] = buf[1];
    data[2] = '\0';
    
    return (uint8_t)strtol((const char*)&data, NULL, 16);
    
    //return ((buf[0] - 0x30) * 10) + (buf[1] - 0x30);
}

static uint16_t getWord(uint8_t* buf)
{
    char data[5];
    
    data[0] = buf[0];
    data[1] = buf[1];
    data[2] = buf[2];
    data[3] = buf[3];
    data[4] = '\0';
    
    return (uint16_t)strtol((const char*)&data, NULL, 16);
    //return ((buf[0] - 0x30) * 1000) + ((buf[1] - 0x30) * 100) + ((buf[2] - 0x30) * 10) + (buf[3] - 0x30);
}

static uint8_t getChecksum(uint8_t* buf)
{
    uint8_t checksum = 0;
    uint32_t i;
    uint32_t length;
    
    length = strlen((const char*)buf);
    
    for(i = 0; i < (length - 2) / 2; i++)
    {
        checksum += getByte(buf);
        buf += 2;
    }
    
    for(i = 0; i < 8; i++)
        checksum ^= 1 << i;
    
    return checksum + 1;
}

static void processHexCommand(char line[256], uint8_t* buffer)
{
    uint32_t chars;
    uint32_t length;
    uint8_t type;
    uint8_t checksum;
    uint16_t address;
    uint32_t i;
    uint8_t* ptr;
    uint8_t data;
    
    ptr = (uint8_t*)line;
    
    chars = strlen(&line[1]) - 1;
    
    if(*ptr != ':')
        return; // shouldn't happen;
    
    ptr++;
    
    // get record length
    length = getByte(ptr);
    ptr += 2;
    
    checksum = getChecksum((uint8_t*)&line[1]);
    
    if(checksum != getByte((uint8_t*)&line[1 + ((chars - 2))]))
        return;
    
    // get record address
    address = getWord(ptr);
    ptr += 4;
    
    // get record type
    type = getByte(ptr);
    ptr += 2;
    
    switch(type)
    {
        case 0: // data record
        {
            for(i = 0; i < length; i++)
            {
                data = getByte(ptr);
                ptr += 2;
                
                buffer[(highAddress << 16) + address] = data;
                
                address++;
            }
            
            break;
        }
        case 1: // end of file
        {
            break;
        }
        case 4: // extended linear address
        {   
            highAddress = getWord(ptr);
            ptr += 4;
            
            break;
        }
    }
}

void decodeHexFile(const char* path, uint8_t* buffer)
{
    FILE* file = fopen(path, "r");
    char buf[256];
    uint32_t length = 0;
    
    memset(buf, 0, sizeof(buf));
    
    if(file == NULL)
        return;
        
    while(1)
    {
        buf[length] = fgetc(file);
        
        if(buf[length] == EOF && length == 0)
            break;
        
        if(buf[length] == EOF || buf[length] == '\n')
        {
            processHexCommand(buf, buffer);
       
            memset(buf, 0, sizeof(buf));
            length = 0;
        }
        else
            length++;
    }
    
    fclose(file);
}

#endif