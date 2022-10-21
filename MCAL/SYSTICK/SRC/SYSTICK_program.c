#include "BIT_Math.h"
#include "Std_Types.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"


static void(*Fptr_STK)(void);



 void SYSTICK_voidDelayOneSec (void )
{
	/* disable systick before init */
	//STCTRL = 0 ;

	/*put the value in STRELOAD register */
	STRELOAD = 0x00f42400 ; // 1s/(1/16Mhz)

	/* clear  STCURRENT register */
	STCURRENT = 0 ;

	/*setting systick clock and interrupt configuration */
	STCTRL |=  0x7;

	/*wait until counter reach 0 */
	//while ( (STCTRL & 0x00010000) == 0 );

	
}


void STK_SetCallBack(void(*pf_local)(void))
{
		Fptr_STK = pf_local;	
}

void SYSTICK_HANDLER ( void ) 
{
	/* clear STCURRENT register and bit counter in STCTRL register*/
	STCURRENT = 0 ;
	
	Fptr_STK () ;
}

