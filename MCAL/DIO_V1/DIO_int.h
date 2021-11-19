/*
 * DIO_int.h
 *
 *  Created on: Oct 17, 2021
 *      Author: LENOVO
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "../../LIB/STD_TYPES.h"


/* Port Defines */
#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PIN Directions */
#define INPUT  0
#define OUTPUT 1

/* PIN Value Options */
#define HIGH   1
#define LOW    0

/*PORT Value Options */
#define FULL_HIGH (u8)0b11111111
#define FULL_LOW  (u8)0b00000000

/* IO Pins */
void DIO_SetPinValue(u8 Port , u8 PinId, u8 PinVal);

u8 DIO_GetPinValue(u8 Port, u8 PinId);

void DIO_SetPinDirection (u8 Port, u8 PinId, u8 PinDir);

/* IO Ports */
void DIO_SetPortDirection (u8 Port, u8 PortDir);

void DIO_SetPortValue     (u8 Port, u8 PortVal);



#endif /* DIO_INT_H_ */
