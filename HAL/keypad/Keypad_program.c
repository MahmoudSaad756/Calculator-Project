/*
 * Keypad_program.c
 *
 *  Created on: Oct 24, 2022
 *      Author: Mahmoud
 */

#include <util/delay.h>
#include "../../services/STD_TYPES.h"
#include "../../services/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "Keypad_interface.h"
#include "Keypad_config.h"
#include "Keypad_private.h"



void KEYPAD_voidInit    (void)
{
	DIO_voidSetPinDirection( KEYPAD_PORT , ROW1 , Output);
	DIO_voidSetPinValue    ( KEYPAD_PORT , ROW1 , High  );

	DIO_voidSetPinDirection( KEYPAD_PORT , ROW2 , Output);
	DIO_voidSetPinValue    ( KEYPAD_PORT , ROW2 , High  );

	DIO_voidSetPinDirection( KEYPAD_PORT , ROW3 , Output);
	DIO_voidSetPinValue    ( KEYPAD_PORT , ROW3 , High  );

	DIO_voidSetPinDirection( KEYPAD_PORT , ROW4 , Output);
	DIO_voidSetPinValue    ( KEYPAD_PORT , ROW4 , High  );

	DIO_voidSetPinDirection( KEYPAD_PORT , COL1 , Input_Pullup);
	DIO_voidSetPinDirection( KEYPAD_PORT , COL2 , Input_Pullup);
	DIO_voidSetPinDirection( KEYPAD_PORT , COL3 , Input_Pullup);
	DIO_voidSetPinDirection( KEYPAD_PORT , COL4 , Input_Pullup);
}


u8   KEYPAD_u8ReadButton(void)
{
	while(1)
	{
		//////////////// ROW 1  /////////////


		DIO_voidSetPinValue    ( KEYPAD_PORT , ROW1 , Low  );
		if( DIO_u8GetPinValue( KEYPAD_PORT , COL1) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL1) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num1 ;
		}
		else if( DIO_u8GetPinValue( KEYPAD_PORT , COL2) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL2) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num2 ;
		}
		else if( DIO_u8GetPinValue( KEYPAD_PORT , COL3) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL3) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num3 ;
		}
		else if( DIO_u8GetPinValue( KEYPAD_PORT , COL4) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL4) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num4 ;
		}
		DIO_voidSetPinValue    ( KEYPAD_PORT , ROW1 , High  );

		//////////////// ROW 2  /////////////

		DIO_voidSetPinValue    ( KEYPAD_PORT , ROW2 , Low  );
		if( DIO_u8GetPinValue( KEYPAD_PORT , COL1) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL1) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num5 ;
		}
		else if( DIO_u8GetPinValue( KEYPAD_PORT , COL2) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL2) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num6 ;
		}
		else if( DIO_u8GetPinValue( KEYPAD_PORT , COL3) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL3) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num7 ;
		}
		else if( DIO_u8GetPinValue( KEYPAD_PORT , COL4) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL4) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num8 ;
		}
		DIO_voidSetPinValue    ( KEYPAD_PORT , ROW2 , High  );

		//////////////// ROW 3  /////////////

		DIO_voidSetPinValue    ( KEYPAD_PORT , ROW3 , Low  );
		if( DIO_u8GetPinValue( KEYPAD_PORT , COL1) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL1) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num9 ;
		}
		else if( DIO_u8GetPinValue( KEYPAD_PORT , COL2) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL2) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num10 ;
		}
		else if( DIO_u8GetPinValue( KEYPAD_PORT , COL3) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL3) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num11 ;
		}
		else if( DIO_u8GetPinValue( KEYPAD_PORT , COL4) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL4) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num12 ;
		}
		DIO_voidSetPinValue    ( KEYPAD_PORT , ROW3 , High  );


		//////////////// ROW 4  /////////////

		DIO_voidSetPinValue    ( KEYPAD_PORT , ROW4 , Low  );
		if( DIO_u8GetPinValue( KEYPAD_PORT , COL1) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL1) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num13 ;
		}
		else if( DIO_u8GetPinValue( KEYPAD_PORT , COL2) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL2) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num14 ;
		}
		else if( DIO_u8GetPinValue( KEYPAD_PORT , COL3) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL3) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num15 ;
		}
		else if( DIO_u8GetPinValue( KEYPAD_PORT , COL4) == IS_Pressed )
		{
			while(DIO_u8GetPinValue( KEYPAD_PORT , COL4) == IS_Pressed) ;
			_delay_ms(10);
			return Btn_Num16 ;
		}
		DIO_voidSetPinValue    ( KEYPAD_PORT , ROW4 , High  );


	}

}



