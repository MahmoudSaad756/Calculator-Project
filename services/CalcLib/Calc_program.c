/*
 * Calc_program.c
 *
 *  Created on: Oct 26, 2022
 *      Author: Mahmoud
 */

#include "../STD_TYPES.h"
#include "Calc_interface.h"

u16 MAXSIZE = 20;
u16 top = -1;
u16 stack[20];


u16 isempty()
{

   if(top == -1)
      return 1;
   else
      return 0;
}

u16 isfull()
{

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

u16 peek()
{
   return stack[top];
}

u16 pop()
{
	u16 data;

   if(!isempty())
   {
      data = stack[top];
      top = top - 1;
      return data;
   }
   else
	   return 0;

}

void push (u16 data)
{

   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
   }

}

u8 * ParseExpression(u8* Str)
{
	u8 Iterator1=0;
	u8 Iterator2=0;
	u16 Cur_Num=0;
	static u8 Parssedstr[20];
	while( Iterator1 < 20 )
	{
		Parssedstr[Iterator1]=0;
		Iterator1++;
	}
	Iterator1=0;

	while(Str[Iterator1])
	{
		if( Str[Iterator1] == '*' || Str[Iterator1] == '/' || Str[Iterator1] == '+' || Str[Iterator1] == '-' )
		{
			Parssedstr[Iterator2++]=Cur_Num;
			Cur_Num=0;
			Parssedstr[Iterator2++]=Str[Iterator1];

		}
		else
		{
			Cur_Num*=10;
			Cur_Num+=Str[Iterator1]-'0';
		}
		Iterator1++;
	}

	if(Cur_Num != 0)
        Parssedstr[Iterator2++]=Cur_Num;

	return Parssedstr;
}

u8 OpretionPriority(u8 op)
{
	if(op == '+' || op == '-')
		return 1;
	if(op == '*' || op == '*')
		return 2;
	else return 3;
}

u8 * ChangeToPostFix(u8* Str)
{
	static u8 PFstr[20];
		u8 Iterator1=0;
		u8 Iterator2=0;

		while( Iterator1 < 20 )
		{
			PFstr[Iterator1]=0;
			Iterator1++;
		}
		Iterator1=0;

		while(Str[Iterator1])
		{
			if(Str[Iterator1] == '+' || Str[Iterator1] == '-' || Str[Iterator1] == '*' || Str[Iterator1] == '/')
			{

				while(!isempty() && OpretionPriority(Str[Iterator1]) <= OpretionPriority(peek()) )
				{
					PFstr[Iterator2++] =  pop();;

				}
				push(Str[Iterator1]);
			}
			else
			{
				PFstr[Iterator2++] =  Str[Iterator1];
			}
			Iterator1++;
		}

		while(!isempty())
		{
			PFstr[Iterator2++] = pop();
		}

	    return PFstr;

}

u16  CalcExpression(u8* Str)
{
	u8 Iterator=0;
	while(Str[Iterator])
	{
		if(Str[Iterator] == '+' || Str[Iterator] == '-' || Str[Iterator] == '*' || Str[Iterator] == '/')
		{
			u16 op1=pop();
			u16 op2=pop();
			switch(Str[Iterator])
			{
				case '+' :   push(op2 + op1); break ;
				case '-' :   push(op2 - op1); break ;
				case '*' :   push(op2 * op1); break ;
				case '/' :   push(op2 / op1); break ;
			}
		}

		else
		{
			push(Str[Iterator]);
		}

		Iterator++;
	}

	return pop();
}
