/*

  WS2812B CPU and memory efficient library

  Date: 28.9.2016

  Author: Martin Hubacek
          http://www.martinhubacek.cz
          @hubmartin

  Licence: MIT License

*/

#include <stdint.h>
#include <stdlib.h>

#include "spi.h"
#include "stm32l4xx_hal.h"
#include "ws2812_spi.h"

// RGB Framebuffers
// uint8_t frameBuffer[3 * 144]; // = 	{50,0,0,	0,50,0,		0,0,50, 	50,50,0, 	0,50,50, 	50,0,50, };
// uint8_t frameBuffer2[3*6] = {0,0,100, 0,100,100, 100,0,0, 		100,100,0, 	100,100,100, 	0,100,0, };

// Helper defines
#define newColor(r, g, b) (((uint32_t)(r) << 16) | ((uint32_t)(g) << 8) | (b))
#define Red(c) ((uint8_t)((c >> 16) & 0xFF))
#define Green(c) ((uint8_t)((c >> 8) & 0xFF))
#define Blue(c) ((uint8_t)(c & 0xFF))

uint32_t Wheel(uint8_t WheelPos)
{
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85)
    {
        return newColor(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if (WheelPos < 170)
    {
        WheelPos -= 85;
        return newColor(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return newColor(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void visRainbow(uint32_t effectLength)
{
    uint32_t i;
    static uint8_t x = 0;

    x += 1;

    if (x >= 256 * 5)
        x = 0;

    for (i = 0; i < effectLength; i++)
    {
        uint32_t color = Wheel(((i * 256) / effectLength + x) & 0xFF);
        {
            ws2812_spi_set_led(i, WS2812_COLOR(Red(color), Green(color), Blue(color)));
        }
    }
}

void visDots(uint32_t random, uint32_t fadeOutFactor)
{
    uint32_t i;

    for (i = 0; i < WS2812_STRIP_LEN; i++)
    {

        if (rand() % random == 0)
        {
            ws2812_spi_set_led(i, 0xFFFFFF);
        }
        uint32_t color = ws2812_spi_get_led(i);

        if (WS2812_RED(color) > fadeOutFactor)
            ws2812_spi_set_led(i, color - WS2812_RED(color) / fadeOutFactor); // rameBuffer[i * 3 + 0] -= frameBuffer[i * 3 + 0] / fadeOutFactor;
        else
            ws2812_spi_set_led(i, color - WS2812_RED(color)); // frameBuffer[i * 3 + 0] = 0;

        if (WS2812_GREEN(color) > fadeOutFactor)
            ws2812_spi_set_led(i, color - WS2812_GREEN(color) / fadeOutFactor); // rameBuffer[i * 3 + 0] -= frameBuffer[i * 3 + 0] / fadeOutFactor;
        else
            ws2812_spi_set_led(i, color - WS2812_GREEN(color)); // frameBuffer[i * 3 + 0] = 0;

        if (WS2812_BLUE(color) > fadeOutFactor)
            ws2812_spi_set_led(i, color - WS2812_BLUE(color) / fadeOutFactor); // rameBuffer[i * 3 + 0] -= frameBuffer[i * 3 + 0] / fadeOutFactor;
        else
            ws2812_spi_set_led(i, color - WS2812_BLUE(color)); // frameBuffer[i * 3 + 0] = 0;
    }
}

void visHandle2()
{
    static uint32_t timestamp;

    if (HAL_GetTick() - timestamp > 16)
    {
        timestamp = HAL_GetTick();

        visRainbow(WS2812_STRIP_LEN - 4);
        HAL_Delay(10);
        /*
                switch(visSelect)
                {
                    case 0:
                        visRainbow(frameBuffer, sizeof(frameBuffer), 15);
                        break;


                    case 1:
                        visDots(frameBuffer, sizeof(frameBuffer), 50, 40);
                        break;

                }*/
        ws2812_spi_send(&hspi1);
    }
}

void visHandle()
{

    // Update your framebuffer here or swap buffers
    visHandle2();

    // HAL_Delay(2);

    // Signal that buffer is changed and transfer new data
    // ws2812b.start_transfer = 1;
    // ws2812b_handle();
}
