#ifndef CAN_COMMS_H_
#define CAN_COMMS_H_
#include "can.h"

#define CAN_BOOTLOADER_ID 0x0A5
#define CAN_MISSION_NEXT_ID 0x0d2
#define CAN_MISSION_CONFIRM_ID 0x0d3
#define CAN_MISSION_STATUS_ID 0x0d4

void can_recv(CAN_HandleTypeDef *hcan, uint8_t fifo);

#endif
