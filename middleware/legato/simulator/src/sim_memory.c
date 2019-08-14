#include "sim_memory.h"
#include "sim_extmem.h"

#include <stdio.h>
#include <stdlib.h>

#if 0
//#define MEM_DEBUG

#ifdef MEM_DEBUG
typedef struct MemoryRecord_t
{
    uint32_t used;
    void* addr;
    size_t size;
} MemoryRecord;

MemoryRecord records[1000] = {0};

void printTotalUsage()
{
    uint32_t total = 0;
    uint32_t i;
    
    for(i = 0; i < 1000; i++)
    {
        if(records[i].used == 1)
            total += records[i].size;          
    }
    
    printf("Total heap used: %u bytes\n", total);
}

void addMemoryRecord(void* ptr, size_t size)
{
    uint32_t i;
    
    for(i = 0; i < 1000; i++)
    {
        if(records[i].used == 0)
        {
            records[i].addr = ptr;
            records[i].size = size;
            records[i].used = 1;
            
            printf("Allocated %u bytes at address 0x%X\n", size, ptr);
            printTotalUsage();
            
            return;
        }
    }
}



void freeMemoryRecord(void* ptr)
{
    uint32_t i;
    
    for(i = 0; i < 1000; i++)
    {
        if(records[i].used == 1 && records[i].addr == ptr)
        {
            printf("Freed %u bytes at address 0x%X\n", records[i].size, ptr);
            records[i].addr = 0;
            records[i].size = 0;
            records[i].used = 0;
            
            printTotalUsage();
            
            return;
        }
    }
}


void addReallocRecord(void* oldPtr, void* newPtr, size_t size)
{
    uint32_t i;
    
    if(oldPtr != newPtr)
    {
        for(i = 0; i < 1000; i++)
        {
            if(records[i].used == 1 && records[i].addr == oldPtr)
            {
                printf("Freed %u bytes at address 0x%X\n", records[i].size, oldPtr);
                records[i].addr = 0;
                records[i].size = 0;
                records[i].used = 0;
                
                printTotalUsage();
                
                return;
            }
        }
        
        for(i = 0; i < 1000; i++)
        {
            if(records[i].used == 0)
            {
                records[i].addr = newPtr;
                records[i].size = size;
                records[i].used = 1;
                
                printf("Allocated %u bytes at address 0x%X\n", size, newPtr);
                printTotalUsage();
                
                return;
            }
        }
    }
    else
    {
        for(i = 0; i < 1000; i++)
        {
            if(records[i].used == 1 && records[i].addr == oldPtr)
            {
                printf("Reallocated %u bytes (was %u) at address 0x%X\n", size, records[i].size, oldPtr);
                records[i].size = size;
                
                printTotalUsage();
                
                return;
            }
        }
    }
}
#endif

void* debugMalloc(size_t size)
{
    void* ptr = malloc(size);
    
    if(ptr == NULL)
        return NULL;
        
    if(size > 1000)
        size = size;
 
#ifdef MEM_DEBUG   
    addMemoryRecord(ptr, size);
#endif

    return ptr;
}

void debugFree(void* addr)
{
#ifdef MEM_DEBUG 
    freeMemoryRecord(addr);
#endif
    
    free(addr);
}

void* debugCalloc(size_t count, size_t size)
{
    void* ptr = calloc(count, size);
  
#ifdef MEM_DEBUG   
    addMemoryRecord(ptr, size);
#endif
    
    return ptr;
}

void* debugRealloc(void* ptr, size_t size)
{
    void* rPtr = realloc(ptr, size);
    
#ifdef MEM_DEBUG 
    addReallocRecord(ptr, rPtr, size);
#endif    
    
    return rPtr;
}

GFXU_MemoryIntf sim_MemoryGetInterface()
{
    GFXU_MemoryIntf intf;
    
#ifdef MEMORY_DEBUG
    intf.heap.malloc = &debugMalloc;
	intf.heap.coherent_alloc = &malloc;
	intf.heap.calloc = &debugCalloc;
	intf.heap.free = &debugFree;
	intf.heap.coherent_free = &free;
	intf.heap.memcpy = &memcpy;
	intf.heap.memset = &memset;
	intf.heap.realloc = &debugRealloc;
	intf.read = &sim_ExtMemReadRequest;
#else
    intf.heap.malloc = &malloc;
	intf.heap.coherent_alloc = &malloc;
	intf.heap.calloc = &calloc;
	intf.heap.free = &free;
	intf.heap.coherent_free = &free;
	intf.heap.memcpy = &memcpy;
	intf.heap.memset = &memset;
	intf.heap.realloc = &realloc;
	intf.read = &sim_ExtMemReadRequest;
#endif

    return intf;
}
#endif