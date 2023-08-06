#include "mission.h"
#include "spi.h"
#include "utils.h"
#include "visEffect.h"
#include "ws2812_spi.h"

#define PERIOD_2HZ_100us 2500 // Duty cycle time to get 2Hz (toggle at 4Hz)

static bool confirmed = false;
static mission_t current_mission = MISSION_NO;
static bool mission_changed = false;

void mission_confirm()
{
    if (mission_get() != MISSION_NO)
        confirmed = true;
}

bool mission_is_confirmed()
{
    return confirmed;
}

void mission_select_next()
{
    if (!confirmed)
    {
        // Cycles through the missions, rolling back to 0 at the end
        mission_set((mission_get() % (NUM_MISSIONS - 1)) + 1);
    }
}

mission_t mission_get()
{
    return current_mission;
}

void mission_set(mission_t mission)
{
    if (!confirmed)
    {
        current_mission = mission;
        mission_changed = true;
    }
}

void mission_run()
{
    static uint32_t delay_100us_last = 0;
    // static mission_t out_mission = MISSION_NO;
    static bool blink = 0;

    if (delay_fun(&delay_100us_last, 400))
    {
        blink = !blink;
    }

    if (confirmed)
    {
        blink = 1;
    }
    else
    {
        if (current_mission == MISSION_NO)
        {
            visHandle();
            return;
            // KITT
            // if (delay_fun(&delay_100us_last, 100))
            //{
            //    static int8_t direction = 1;
            //    if (out_mission >= NUM_MISSIONS - 1)
            //    {
            //        direction = -1;
            //    }
            //    else if (out_mission <= 1)
            //    {
            //        direction = 1;
            //    }

            //    out_mission += direction;
            //}
        }
    }

    for (uint8_t i = 1; i < NUM_MISSIONS; i++)
    {
        if (blink)
        {
            ws2812_spi_set_led(i - 1, i == current_mission ? WS2812_COLOR(255, 0, 0) : 0);
        }
        else
        {
            ws2812_spi_set_led(i - 1, WS2812_COLOR(0, 0, 0));
        }
    }
    ws2812_spi_send(&hspi1);
    HAL_Delay(1);
}
