 

#include "BIT_Math.h"
#include "Std_Types.h"


#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "blink.h"




int main( void )
{
		 HAL_voidBlinkLEDinit();
	
  while (1)
    {
			HAL_voidBlinkLEDRunnable( PORTA , PIN0 , 2 , 1 ) ;
    }
		
		return 0 ;
}

