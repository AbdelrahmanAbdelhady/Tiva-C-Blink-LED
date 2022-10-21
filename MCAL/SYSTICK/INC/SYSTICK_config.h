#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_


#define SYSTICK_CLOCK 			SYSTEM_CLOCK
/* options : SYSTEM_CLOCK
  			 PIOSC_DIV_4
 */

#define SYSTICK_INTERRUPT 		DISABLE
/* options : DISABLE
 	 	 	 ENABLE
 */


#define SYSTICK_OPERATION		ENABLE
/* options : DISABLE
 	 	 	 ENABLE
 */

#define SYSTICK_DELAY			0x00FFFFFF





#endif
