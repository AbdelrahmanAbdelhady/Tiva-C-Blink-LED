#include "Std_Types.h"
#include "BIT_Math.h"

#include "GPIO_interface.h"
#include "GPIO_ppconfig.h"



const Pin_Config_Type PIN_ARR[43] = {
		{PORTA , PIN0 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTA , PIN1 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTA , PIN2 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTA , PIN3 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTA , PIN4 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTA , PIN5 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTA , PIN6 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTA , PIN7 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTB , PIN0 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTB , PIN1 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTB , PIN2 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTB , PIN3 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTB , PIN4 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTB , PIN5 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTB , PIN6 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTB , PIN7 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTC , PIN0 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTC , PIN1 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTC , PIN2 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTC , PIN3 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTC , PIN4 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTC , PIN5 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTC , PIN6 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTC , PIN7 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTD , PIN0 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTD , PIN1 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTD , PIN2 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTD , PIN3 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTD , PIN4 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTD , PIN5 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTD , PIN6 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTD , PIN7 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTE , PIN0 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTE , PIN1 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTE , PIN2 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTE , PIN3 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTE , PIN4 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTE , PIN5 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTF , PIN0 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTF , PIN1 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTF , PIN2 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTF , PIN3 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTF , PIN4 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 }

};



