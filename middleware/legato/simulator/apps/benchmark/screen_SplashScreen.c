#include "gfx/legato/generated/screen/le_gen_screen_SplashScreen.h"

#include "sim_time.h"

static enum
{
    SCREEN_SETUP = 0,
    SCREEN_MOVE_BAR,
    SCREEN_SWAP_LOGO_ALPHA,
    SCREEN_SHOW_SMALL_ICON,
    SCREEN_END_DELAY,
    SCREEN_WAIT_FOR_NEXT,
    SCREEN_MOVE_TO_NEXT,
    SCREEN_NEXT,
    SCREEN_DONE
} screenState;

static int16_t splashAlpha;
static int32_t barPosX;

#define BAR_DELAY_IN_TICKS       20
#define FADE_DELAY_IN_TICKS      20
#define LOGO_DELAY_IN_TICKS      20
#define SHUTDOWN_DELAY_IN_TICKS  1500

static uint32_t triggerTick;
static uint32_t count;

static void setup()
{
    splashAlpha = 255;

    SplashBar->fn->setX(SplashBar, barPosX);

    SplashPIC32Logo->fn->setAlphaEnabled(SplashPIC32Logo, LE_TRUE);
    SplashPIC32Logo->fn->setAlphaAmount(SplashPIC32Logo, splashAlpha);

    SplashHarmonyLogo->fn->setAlphaEnabled(SplashHarmonyLogo, LE_TRUE);
    SplashHarmonyLogo->fn->setVisible(SplashHarmonyLogo, LE_TRUE);
    SplashHarmonyLogo->fn->setAlphaAmount(SplashHarmonyLogo, 255 - splashAlpha);

    SplashMicrochipLogo->fn->setVisible(SplashMicrochipLogo, LE_TRUE);
    SplashMicrochipLogo->fn->setAlphaEnabled(SplashMicrochipLogo, LE_TRUE);
    SplashMicrochipLogo->fn->setAlphaAmount(SplashMicrochipLogo, 0);
    
    triggerTick = sim_TimeTotal() + BAR_DELAY_IN_TICKS;
                
    screenState = SCREEN_MOVE_BAR;
}

static void moveBar()
{
    if (sim_TimeTotal() >= triggerTick)
    {
        barPosX = barPosX * 3 / 4;

        triggerTick = sim_TimeTotal() + BAR_DELAY_IN_TICKS;
    }
    
    if (barPosX <= 0)
    {
        barPosX = 0;
        
        triggerTick = sim_TimeTotal() + FADE_DELAY_IN_TICKS;
        splashAlpha = 0;
        
        screenState = SCREEN_SWAP_LOGO_ALPHA;
    }

    SplashBar->fn->setX(SplashBar, barPosX);
}

static void fadeLogo()
{
    uint32_t percent;

    if(sim_TimeTotal() < triggerTick)
    {
        return;
    }

    triggerTick = sim_TimeTotal() + FADE_DELAY_IN_TICKS;



    percent = lePercentWholeRounded(splashAlpha, 255);
    percent = lePercentOf(255, percent);
    
    percent = leClampi(0, 255, percent);
    
    //printf("%u, %u\n", currentTick, percent); 

    SplashPIC32Logo->fn->setAlphaAmount(SplashPIC32Logo, 255 - percent);
    SplashHarmonyLogo->fn->setAlphaAmount(SplashHarmonyLogo, percent);

    if (splashAlpha >= 255)
    {
        //PIC32LogoWidget->fn->setVisible(PIC32LogoWidget, LE_TRUE);
        //HarmonyLogoWidget->fn->setVisible(HarmonyLogoWidget, LE_TRUE);
        SplashMicrochipLogo->fn->setAlphaAmount(SplashMicrochipLogo, 0);
        
        triggerTick = sim_TimeTotal() + LOGO_DELAY_IN_TICKS;

        splashAlpha = 0;
        
        screenState = SCREEN_SHOW_SMALL_ICON;
    }
    else
    {
        splashAlpha += 10;
    }
}

static void showMCLogo()
{
    if(sim_TimeTotal() < triggerTick)
    {
        return;
    }

    triggerTick = sim_TimeTotal() + FADE_DELAY_IN_TICKS;

    splashAlpha = leClampi(0, 255, splashAlpha);

    SplashMicrochipLogo->fn->setAlphaAmount(SplashMicrochipLogo, splashAlpha);
    
    if (splashAlpha == 255)
    {
        triggerTick = sim_TimeTotal() + SHUTDOWN_DELAY_IN_TICKS;
    
        screenState = SCREEN_END_DELAY;
    }
    else
    {
        splashAlpha += 10;
    }
}

static void delay()
{
    if (sim_TimeTotal() >= triggerTick)
    {
        screenState = SCREEN_WAIT_FOR_NEXT;
    }
}

void SplashScreen_OnShow()
{
    splashAlpha = 255;
    barPosX = leGetDisplayRect().width;

    screenState = SCREEN_SETUP;
}

void SplashScreen_OnHide()
{

}

void SplashScreen_OnUpdate()
{
    switch (screenState)
    {
        case SCREEN_SETUP:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
                leEvent_GetCount() == 0)
            {
                setup();
            }

            break;
        }
        case SCREEN_MOVE_BAR:
        {
            moveBar();

            break;
        }
        case SCREEN_SWAP_LOGO_ALPHA:
        {
            fadeLogo();

            break;
        }
        case SCREEN_SHOW_SMALL_ICON:
        {
            showMCLogo();

            break;
        }
        case SCREEN_END_DELAY:
        {
            delay();

            break;
        }
        case SCREEN_WAIT_FOR_NEXT:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
                leEvent_GetCount() == 0)
            {
                screenState = SCREEN_MOVE_TO_NEXT;
            }

            break;
        }
        case SCREEN_MOVE_TO_NEXT:
        {
            legato_showScreen(screenID_FPSCounters);

            screenState = SCREEN_DONE;

            break;
        }
        case SCREEN_DONE:
        default:
            break;
    }
}