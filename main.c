/*
 * main.c
 *
 *  Created on: Oct 24, 2022
 *      Author: Mahmoud
 */

#include <util/delay.h>

#include "services/STD_TYPES.h"
#include "services/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"

#include "HAL/LCD/LCD_interface.h"
#include "HAL/keypad/Keypad_interface.h"

#include "services/CalcLib/Calc_interface.h"

u8 EquaBtn[16]={'7','8','9','/','4','5','6','*','1','2','3','-','%','0','=','+'};

int main(void)
{

	KEYPAD_voidInit();
	LCD_voidInit();
	u8 Expression[16]={0};
	u8 Iterator=0;
	u8 OperationDone=0;

	while(1)
	{

		u8 Num = KEYPAD_u8ReadButton();

		if(OperationDone == 1)
		{
			LCD_voidClear();
			Iterator = 0;
			OperationDone = 0;
			while(Expression[Iterator])
			{
				Expression[Iterator] = 0;
				Iterator++;
			}
			Iterator = 0;
		}

		if(EquaBtn[Num-1] == '=')
		{
			u8 * Parssed = ParseExpression(Expression);
			LCD_voidgoto(2,1);
			u8 * PostFix = ChangeToPostFix(Parssed);

			u16  Answer  = CalcExpression(PostFix);

			LCD_voidSendNumber(Answer);

			OperationDone=1;
			continue;
		}

		Expression[Iterator++]=EquaBtn[Num-1];
		LCD_voidSendChar(EquaBtn[Num-1]);
	}

	return 0;
}
