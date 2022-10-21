#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_


#define SYSTEM_CLOCK	1
#define PIOSC_DIV_4		0

#define DISABLE 		0
#define ENABLE			1




#define   STCTRL		(*(volatile u32*)(0xE000E010))
#define   STRELOAD		(*(volatile u32*)(0xE000E014))
#define   STCURRENT		(*(volatile u32*)(0xE000E018))


static void SYSTICK_voidDelayOneMilliSec (void);
void SYSTICK_HANDLER ( void ) ;

#endif
