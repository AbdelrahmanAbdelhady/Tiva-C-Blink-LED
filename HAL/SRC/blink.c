#include "BIT_Math.h"
#include "Std_Types.h"

#include "blink.h"

extern const Pin_Config_Type PIN_ARR[43] ;
static u8 flag_systick ;
extern const NVIC_Config_Type NVIC_Configurition[78] ;

void func (void)
{
	
	flag_systick ++ ;
	SYSTICK_voidDelayOneSec();
}
	



void HAL_voidBlinkLEDinit ( void )
	
{
	RCC_voidEnableSysClock() ;
	GPIO_voidInit(PIN_ARR);
	NVIC_voidInit(NVIC_Configurition);
	
	STK_SetCallBack(func ) ;
	SYSTICK_voidDelayOneSec();
}




void HAL_voidBlinkLEDRunnable ( Port_Type port , Pin_Type pin , u8 TimeOn , u8 TimeOff ) 
{
	static u8 LED_flag = 0 ;
	
	if ( LED_flag == 0 )
	{
		GPIO_voidWritePin ( port , pin , HIGH ) ;
		if ( flag_systick == TimeOn ) 
		{
			flag_systick = 0 ;
			LED_flag = 1 ;
		}
	}
	else if ( LED_flag == 1 ) 
	{
		GPIO_voidWritePin ( port , pin , LOW ) ;
		if ( flag_systick == TimeOff )
		{
			flag_systick = 0 ;
			LED_flag = 0 ;
		}
	}
}
	
	


