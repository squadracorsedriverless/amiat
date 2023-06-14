#ifndef CAN_COMMS_H_
#define CAN_COMMS_H_
#include "can.h"

#define CAN_BOOTLOADER_ID 0x0A6
#define CAN_MISSION_NEXT_ID 0x0A0
#define CAN_MISSION_CONFIRM_ID 0x0A1
#define CAN_MISSION_STATUS_ID 0x0A2
#define CAN_SPARE_LED_0_ID 0x0A3
#define CAN_SPARE_LED_1_ID 0x0A4
#define CAN_SPARE_LED_2_ID 0x0A5

void can_recv(CAN_HandleTypeDef *hcan, uint8_t fifo);

#endif
