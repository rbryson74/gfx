#include "sim_driver.h"

#include "SDL.h"

#include "gfx/legato/common/legato_color.h"
#include "gfx/legato/common/legato_pixelbuffer.h"

#include "sim_touch.h"

SDL_Renderer* renderer = NULL;
SDL_Surface* surface = NULL;
SDL_Texture* texture = NULL;
void* window = NULL;

static uint32_t vsyncCount = 0;

#if DRIVER_COLOR_MODE == LE_COLOR_MODE_RGB_565
uint8_t displayBuffer[3 * DRIVER_DISPLAY_WIDTH * DRIVER_DISPLAY_HEIGHT];
#endif

int32_t simDriver_Initialize(void)
{
    SDL_RendererInfo info;
    int32_t idx;
    
    // SDL setup
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("GFX HAL Desktop Driver",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              DRIVER_DISPLAY_WIDTH,
                              DRIVER_DISPLAY_HEIGHT,
                              0);

    if(window == NULL)
        return -1;
        
    for(idx = 0; idx < SDL_GetNumRenderDrivers(); idx++)
    {
        SDL_GetRenderDriverInfo(idx, &info);
        
        if(strcmp(info.name, "opengl") == 0)
            break;
    }
    
    if(idx > 10) // hackhack
        idx = -1;

    renderer = SDL_CreateRenderer(window, idx, SDL_RENDERER_ACCELERATED);
    
    surface = SDL_CreateRGBSurface(0,
                                   DRIVER_DISPLAY_WIDTH,
                                   DRIVER_DISPLAY_HEIGHT,
                                   //16, 0, 0, 0, 0);
                                   24,
                                   0xFF0000,
                                   0x00FF00,
                                   0x0000FF,
                                   0);
    
    return 0;
}

leColorMode simDriver_GetColorMode(void)
{
    return LE_COLOR_MODE_RGB_565;
}

uint32_t simDriver_GetBufferCount(void)
{
    return 1;
}

uint32_t simDriver_GetBufferWidth(void)
{
    return DRIVER_DISPLAY_WIDTH;
}

uint32_t simDriver_GetBufferHeight(void)
{
    return DRIVER_DISPLAY_HEIGHT;
}

leResult simDriver_FillRect(int32_t x,
                            int32_t y,
                            uint32_t w,
                            uint32_t h,
                            leColor clr)
{
    return LE_SUCCESS;
}

leResult simDriver_SetActiveLayer(uint32_t idx)
{
    return 0;
}

int blit = 0;

leResult simDriver_BlitBuffer(int32_t x,
                              int32_t y,
                              lePixelBuffer* buf)
{
    uint32_t pixelX, pixelY;
    leColor src_clr, argb_clr;//, dest_clr;
    uint8_t* data;
    int r, c;
    
    //blit += 1;
    
    //if(blit != 2)
    //    return LE_SUCCESS;
    
    for(r = 0; r < buf->size.height; r++)
    {
        pixelY = r;
        
        //if(r > 1)
        //    return LE_SUCCESS;
        
        for(c = 0; c < buf->size.width; c++)
        {
            pixelX = c;
            
            src_clr = lePixelBufferGet_Unsafe(buf, pixelX, pixelY);
            
            //if(layer->maskEnable == GFX_TRUE && layer->maskColor == src_clr)
            //    continue; 
            
            argb_clr = leColorConvert(DRIVER_COLOR_MODE, LE_COLOR_MODE_RGB_888, src_clr);
            //argb_clr = convertTo32bit(mode, src_clr);
            
            //if((argb_clr & 0xFFFFFF00) > 0)
            //    x = x;
            
            data = surface->pixels;
            data += ((r + y) * surface->pitch) +
                    ((c + x) * surface->format->BytesPerPixel);
            
            /*for(idx = 0; idx < surface->format->BytesPerPixel; idx++)
            {
                data[idx] = ((uint8_t*)argb_clr)[idx];
            }*/
            
            memcpy(data, &argb_clr, surface->format->BytesPerPixel);
            
            //pixel_addr = (uint32_t*)(data);
            
            /*if(layer->alphaEnable == GFX_TRUE)
            {
                //dest_clr = GFX_ColorConvert(GFX_COLOR_MODE_RGBA_8888, AR
                argb_clr = (argb_clr & 0xFFFFFF00) | (layer->alphaAmount);
                dest_clr = GFX_ColorConvert(GFX_COLOR_MODE_ARGB_8888, GFX_COLOR_MODE_RGBA_8888, *pixel_addr);
                
                argb_clr = GFX_ColorBlendAlpha(argb_clr, dest_clr, GFX_COLOR_MODE_RGBA_8888); 
            }*/
            
            //argb_clr = GFX_ColorConvert(GFX_COLOR_MODE_RGBA_8888, GFX_COLOR_MODE_RGB_888, argb_clr);
            
            //*pixel_addr = (argb_clr & 0xFFFFFF) | 0xFF000000;
            //*pixel_addr = argb_clr;
        }
    }
    
    return LE_SUCCESS;
}

int32_t needsSwap = LE_FALSE;

void simDriver_Swap(void)
{
    needsSwap = LE_TRUE;
}

uint32_t simDriver_GetVSYNCCount(void)
{
    return vsyncCount;
}

extern int32_t sim_shouldRun;

static leResult sdlUpdate()
{
	SDL_Event evt;

	/* Check for new events */
    while(SDL_PollEvent(&evt))
    {
        /* If a quit event has been sent */
        if (evt.type == SDL_QUIT)
        {
            /* Quit the application */
            return LE_FAILURE;
        }
        else if(evt.type == SDL_WINDOWEVENT)
        {
            if(evt.window.type != SDL_WINDOWEVENT_MOVED)
            {                
                //printf("forcing redraw\n");
                
                //SDL_UpdateWindowSurface(window);
                SDL_RenderPresent(renderer);
            }
        }
        
        Touch_HandleEvent(&evt);
    }

	return LE_SUCCESS;
}

void simDriver_Update(void)
{
    SDL_Rect rect;
    
    if(sdlUpdate() == LE_FAILURE)
    {
        sim_shouldRun = 0;

        return;
    }

    if(needsSwap == LE_FALSE)
		return;
		
    needsSwap = LE_FALSE;
    
    rect.x = 0;
    rect.y = 0;
    rect.w = DRIVER_DISPLAY_WIDTH;
    rect.h = DRIVER_DISPLAY_HEIGHT;

    //SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 0, 0, 0));
    
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
    SDL_RenderClear(renderer);

    //SDL_SetTextureBlendMode(texture, gfx_to_sdl_bm[layer->blend_mode]);
    SDL_RenderCopy(renderer, texture, &rect, &rect);
    //SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_NONE);
    
    SDL_RenderPresent(renderer);
    SDL_RenderCopy(renderer, texture, &rect, &rect);
    SDL_RenderPresent(renderer);
    
    SDL_DestroyTexture(texture);

    vsyncCount += 1;
}