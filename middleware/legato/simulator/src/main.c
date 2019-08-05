#include "sim_legato.h"
#include "sim_extmem.h"
#include "sim_time.h"

int main(int argc, char* argv[])
{
    sim_TimeInit();
    
#if LE_EXTERNAL_STREAMING_ENABLED == 1
    sim_ExtMemInitialize();
#endif
    
    run_Legato();
}