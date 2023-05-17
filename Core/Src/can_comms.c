#include "can_comms.h"
#include "main.h"
#include "mission.h"
#include "spi.h"
#include "utils.h"
#include "ws2812_spi.h"

void can_recv(CAN_HandleTypeDef *hcan, uint8_t fifo)
{
    CAN_RxHeaderTypeDef RxHeader;
    uint8_t RxData[8] = {0};

    if (HAL_CAN_GetRxMessage(hcan, fifo, &RxHeader, RxData) != HAL_OK)
    {
        /* Transmission request Error */
        HAL_CAN_ResetError(hcan);
        Error_Handler();
    }

    /*Reboot Board - Received command byte from CAN*/
    if ((RxHeader.StdId == CAN_BOOTLOADER_ID) && (RxHeader.DLC == 2) && (RxData[0] == 0xFF) && (RxData[1] == 0x00))
    {
        NVIC_SystemReset();
    }
    else if (RxHeader.StdId == CAN_MISSION_NEXT_ID && RxHeader.DLC == 1)
    {
        mission_select_next();
    }
    else if (RxHeader.StdId == CAN_MISSION_CONFIRM_ID && RxHeader.DLC == 1)
    {
        mission_confirm();
    }
}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    can_recv(hcan, CAN_RX_FIFO1);
}
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    can_recv(hcan, CAN_RX_FIFO0);
}
