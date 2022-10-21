#include "Std_Types.h"
#include "BIT_Math.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_ppconfig.h"

 
void GPIO_voidInit ( Pin_Config_Type* config_ptr )
{
	u8 index = 0 ;
	u8 PIN ;

	SET_BIT(RCGCGPIO , 0 ) ;
	SET_BIT(RCGCGPIO , 1 ) ;
	SET_BIT(RCGCGPIO , 2 ) ;
	SET_BIT(RCGCGPIO , 3 ) ;
	SET_BIT(RCGCGPIO , 4 ) ;
	SET_BIT(RCGCGPIO , 5 ) ;
	for ( index = 0 ; index < TOTAL_PINS_NUM ; index++ )
	{
		
		PIN = config_ptr[index].pin  ;
		switch (config_ptr[index].port)
		{
		//--------------------------------------PORT A ---------------------------------------------------------------

		case PORTA :
			//Unlocking port A
			REG(GPIOA+GPIOLOCK) = GPIOLOCK_KEY ;
			REG(GPIOA+GPIOCR) = 0xff;

			//setting pin direction
			CLR_BIT(REG(GPIOA+GPIODIR),PIN);
			REG(GPIOA+GPIODIR) |= (config_ptr[index].direction)<<PIN ;

			//enable digital
			SET_BIT(REG(GPIOA+GPIODEN),PIN);

			//setting ampere
			switch (config_ptr[index].current)
			{
			case MA_AMPERE_2 :
				SET_BIT(REG(GPIOA+GPIODR2R),PIN);
				break ;

			case MA_AMPERE_4 :
				SET_BIT(REG(GPIOA+GPIODR4R),PIN);
				break ;

			case MA_AMPERE_8 :
				SET_BIT(REG(GPIOA+GPIODR8R),PIN);
				break ;
			}

			//setting Pull attach type
			switch (config_ptr[index].attach)
			{
			case OPEN_DRAIN :
				SET_BIT(REG(GPIOA+GPIOODR),PIN);
				CLR_BIT(REG(GPIOA+GPIOPUR),PIN);
				CLR_BIT(REG(GPIOA+GPIOPDR),PIN);
				break ;

			case PULLDOWN :
				CLR_BIT(REG(GPIOA+GPIOODR),PIN);
				SET_BIT(REG(GPIOA+GPIOPDR),PIN);
				break ;

			case PULLUP :
				CLR_BIT(REG(GPIOA+GPIOODR),PIN);
				SET_BIT(REG(GPIOA+GPIOPUR),PIN);
				break ;
			}

			//setting initial level value
			CLR_BIT(REG(GPIOA+GPIODATA),PIN) ;
			REG(GPIOA+GPIODATA) |= ((config_ptr[index].level_value)<<PIN) ;


			// setting mode
			switch (PIN)
			{
			case PIN0 :
				if ( config_ptr[index].mode == UART )
				{
					SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
					REG(GPIOA+GPIOPCTL) |= 0x1 ;
				}
				else if ( config_ptr[index].mode == CAN )
				{
					SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
					REG(PORTA+GPIOPCTL) |= 0x8 ;
				}
				break ;

			case PIN1 :
				if ( config_ptr[index].mode == UART )
				{
					SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
					REG(GPIOA+GPIOPCTL) |= 0x1 << 4 ;
				}
				else if ( config_ptr[index].mode == CAN )
				{
					SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
					REG(GPIOA+GPIOPCTL) |= 0x8 << 4;
				}
				break ;

			case PIN2 :
				if ( config_ptr[index].mode == SSI )
				{
					SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
					REG(GPIOA+GPIOPCTL) |= 0x2 << 8;
				}
				break ;

			case PIN3 :
				if ( config_ptr[index].mode == SSI )
				{
					SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
					REG(GPIOA+GPIOPCTL) |= 0x2 << 12;
				}
				break ;

			case PIN4 :
				if ( config_ptr[index].mode == SSI )
				{
					SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
					REG(GPIOA+GPIOPCTL) |= 0x2 << 16 ;
				}
				break ;

			case PIN5 :
				if ( config_ptr[index].mode == SSI )
				{
					SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
					REG(GPIOA+GPIOPCTL) |= 0x2 << 20 ;
				}
				break ;

			case PIN6 :
				if ( config_ptr[index].mode == I2C )
				{
					SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
					REG(GPIOA+GPIOPCTL) |= 0x3 << 24 ;
				}
				else if ( config_ptr[index].mode == PWM  )
				{
					SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
					REG(GPIOA+GPIOPCTL) |= 0x5 << 24 ;
				}
				break ;

			case PIN7 :
				if ( config_ptr[index].mode == I2C )
				{
					SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
					REG(GPIOA+GPIOPCTL) |= 0x3 << 28 ;
				}
				else if ( config_ptr[index].mode == PWM  )
				{
					SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
					REG(GPIOA+GPIOPCTL) |= 0x5 << 28 ;
				}
				break ;
			}
			break ;

			//-------------------------------------------- GPIO B --------------------------------------------------------

			case PORTB :
				//Unlocking GPIO B
				REG(GPIOB+GPIOLOCK) = GPIOLOCK_KEY ;
				REG(GPIOB+GPIOCR) = 0xff;

				//setting pin direction
				CLR_BIT(REG(GPIOB+GPIODIR),PIN);
				REG(GPIOB+GPIODIR) |= (config_ptr[index].direction)<<PIN ;

				//enable digital
				SET_BIT(REG(GPIOB+GPIODEN),PIN);

				//setting ampere
				switch (config_ptr[index].current)
				{
				case MA_AMPERE_2 :
					SET_BIT(REG(GPIOB+GPIODR2R),PIN);
					break ;

				case MA_AMPERE_4 :
					SET_BIT(REG(GPIOB+GPIODR4R),PIN);
					break ;

				case MA_AMPERE_8 :
					SET_BIT(REG(GPIOB+GPIODR8R),PIN);
					break ;
				}

				//setting Pull attach type
				switch (config_ptr[index].attach)
				{
				case OPEN_DRAIN :
					SET_BIT(REG(GPIOB+GPIOODR),PIN);
					CLR_BIT(REG(GPIOB+GPIOPUR),PIN);
					CLR_BIT(REG(GPIOB+GPIOPDR),PIN);
					break ;

				case PULLDOWN :
					CLR_BIT(REG(GPIOB+GPIOODR),PIN);
					SET_BIT(REG(GPIOB+GPIOPDR),PIN);
					break ;

				case PULLUP :
					CLR_BIT(REG(GPIOB+GPIOODR),PIN);
					SET_BIT(REG(GPIOB+GPIOPUR),PIN);
					break ;
				}

				//setting initial level value
				CLR_BIT(REG(GPIOB+GPIODATA),PIN) ;
				REG(GPIOB+GPIODATA) |= ((config_ptr[index].level_value)<<PIN) ;


				// setting mode
				switch (PIN)
				{
				case PIN0 :
					if ( config_ptr[index].mode == UART )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x1 ;
					}
					else if ( config_ptr[index].mode == TIMER )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x7 ;
					}
					break ;

				case PIN1 :
					if ( config_ptr[index].mode == UART )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x1 << 4 ;
					}
					else if ( config_ptr[index].mode == TIMER )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x7 << 4;
					}
					break ;

				case PIN2 :
					if ( config_ptr[index].mode == I2C )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x3 << 8;
					}
					else if ( config_ptr[index].mode == TIMER )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x7 << 8;
					}
					break ;

				case PIN3 :
					if ( config_ptr[index].mode == I2C )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x3 << 12;
					}
					else if ( config_ptr[index].mode == TIMER )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x7 << 12;
					}
					break ;

				case PIN4 :
					if ( config_ptr[index].mode == SSI )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x2 << 16 ;
					}
					else if ( config_ptr[index].mode == PWM )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x4 << 16 ;
					}
					else if ( config_ptr[index].mode == TIMER )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x7 << 16 ;
					}
					else if ( config_ptr[index].mode == CAN )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x8 << 16 ;
					}
					break ;

				case PIN5 :
					if ( config_ptr[index].mode == SSI )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x2 << 20 ;
					}
					else if ( config_ptr[index].mode == PWM )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x4 << 20 ;
					}
					else if ( config_ptr[index].mode == TIMER )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x7 << 20 ;
					}
					else if ( config_ptr[index].mode == CAN )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x8 << 20 ;
					}
					break ;

				case PIN6 :
					if ( config_ptr[index].mode == SSI )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x2 << 24 ;
					}
					else if ( config_ptr[index].mode == PWM )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x4 << 24 ;
					}
					else if ( config_ptr[index].mode == TIMER )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x7 << 24 ;
					}
					break ;

				case PIN7 :
					if ( config_ptr[index].mode == SSI )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x2 << 28 ;
					}
					else if ( config_ptr[index].mode == PWM )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x4 << 28 ;
					}
					else if ( config_ptr[index].mode == TIMER )
					{
						SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
						REG(GPIOB+GPIOPCTL) |= 0x7 << 28 ;
					}
					break ;
				}
				break ;

				//---------------------------------------------------GPIOC-------------------------------------------------------

				case PORTC :
					//Unlocking GPIO C
					REG(GPIOC+GPIOLOCK) = GPIOLOCK_KEY ;
					REG(GPIOC+GPIOCR) = 0xff;

					//setting pin direction
					CLR_BIT(REG(GPIOC+GPIODIR),PIN);
					REG(GPIOC+GPIODIR) |= (config_ptr[index].direction)<<PIN ;

					//enable digital
					SET_BIT(REG(GPIOC+GPIODEN),PIN);

					//setting ampere
					switch (config_ptr[index].current)
					{
					case MA_AMPERE_2 :
						SET_BIT(REG(GPIOC+GPIODR2R),PIN);
						break ;

					case MA_AMPERE_4 :
						SET_BIT(REG(GPIOC+GPIODR4R),PIN);
						break ;

					case MA_AMPERE_8 :
						SET_BIT(REG(GPIOC+GPIODR8R),PIN);
						break ;
					}

					//setting Pull attach type
					switch (config_ptr[index].attach)
					{
					case OPEN_DRAIN :
						SET_BIT(REG(GPIOC+GPIOODR),PIN);
						CLR_BIT(REG(GPIOC+GPIOPUR),PIN);
						CLR_BIT(REG(GPIOC+GPIOPDR),PIN);
						break ;

					case PULLDOWN :
						CLR_BIT(REG(GPIOC+GPIOODR),PIN);
						SET_BIT(REG(GPIOC+GPIOPDR),PIN);
						break ;

					case PULLUP :
						CLR_BIT(REG(GPIOC+GPIOODR),PIN);
						SET_BIT(REG(GPIOC+GPIOPUR),PIN);
						break ;
					}

					//setting initial level value
					CLR_BIT(REG(GPIOC+GPIODATA),PIN) ;
					REG(GPIOC+GPIODATA) |= ((config_ptr[index].level_value)<<PIN) ;


					// setting mode
					switch (PIN)
					{
					case PIN0 :
						if ( config_ptr[index].mode == TIMER )
						{
							SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
							REG(GPIOC+GPIOPCTL) |= 0x7 ;
						}
						break ;

					case PIN1 :
						if ( config_ptr[index].mode == TIMER )
						{
							SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
							REG(GPIOC+GPIOPCTL) |= 0x7 << 4 ;
						}
						break ;

					case PIN2 :
						if ( config_ptr[index].mode == TIMER )
						{
							SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
							REG(GPIOC+GPIOPCTL) |= 0x7 << 8;
						}
						break ;

					case PIN3 :
						if ( config_ptr[index].mode == TIMER )
						{
							SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
							REG(GPIOC+GPIOPCTL) |= 0x7 << 12;
						}
						break ;

					case PIN4 :
						if ( config_ptr[index].mode == UART )
						{
							SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
							REG(GPIOC+GPIOPCTL) |= 0x1 << 16 ;
						}
						else if ( config_ptr[index].mode == PWM )
						{
							SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
							REG(GPIOC+GPIOPCTL) |= 0x4 << 16 ;
						}
						else if (config_ptr[index].mode == TIMER )
						{
							SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
							REG(GPIOC+GPIOPCTL) |= 0x7 << 16 ;
						}
						break ;

					case PIN5 :
						if ( config_ptr[index].mode == UART )
						{
							SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
							REG(GPIOC+GPIOPCTL) |= 0x1 << 20 ;
						}
						else if ( config_ptr[index].mode == PWM )
						{
							SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
							REG(GPIOC+GPIOPCTL) |= 0x4 << 20 ;
						}
						else if (config_ptr[index].mode == TIMER )
						{
							SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
							REG(GPIOC+GPIOPCTL) |= 0x7 << 20 ;
						}
						break ;

					case PIN6 :
						if ( config_ptr[index].mode == UART )
						{
							SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
							REG(GPIOC+GPIOPCTL) |= 0x1 << 24 ;
						}
						else if (config_ptr[index].mode == TIMER )
						{
							SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
							REG(GPIOC+GPIOPCTL) |= 0x7 << 24 ;
						}
						break ;

					case PIN7 :
						if ( config_ptr[index].mode == UART )
						{
							SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
							REG(GPIOC+GPIOPCTL) |= 0x1 << 28 ;
						}
						else if ( config_ptr[index].mode == TIMER  )
						{
							SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
							REG(GPIOC+GPIOPCTL) |= 0x7 << 28 ;
						}
						break ;
					}
					break ;

					//-------------------------------------------GPIO D-----------------------------------------------

					case PORTD :
						//Unlocking GPIO D
						REG(GPIOD+GPIOLOCK) = GPIOLOCK_KEY ;
						REG(GPIOD+GPIOCR) = 0xff;

						//setting pin direction
						CLR_BIT(REG(GPIOD+GPIODIR),PIN);
						REG(GPIOD+GPIODIR) |= (config_ptr[index].direction)<<PIN ;

						//enable digital
						SET_BIT(REG(GPIOD+GPIODEN),PIN);

						//setting ampere
						switch (config_ptr[index].current)
						{
						case MA_AMPERE_2 :
							SET_BIT(REG(GPIOD+GPIODR2R),PIN);
							break ;

						case MA_AMPERE_4 :
							SET_BIT(REG(GPIOD+GPIODR4R),PIN);
							break ;

						case MA_AMPERE_8 :
							SET_BIT(REG(GPIOD+GPIODR8R),PIN);
							break ;
						}

						//setting Pull attach type
						switch (config_ptr[index].attach)
						{
						case OPEN_DRAIN :
							SET_BIT(REG(GPIOD+GPIOODR),PIN);
							CLR_BIT(REG(GPIOD+GPIOPUR),PIN);
							CLR_BIT(REG(GPIOD+GPIOPDR),PIN);
							break ;

						case PULLDOWN :
							CLR_BIT(REG(GPIOD+GPIOODR),PIN);
							SET_BIT(REG(GPIOD+GPIOPDR),PIN);
							break ;

						case PULLUP :
							CLR_BIT(REG(GPIOD+GPIOODR),PIN);
							SET_BIT(REG(GPIOD+GPIOPUR),PIN);
							break ;
						}

						//setting initial level value
						CLR_BIT(REG(GPIOD+GPIODATA),PIN) ;
						REG(GPIOD+GPIODATA) |=  ((config_ptr[index].level_value)<<PIN) ;


						// setting mode
						switch (PIN)
						{
						case PIN0 :
							if ( config_ptr[index].mode == SSI )
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x1 ;
							}
							else if ( config_ptr[index].mode == I2C)
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x3 ;
							}
							else if ( config_ptr[index].mode == PWM)
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x4 ;
							}
							else if ( config_ptr[index].mode == TIMER)
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x7 ;
							}
							break ;

						case PIN1 :
							if ( config_ptr[index].mode == SSI )
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x1 <<4 ;
							}
							else if ( config_ptr[index].mode == I2C)
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x3 << 4 ;
							}
							else if ( config_ptr[index].mode == PWM)
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x4 << 4 ;
							}
							else if ( config_ptr[index].mode == TIMER)
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x7 << 4 ;
							}
							break ;

						case PIN2 :
							if ( config_ptr[index].mode == SSI )
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x1 <<8 ;
							}
							else if ( config_ptr[index].mode == PWM)
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x4 << 8 ;
							}
							else if ( config_ptr[index].mode == TIMER)
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x7 << 8 ;
							}
							break ;

						case PIN3 :
							if ( config_ptr[index].mode == SSI )
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x1 <<12 ;
							}
							else if ( config_ptr[index].mode == TIMER)
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x7 << 12 ;
							}
							break ;

						case PIN4 :
							if ( config_ptr[index].mode == UART )
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x1 << 16 ;
							}
							else if (config_ptr[index].mode == TIMER )
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x7 << 16 ;
							}
							break ;

						case PIN5 :
							if ( config_ptr[index].mode == UART )
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x1 << 20 ;
							}
							else if (config_ptr[index].mode == TIMER )
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x7 << 20 ;
							}
							break ;

						case PIN6 :
							if ( config_ptr[index].mode == UART )
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x1 << 24 ;
							}
							else if (config_ptr[index].mode == TIMER )
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x7 << 24 ;
							}
							break ;

						case PIN7 :
							if ( config_ptr[index].mode == UART )
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x1 << 28 ;
							}
							else if ( config_ptr[index].mode == TIMER  )
							{
								SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
								REG(GPIOD+GPIOPCTL) |= 0x7 << 28 ;
							}
							break ;
						}
						break ;

						//------------------------------------------------GPIO E ------------------------------------------------

						case PORTE :
							//Unlocking GPIO E
							REG(GPIOE+GPIOLOCK) = GPIOLOCK_KEY ;
							REG(GPIOE+GPIOCR) = 0xff;

							//setting pin direction
							CLR_BIT(REG(GPIOE+GPIODIR),PIN);
							REG(GPIOE+GPIODIR) |= (config_ptr[index].direction)<<PIN ;

							//enable digital
							SET_BIT(REG(GPIOE+GPIODEN),PIN);

							//setting ampere
							switch (config_ptr[index].current)
							{
							case MA_AMPERE_2 :
								SET_BIT(REG(GPIOE+GPIODR2R),PIN);
								break ;

							case MA_AMPERE_4 :
								SET_BIT(REG(GPIOE+GPIODR4R),PIN);
								break ;

							case MA_AMPERE_8 :
								SET_BIT(REG(GPIOE+GPIODR8R),PIN);
								break ;
							}

							//setting Pull attach type
							switch (config_ptr[index].attach)
							{
							case OPEN_DRAIN :
								SET_BIT(REG(GPIOE+GPIOODR),PIN);
								CLR_BIT(REG(GPIOE+GPIOPUR),PIN);
								CLR_BIT(REG(GPIOE+GPIOPDR),PIN);
								break ;

							case PULLDOWN :
								CLR_BIT(REG(GPIOE+GPIOODR),PIN);
								SET_BIT(REG(GPIOE+GPIOPDR),PIN);
								break ;

							case PULLUP :
								CLR_BIT(REG(GPIOE+GPIOODR),PIN);
								SET_BIT(REG(GPIOE+GPIOPUR),PIN);
								break ;
							}

							//setting initial level value
							CLR_BIT(REG(GPIOE+GPIODATA),PIN) ;
							REG(GPIOE+GPIODATA) |= ((config_ptr[index].level_value)<<PIN) ;


							// setting mode
							switch (PIN)
							{
							case PIN0 :
								if ( config_ptr[index].mode == UART )
								{
									SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
									REG(GPIOE+GPIOPCTL) |= 0x1 ;
								}
								break ;

							case PIN1 :
								if ( config_ptr[index].mode == UART )
								{
									SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
									REG(GPIOE+GPIOPCTL) |= 0x1 <<4 ;
								}
								break ;

							case PIN2 :
								break ;

							case PIN3 :
								break ;

							case PIN4 :
								if ( config_ptr[index].mode == UART )
								{
									SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
									REG(GPIOE+GPIOPCTL) |= 0x1 << 16 ;
								}
								else if (config_ptr[index].mode == I2C )
								{
									SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
									REG(GPIOE+GPIOPCTL) |= 0x3 << 16 ;
								}
								else if (config_ptr[index].mode == PWM )
								{
									SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
									REG(GPIOE+GPIOPCTL) |= 0x4 << 16 ;
								}
								else if (config_ptr[index].mode == CAN )
								{
									SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
									REG(GPIOE+GPIOPCTL) |= 0x8 << 16 ;
								}
								break ;

							case PIN5 :
								if ( config_ptr[index].mode == UART )
								{
									SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
									REG(GPIOE+GPIOPCTL) |= 0x1 << 20 ;
								}
								else if (config_ptr[index].mode == I2C )
								{
									SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
									REG(GPIOE+GPIOPCTL) |= 0x3 << 20 ;
								}
								else if (config_ptr[index].mode == PWM )
								{
									SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
									REG(GPIOE+GPIOPCTL) |= 0x4 << 20 ;
								}
								else if (config_ptr[index].mode == CAN )
								{
									SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
									REG(GPIOE+GPIOPCTL) |= 0x8 << 20 ;
								}
								break ;

							}
							break ;

							//----------------------------------------GPIO F ---------------------------------------------------

							case PORTF :
								//Unlocking GPIO E
								REG(GPIOF+GPIOLOCK) = GPIOLOCK_KEY ;
								REG(GPIOF+GPIOCR) = 0xff;

								//setting pin direction
								CLR_BIT(REG(GPIOF+GPIODIR),PIN);
								REG(GPIOF+GPIODIR) |= (config_ptr[index].direction)<<PIN ;

								//enable digital
								SET_BIT(REG(GPIOF+GPIODEN),PIN);

								//setting ampere
								switch (config_ptr[index].current)
								{
								case MA_AMPERE_2 :
									SET_BIT(REG(GPIOF+GPIODR2R),PIN);
									break ;

								case MA_AMPERE_4 :
									SET_BIT(REG(GPIOF+GPIODR4R),PIN);
									break ;

								case MA_AMPERE_8 :
									SET_BIT(REG(GPIOF+GPIODR8R),PIN);
									break ;
								}

								//setting Pull attach type
								switch (config_ptr[index].attach)
								{
								case OPEN_DRAIN :
									SET_BIT(REG(GPIOF+GPIOODR),PIN);
									CLR_BIT(REG(GPIOF+GPIOPUR),PIN);
									CLR_BIT(REG(GPIOF+GPIOPDR),PIN);
									break ;

								case PULLDOWN :
									CLR_BIT(REG(GPIOF+GPIOODR),PIN);
									SET_BIT(REG(GPIOF+GPIOPDR),PIN);
									break ;

								case PULLUP :
									CLR_BIT(REG(GPIOF+GPIOODR),PIN);
									SET_BIT(REG(GPIOF+GPIOPUR),PIN);
									break ;
								}

								//setting initial level value
								CLR_BIT(REG(GPIOF+GPIODATA),PIN) ;
								REG(GPIOF+GPIODATA) |= ((config_ptr[index].level_value)<<PIN) ;


								// setting mode
								switch (PIN)
								{
								case PIN0 :
									if ( config_ptr[index].mode == UART )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x1 ;
									}
									else if ( config_ptr[index].mode == SSI )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x2 ;
									}
									else if ( config_ptr[index].mode == CAN )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x3 ;
									}
									else if ( config_ptr[index].mode == PWM )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x5 ;
									}
									else if ( config_ptr[index].mode == TIMER )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x7 ;
									}
									break ;

								case PIN1 :
									if ( config_ptr[index].mode == UART )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x1 << 4 ;
									}
									else if ( config_ptr[index].mode == SSI )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x2 << 4;
									}
									else if ( config_ptr[index].mode == PWM )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x5 << 4 ;
									}
									else if ( config_ptr[index].mode == TIMER )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x7 << 4;
									}
									break ;

								case PIN2 :
									if ( config_ptr[index].mode == SSI )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x2 << 8;
									}
									else if ( config_ptr[index].mode == PWM )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x5 << 8 ;
									}
									else if ( config_ptr[index].mode == TIMER )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x7 << 8;
									}
									break ;

								case PIN3 :
									if ( config_ptr[index].mode == SSI )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x2 << 16  ;
									}
									else if ( config_ptr[index].mode == CAN )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x3 << 16  ;
									}
									else if ( config_ptr[index].mode == PWM )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x5 << 16 ;
									}
									else if ( config_ptr[index].mode == TIMER )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x7 << 16 ;
									}
									break ;

								case PIN4 :
									if ( config_ptr[index].mode == PWM )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x5 << 20 ;
									}
									else if ( config_ptr[index].mode == TIMER )
									{
										SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
										REG(GPIOF+GPIOPCTL) |= 0x7 << 20 ;
									}
									break ;

								}
								break ;

		}
	}
}







Pin_Level_Type GPIO_u8ReadPin ( Port_Type port , Pin_Type pin )
{
	Pin_Level_Type res ;
	switch (port)
	{
		case PORTA :
			res = GET_BIT(REG(GPIOA+GPIODATA) , pin );
			break ;

		case PORTB :
			res = GET_BIT(REG(GPIOB+GPIODATA) , pin );
			break ;

		case PORTC :
			res = GET_BIT(REG(GPIOC+GPIODATA) , pin );
			break ;

		case PORTD :
			res = GET_BIT(REG(GPIOD+GPIODATA) , pin );
			break ;

		case PORTE :
			res = GET_BIT(REG(GPIOE+GPIODATA) , pin );
			break ;

		case PORTF :
			res = GET_BIT(REG(GPIOF+GPIODATA) , pin );
			break ;


	}

	return res ;
}



void GPIO_voidWritePin ( Port_Type port , Pin_Type pin , Pin_Level_Type level )
{
	if ( level == HIGH )
	{
		switch (port)
		{
		case PORTA :
			SET_BIT(REG(GPIOA+GPIODATA) , pin);
			break ;

		case PORTB :
			SET_BIT(REG(GPIOB+GPIODATA) , pin);
			break ;

		case PORTC :
			SET_BIT(REG(GPIOC+GPIODATA) , pin);
			break ;

		case PORTD :
			SET_BIT(REG(GPIOD+GPIODATA) , pin);
			break ;

		case PORTE :
			SET_BIT(REG(GPIOE+GPIODATA) , pin);
			break ;

		case PORTF :
			SET_BIT(REG(GPIOF+GPIODATA) , pin);
			break ;
		}
	}
	else if ( level == LOW )
	{
		switch (port)
		{
		case PORTA :
			CLR_BIT(REG(GPIOA+GPIODATA) , pin);
			break ;

		case PORTB :
			CLR_BIT(REG(GPIOB+GPIODATA) , pin);
			break ;

		case PORTC :
			CLR_BIT(REG(GPIOC+GPIODATA) , pin);
			break ;

		case PORTD :
			CLR_BIT(REG(GPIOD+GPIODATA) , pin);
			break ;

		case PORTE :
			CLR_BIT(REG(GPIOE+GPIODATA) , pin);
			break ;

		case PORTF :
			CLR_BIT(REG(GPIOF+GPIODATA) , pin);
			break ;
		}
	}

}



Port_Level_Type GPIO_u8ReadPort ( Port_Type port )
{
	Port_Level_Type  res ;

	switch ( port )
	{
	case PORTA :
		res = REG(GPIOA+ GPIODATA);
		break ;

	case PORTB :
		res = REG(GPIOB+ GPIODATA);
		break ;

	case PORTC :
		res = REG(GPIOC+ GPIODATA);
		break ;

	case PORTD :
		res = REG(GPIOD+ GPIODATA);
		break ;

	case PORTE :
		res = REG(GPIOE+ GPIODATA);
		break ;

	case PORTF :
		res = REG(GPIOF+ GPIODATA);
		break ;
	}

	return res ;
}



void GPIO_voidWritePort ( Port_Type port ,  Port_Level_Type level )
{
	switch ( port )
	{
	case PORTA :
		REG(GPIOA+GPIODATA) = level ;
		break ;

	case PORTB :
		REG(GPIOB+GPIODATA) = level ;
		break ;

	case PORTC :
		REG(GPIOC+GPIODATA) = level ;
		break ;

	case PORTD :
		REG(GPIOD+GPIODATA) = level ;
		break ;

	case PORTE :
		REG(GPIOE+GPIODATA) = level ;
		break ;

	case PORTF :
		REG(GPIOF+GPIODATA) = level ;
		break ;
	}

}



Pin_Level_Type GPIO_u8FlipPin ( Port_Type port , Pin_Type pin )
{	Pin_Level_Type res ;

	switch ( port )
	{
	case PORTA :
		TOGGLE_BIT(REG(GPIOA+GPIODATA) , pin );
		res = GET_BIT(REG(GPIOA+GPIODATA) , pin );
		break ;

	case PORTB :
		TOGGLE_BIT(REG(GPIOB+GPIODATA) , pin );
		res = GET_BIT(REG(GPIOB+GPIODATA) , pin );
		break ;

	case PORTC :
		TOGGLE_BIT(REG(GPIOC+GPIODATA) , pin );
		res = GET_BIT(REG(GPIOC+GPIODATA) , pin );
		break ;

	case PORTD :
		TOGGLE_BIT(REG(GPIOD+GPIODATA) , pin );
		res = GET_BIT(REG(GPIOD+GPIODATA) , pin );
		break ;

	case PORTE :
		TOGGLE_BIT(REG(GPIOE+GPIODATA) , pin );
		res = GET_BIT(REG(GPIOE+GPIODATA) , pin );
		break ;

	case PORTF :
		TOGGLE_BIT(REG(GPIOF+GPIODATA) , pin );
		res = GET_BIT(REG(GPIOF+GPIODATA) , pin );
		break ;
	}

	return res ;
}

