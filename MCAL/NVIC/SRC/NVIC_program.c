#include "Std_Types.h"
#include "BIT_Math.h"


#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_ppconfig.h"

//extern NVIC_Config_Type NVIC_Configurition[138] ;


void NVIC_voidEnableInterrupt ( NVIC_IRQ_Type IRQ_type )
{
	u8 reg_address = IRQ_type / 32 ;
	u8 pin = IRQ_type % 32 ;


	if ( reg_address == 0)
	{
		SET_BIT(NVIC->EN[0] , pin);
	}
	else if ( reg_address == 1 )
	{
		pin = pin - 32 ;
		SET_BIT(NVIC->EN[1] , pin);
	}
	else if ( reg_address == 2 )
	{
		pin = pin - 64 ;
		SET_BIT(NVIC->EN[2] , pin);
	}
	else if ( reg_address == 3 )
	{
		pin = pin - 96 ;
		SET_BIT(NVIC->EN[3] , pin);
	}
	else if ( reg_address == 4 )
	{
		pin = pin - 128 ;
		SET_BIT(NVIC->EN[4] , pin);
	}

}

void NVIC_voidDisableInterrupt ( NVIC_IRQ_Type IRQ_type )
{
	u8 reg_address = IRQ_type / 32 ;
	u8 pin = IRQ_type % 32 ;

	if ( reg_address == 0)
	{
		NVIC->DIS[0] = 1 << pin ;
	}
	else if ( reg_address == 1 )
	{
		pin = pin - 32 ;
		NVIC->DIS[1] = 1 << pin ;
	}
	else if ( reg_address == 2 )
	{
		pin = pin - 64 ;
		NVIC->DIS[2] = 1 << pin ;
	}
	else if ( reg_address == 3 )
	{
		pin = pin - 96 ;
		NVIC->DIS[3] = 1 << pin ;
	}
	else if ( reg_address == 4 )
	{
		pin = pin - 128 ;
		NVIC->DIS[4] = 1 << pin ;
	}

}



void NVIC_voidSetPendingFlag ( NVIC_IRQ_Type IRQ_type )
{
	u8 reg_address = IRQ_type / 32 ;
	u8 pin = IRQ_type % 32 ;

	if ( reg_address == 0)
	{
		SET_BIT(NVIC->PEND[0] , pin);
	}
	else if ( reg_address == 1 )
	{
		pin = pin - 32 ;
		SET_BIT(NVIC->PEND[1] , pin);
	}
	else if ( reg_address == 2 )
	{
		pin = pin - 64 ;
		SET_BIT(NVIC->PEND[2] , pin);
	}
	else if ( reg_address == 3 )
	{
		pin = pin - 96 ;
		SET_BIT(NVIC->PEND[3] , pin);
	}
	else if ( reg_address == 4 )
	{
		pin = pin - 128 ;
		SET_BIT(NVIC->PEND[4] , pin);
	}

}



void NVIC_voidClearPendingFlag ( NVIC_IRQ_Type IRQ_type )
{
	u8 reg_address = IRQ_type / 32 ;
	u8 pin = IRQ_type % 32 ;

	if ( reg_address == 0)
	{
		SET_BIT(NVIC->UNPEND[0] , pin);
	}
	else if ( reg_address == 1 )
	{
		pin = pin - 32 ;
		SET_BIT(NVIC->UNPEND[1] , pin);
	}
	else if ( reg_address == 2 )
	{
		pin = pin - 64 ;
		SET_BIT(NVIC->UNPEND[2] , pin);
	}
	else if ( reg_address == 3 )
	{
		pin = pin - 96 ;
		SET_BIT(NVIC->UNPEND[3] , pin);
	}
	else if ( reg_address == 4 )
	{
		pin = pin - 128 ;
		SET_BIT(NVIC->UNPEND[4] , pin);
	}
}



void NVIC_voidTriggerInterrupt (  NVIC_IRQ_Type IRQ_type )
{
	NVIC_SWTRIG = 0 ;
	NVIC_SWTRIG = IRQ_type ;
}



NVIC_IRQ_State NVIC_u8GetActiveFlag ( NVIC_IRQ_Type IRQ_type )
{
	u8 reg_address = IRQ_type / 32 ;
	u8 pin = IRQ_type % 32 ;
	NVIC_IRQ_State state = DISABLED ;

	if ( reg_address == 0)
	{
		state = GET_BIT(NVIC->ACTIVE[0] , pin);
	}
	else if ( reg_address == 1 )
	{
		pin = pin - 32 ;
		state = GET_BIT(NVIC->ACTIVE[1] , pin);
	}
	else if ( reg_address == 2 )
	{
		pin = pin - 64 ;
		state = GET_BIT(NVIC->ACTIVE[2] , pin);
	}
	else if ( reg_address == 3 )
	{
		pin = pin - 96 ;
		state = GET_BIT(NVIC->ACTIVE[3] , pin);
	}
	else if ( reg_address == 4 )
	{
		pin = pin - 128 ;
		state = GET_BIT(NVIC->ACTIVE[4] , pin);
	}
	return state ;
}




static void change_irq_state ( NVIC_IRQ_Type IRQ_type , NVIC_IRQ_State state )
{
	if ( state == ENABLED )
	{
		NVIC_voidEnableInterrupt ( IRQ_type );
	}
	else if ( state == DISABLED )
	{
		NVIC_voidDisableInterrupt ( IRQ_type );
	}
}



static void SCB_void_setNVICpriority ( void)
{
	SCB_APINT = ( 0x05FA0000 | (SET_PRIORITY<<8)) ;
}


void NVIC_voidInit( NVIC_Config_Type * config_ptr )
{
	u8 index = 0 ;
	SCB_void_setNVICpriority ();
	
	for ( index =0 ; index<TOTAL_NUM_OF_IRQS ; index++)
	{
		change_irq_state(config_ptr[index].irq_num , config_ptr[index].state );
		
		NVIC->PRI[config_ptr[index].irq_num] = (config_ptr[index].priority)<<5 ;
	}

}


