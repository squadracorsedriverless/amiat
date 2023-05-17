#ifndef UTILS_H_
#define UTILS_H_
#include <inttypes.h>

extern uint32_t tick_100us;
uint8_t delay_fun(uint32_t *delay_100us_last, uint32_t delay_100us);
uint32_t tick_get_100us(void);

#endif