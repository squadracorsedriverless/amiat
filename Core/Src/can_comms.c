#include "can_comms.h"
#include "can.h"
#include "main.h"
#include "mission.h"
#include "tlb_battery.h"
#include "utils.h"
#include "ws2812_spi.h"

typedef enum
{
    BUTTON_DOWN = 1,
    BUTTON_UP = 0,
} button_condition;

// Logical state of the button
typedef enum
{
    BUTTON_PRESSED = 0,
    BUTTON_RELEASED = 1,
    BUTTON_LONGPRESS = 2
} button_state;

#define BUTTON_SHORT_PRESS_TIME_MS 30
#define BUTTON_LONG_PRESS_TIME_MS 800

void can_recv(CAN_HandleTypeDef *hcan)
{
    CAN_RxHeaderTypeDef RxHeader;
    uint8_t RxData[8] = {0};

    if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK)
    {
        /* Transmission request Error */
        HAL_CAN_ResetError(hcan);
        // Error_Handler();
    }

    /*Reboot Board - Received command byte from CAN*/
    if ((RxHeader.StdId == CAN_BOOTLOADER_ID) && (RxHeader.DLC == 2) && (RxData[0] == 0xFF) && (RxData[1] == 0x00))
    {
        NVIC_SystemReset();
    }
    else if (RxHeader.StdId == TLB_BATTERY_SHTDWN_LINE_TSAC_STATUS_FRAME_ID && RxHeader.DLC == TLB_BATTERY_SHTDWN_LINE_TSAC_STATUS_LENGTH)
    {
        struct tlb_battery_shtdwn_line_tsac_status_t status;
        tlb_battery_shtdwn_line_tsac_status_unpack(&status, RxData, RxHeader.DLC);

        uint8_t red, green;

        green = tlb_battery_shtdwn_line_tsac_status_shtdwn_tsac_fin_sec_in_active_lvl_decode(status.shtdwn_tsac_fin_sec_in_active_lvl) ? 0xFF : 0;
        red = tlb_battery_shtdwn_line_tsac_status_shtdwn_tsac_init_sec_in_active_lvl_decode(status.shtdwn_tsac_init_sec_in_active_lvl) ? 0 : 0xFF;

        ws2812_spi_set_led(IDX_SPARE_LED_1, WS2812_COLOR(red, green, 0));
    }
    else if (RxHeader.StdId == CAN_BTN_STATUS_ID)
    {
        static button_state state = BUTTON_RELEASED;
        static uint32_t down_time = 0;

        button_condition condition = (RxData[3] >> 2) & 0b1;

        switch (state)
        {
        case BUTTON_RELEASED:
            if (condition == BUTTON_DOWN)
            {
                // If button was up and now is down
                state = BUTTON_PRESSED;
                down_time = HAL_GetTick();
            }
            break;
        case BUTTON_PRESSED:
            if (condition == BUTTON_UP)
            {
                // If button was down and now is up
                if (HAL_GetTick() - down_time >= BUTTON_SHORT_PRESS_TIME_MS)
                {
                    mission_select_next();
                }
                state = BUTTON_RELEASED;
            }
            else if (HAL_GetTick() - down_time > BUTTON_LONG_PRESS_TIME_MS)
            {
                // If button has been down for a while
                mission_confirm();
                state = BUTTON_LONGPRESS;
            }
            break;
        case BUTTON_LONGPRESS:
            if (condition == BUTTON_UP)
            {
                // If button has been down for a while but now is up
                state = BUTTON_RELEASED;
            }
            break;
        }
    }
    else if (RxHeader.StdId == CAN_SPARE_LED_0_ID && RxHeader.DLC == 3)
    {
        ws2812_spi_set_led(IDX_SPARE_LED_0, WS2812_COLOR(RxData[0], RxData[1], RxData[2]));
    }
    else if (RxHeader.StdId == CAN_SPARE_LED_1_ID && RxHeader.DLC == 3)
    {
        // ws2812_spi_set_led(IDX_SPARE_LED_1, WS2812_COLOR(RxData[0], RxData[1], RxData[2]));
    }
    else if (RxHeader.StdId == CAN_SPARE_LED_2_ID && RxHeader.DLC == 3)
    {
        ws2812_spi_set_led(IDX_SPARE_LED_2, WS2812_COLOR(RxData[0], RxData[1], RxData[2]));
    }
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    can_recv(hcan);
}