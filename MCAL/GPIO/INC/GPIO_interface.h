#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_

#include "Std_Types.h"

typedef enum {
	PIN0 ,
	PIN1 ,
	PIN2 ,
	PIN3 ,
	PIN4 ,
	PIN5 ,
	PIN6 ,
	PIN7
}Pin_Type;

typedef enum {
	PORTA ,
	PORTB ,
	PORTC ,
	PORTD ,
	PORTE ,
	PORTF
}Port_Type;



typedef u8 Port_Level_Type ;

typedef enum {
	LOW  ,
	HIGH
}Pin_Level_Type;

typedef enum {
	INPUT ,
	OUTPUT
}Pin_Direction_Type ;

typedef enum {
	PULLUP  ,
	PULLDOWN  ,
	OPEN_DRAIN 
}Pin_Internal_Attach_type;

typedef enum {
	DIO ,
	TIMER ,
	UART ,
	I2C ,
	PWM ,
	ADC ,
	CAN ,
	WDT ,
	SSI
}Pin_Mode_Type;

typedef enum {
	MA_AMPERE_2 ,
	MA_AMPERE_4 ,
	MA_AMPERE_8
}Pin_Output_Currnet_Type;


typedef struct {
	Port_Type port ;
	Pin_Type pin ;
	Pin_Mode_Type mode ;
	Pin_Level_Type level_value ;
	Pin_Direction_Type direction ;
	Pin_Internal_Attach_type attach ;
	Pin_Output_Currnet_Type current ;

}Pin_Config_Type;





void GPIO_voidInit (Pin_Config_Type* config_ptr );

Pin_Level_Type GPIO_u8ReadPin ( Port_Type port , Pin_Type pin ) ;
void GPIO_voidWritePin ( Port_Type port , Pin_Type pin , Pin_Level_Type level );
Port_Level_Type GPIO_u8ReadPort ( Port_Type port ) ;
void GPIO_voidWritePort ( Port_Type port ,  Port_Level_Type level );
Pin_Level_Type GPIO_u8FlipPin ( Port_Type port , Pin_Type pin );


#endif
