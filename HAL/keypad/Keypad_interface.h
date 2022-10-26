/*
 * Keypad_interface.h
 *
 *  Created on: Oct 24, 2022
 *      Author: Mahmoud
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define Btn_Num1    1
#define Btn_Num2    2
#define Btn_Num3    3
#define Btn_Num4    4
#define Btn_Num5    5
#define Btn_Num6    6
#define Btn_Num7    7
#define Btn_Num8    8
#define Btn_Num9    9
#define Btn_Num10   10
#define Btn_Num11   11
#define Btn_Num12   12
#define Btn_Num13   13
#define Btn_Num14   14
#define Btn_Num15   15
#define Btn_Num16   16



#define IS_Pressed  0



void KEYPAD_voidInit    (void);
u8   KEYPAD_u8ReadButton(void);

#endif /* KEYPAD_INTERFACE_H_ */
