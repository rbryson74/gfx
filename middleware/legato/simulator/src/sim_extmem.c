#include "sim_extmem.h"

#include <stdio.h>
#include <string.h>

#if LE_EXTERNAL_STREAMING_ENABLED == 1

GFXU_ExternalAssetReader* _reader;
uint32_t _location_id;
void* _address;
uint32_t _size;
uint8_t* _buffer;
GFXU_MemoryReadRequestCallback_FnPtr _cb;

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

static void memoryRead()
{
    //printf("mem request: %i\n", requests++);
    if(_location_id == 1)
        memcpy(_buffer, &spi[(uint32_t)_address], _size);
    else if(_location_id == 2)
        memcpy(_buffer, &sqi[(uint32_t)_address], _size);
    
    if(_cb != NULL)
        _cb(_reader);
}

GFX_Result sim_ExtMemReadRequest(GFXU_ExternalAssetReader* reader,
                                 uint32_t location_id,
                                 void* address,
                                 uint32_t size,
                                 uint8_t* buffer,
                                 GFXU_MediaReadRequestCallback_FnPtr cb)
{
    _reader = NULL;
    _cb = NULL;
    
    _location_id = location_id;
    _address = address;
    _size = size;
    _buffer = buffer;
    
    // blocking read
    if(cb == NULL)
    {
        memoryRead();
    }
    // non-blocking read
    else
    {
        _reader = reader;
        _cb = cb;
        
        memWaitCounter = 2;
    }

    return GFX_SUCCESS;
}

void sim_ExtMemUpdate()
{
    if(_reader == NULL)
        return;
        
    memWaitCounter--;
    
    if(memWaitCounter == 0)
    {
        memoryRead();
        
        _reader = NULL;
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
    
    length = strlen(buf);
    
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
    
    ptr = &line[0];
    
    chars = strlen(&line[1]) - 1;
    
    if(*ptr != ':')
        return; // shouldn't happen;
    
    ptr++;
    
    // get record length
    length = getByte(ptr);
    ptr += 2;
    
    checksum = getChecksum(&line[1]);
    
    if(checksum != getByte(&line[1 + ((chars - 2))]))
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