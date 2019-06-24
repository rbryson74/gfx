#ifndef SIM_EXTMEM_H
#define SIM_EXTMEM_H

#if LE_EXTERNAL_STREAMING_ENABLED == 1

void sim_ExtMemInitialize();

GFX_Result sim_ExtMemReadRequest(GFXU_ExternalAssetReader* reader,
                                 uint32_t location_id,
                                 void* address,
                                 uint32_t size,
                                 uint8_t* buffer,
                                 GFXU_MediaReadRequestCallback_FnPtr cb);
                                 
void sim_ExtMemUpdate();

#endif

#endif // SIM_EXTMEM_H