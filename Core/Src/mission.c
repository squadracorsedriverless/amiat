#include "mission.h"
#include "spi.h"
#include "utils.h"
#include "ws2812_spi.h"

#define PERIOD_2HZ_100us 2500 // Duty cycle time to get 2Hz (toggle at 4Hz)

static bool confirmed = false;
static mission_t current_mission = MISSION_NO;

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
        current_mission = mission;
}

void mission_run()
{
    static uint32_t delay_100us_last = 0;
    static mission_t out_mission;

    if (confirmed)
    {
        out_mission = current_mission;
    }
    else
    {
        if (current_mission == MISSION_NO)
        {
            // KITT
            if (delay_fun(&delay_100us_last, 1000))
            {
                static int8_t direction = 1;
                if (out_mission >= NUM_MISSIONS - 1)
                {
                    direction = -1;
                }
                else if (out_mission <= 1)
                {
                    direction = 1;
                }

                out_mission += direction;
            }
        }
        else
        {
            if (delay_fun(&delay_100us_last, PERIOD_2HZ_100us))
            {
                out_mission = (out_mission == current_mission ? MISSION_NO : current_mission);
            }
        }
    }

    ws2812_spi_set_led(1 << (out_mission - 1), WS2812_COLOR(255, 0, 0));
    ws2812_spi_send(&hspi1);
}
