#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_


#include "Std_Types.h"



void SYSTICK_voidDelayOneSec (void );

void STK_SetCallBack(void(*pf_local)(void));


#endif
