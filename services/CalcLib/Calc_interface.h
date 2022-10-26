/*
 * Calc_interface.h
 *
 *  Created on: Oct 26, 2022
 *      Author: Mahmoud
 */

#ifndef CALC_INTERFACE_H_
#define CALC_INTERFACE_H_




u16 isempty();
u16 isfull();
u16 peek();
u16 pop();
void push(u16 data);
u8 * ParseExpression(u8* Str);
u8 * ChangeToPostFix(u8* Str);
u16  CalcExpression(u8* Str);
u8 OpretionPriority(u8 op);


#endif /* CALC_INTERFACE_H_ */
