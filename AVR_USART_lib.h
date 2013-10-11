/*
 * AVR_USART_lib.h
 *
 *  Created on: Oct 11, 2013
 *      Author: lhotse
 */




#ifndef AVR_USART_LIB_H
#define AVR_USART_LIB_H



#include <avr/io.h>



void USART_Init( uint16_t ui16UBRR ) ;

void USART_Transmit( unsigned char data ) ;


#endif AVR_USART_LIB_H
