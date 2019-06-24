#include "sim_time.h"

double delta;
size_t ticks;

#ifdef LINUX


struct timeval start;
struct timeval last;

#elif defined WINDOWS

LARGE_INTEGER freq;

LARGE_INTEGER start;
LARGE_INTEGER last;

#endif

#ifdef LINUX

#include <sys/time.h>
#include <unistd.h>

void sim_TimeInit()
{
    delta = 0.0;
    ticks = 0;

    start.tv_sec = 0;
    start.tv_usec = 0;

    gettimeofday(&start, NULL);

    last = start;
}

void sim_TimeUpdate()
{
    struct timeval ts;

    gettimeofday(&ts, NULL);

    delta = (ts.tv_sec - last.tv_sec) * 1000;
    delta += (ts.tv_usec - last.tv_usec) / 1000;

    delta = delta * 0.001; /* convert to seconds */

    last = ts;
}

uint32_t sim_TimeTotal()
{
    size_t tm;

    tm = (last.tv_sec - start.tv_sec) * 1000;
    tm += (last.tv_usec - start.tv_usec) / 1000;

    return tm;
}

void sim_TimeSleep(uint32_t u)
{
    usleep(u);
}

#endif /* LINUX */

#ifdef WINDOWS

#include <windows.h>

double delta;
double frame;
//uint32_t ticks;

LARGE_INTEGER	freq;

LARGE_INTEGER	start;
LARGE_INTEGER	last;

void sim_TimeInit()
{
	freq.QuadPart = 0;
	
	start.QuadPart = 0;
	last.QuadPart = 0;

	delta = 0.0;
	frame = 0.0;

	// get processor clock frequency
	QueryPerformanceFrequency(&freq);	

	// get start time
	QueryPerformanceCounter(&start);
	QueryPerformanceCounter(&last);
}

void sim_TimeUpdate()
{
	LARGE_INTEGER current;

	QueryPerformanceCounter(&current);

	// calculate delta time
	delta = ((((float)current.QuadPart - (float)last.QuadPart)) / (float)freq.QuadPart);
    //frame += delta;
    //ticks = (uint32_t)(delta * 1000);
    
    //if(ticks == 0)
    //    ticks = 1;
        //printf("zero\n");

	// dump old previous time
	last.QuadPart = current.QuadPart;
}

uint32_t sim_TimeTotal()
{
    float t = (((float)last.QuadPart - (float)start.QuadPart)) / (float)freq.QuadPart;
    
    t *= 1000;
    
	return (uint32_t)t;
}

void sim_TimeSleep(uint32_t u)
{
	Sleep(u / 1000);
}

/*uint32_t sim_TimeTicks()
{
    printf("%d\n", ticks);
    return ticks;
}*/

#endif

double sim_TimeDelta()
{
    return delta;
}

