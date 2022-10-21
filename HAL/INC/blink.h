#ifndef BLINK_H_
#define BLINK_H_

#include "SYSTICK_interface.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"


void HAL_voidBlinkLEDinit ( void ) ;
void HAL_voidBlinkLEDRunnable ( Port_Type port , Pin_Type pin , u8 TimeOn , u8 TimeOff ) ;
	

#endif
