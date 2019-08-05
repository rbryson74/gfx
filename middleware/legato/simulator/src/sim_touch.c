#include "sim_touch.h"

#include "gfx/legato/legato.h"

#include "SDL.h"

#if 0
#define TYPE_TOUCHSCREEN  0

#define TOUCH_EVENT_PRESS       0
#define TOUCH_EVENT_RELEASE     1
#define TOUCH_EVENT_MOVE        2

void touchEventCallback(uint32_t evt)
{
    if(evt == TOUCH_EVENT_PRESS)
	{
        //printf("Touch Down:   %i, %i\n", x, y);
		leInput_InjectTouchDown(0, x, y);
	}
	else if(evt == TOUCH_EVENT_RELEASE)
	{
		//printf("Touch Up:     %i, %i\n", x, y);
		leInput_InjectTouchUp(0, x, y);
	}
	/*else if(evt == EVENT_STILLPRESS)
	{
		printf("Still Press:  %i, %i\n", x, y);
	}*/
	else if(evt == TOUCH_EVENT_MOVE)
	{
		//printf("Move:         %i, %i\n", x, y);
		leInput_InjectTouchMoved(0, x, y);
	}
}
#endif

void Touch_HandleEvent(void* e)
{
    SDL_Event* evt = (SDL_Event*)e;
    SDL_MouseButtonEvent* buttonEvt;
    SDL_MouseMotionEvent* moveEvt;
    
    //int32_t count, i;
    
    //if(callback == NULL)
    //    return;
    
    /*while(1)
    {*/
        /*count = SDL_PeepEvents(events,
                               20,
                               SDL_PEEKEVENT,
                               SDL_MOUSEMOTION,
                               SDL_MOUSEBUTTONUP);
                               
        if(count == 0)
            break;*/
        
        /*for(i = 0; i < count; i++)
        {*/
            if(evt->type == SDL_MOUSEBUTTONDOWN /*&& down == 0*/)
            {
                buttonEvt = (SDL_MouseButtonEvent*)evt;
                
                //callback(TOUCH_EVENT_PRESS, buttonEvt->x, buttonEvt->y);
                
                //down = 1;
                
                //last_x = buttonEvt->x;
                //last_y = buttonEvt->y;
                
                leInput_InjectTouchDown(0, buttonEvt->x, buttonEvt->y);
                
            }
            else if(evt->type == SDL_MOUSEBUTTONUP) 
            {
                buttonEvt = (SDL_MouseButtonEvent*)evt;
                
                //callback(TOUCH_EVENT_RELEASE, buttonEvt->x, buttonEvt->y);
                
                //down = 0;
                
                leInput_InjectTouchUp(0, buttonEvt->x, buttonEvt->y);
            }
            else if(evt->type == SDL_MOUSEMOTION)
            {
                moveEvt = (SDL_MouseMotionEvent*)evt;
                
                //callback(TOUCH_EVENT_MOVE, moveEvt->x, moveEvt->y);
                
                //last_x = moveEvt->x;
                //last_y = moveEvt->y;
                
                leInput_InjectTouchMoved(0, moveEvt->x, moveEvt->y);
            }
        //}
    //}
    
    /*if(callback != NULL && down == 1)
    {
        callback(EVENT_STILLPRESS, last_x, last_y);
    }*/
}