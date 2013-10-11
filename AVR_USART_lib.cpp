/*
 * AVR_USART_lib.cpp
 *
 *  Created on: Oct 11, 2013
 *      Author: lhotse
 */



#include "AVR_USART_lib.h"



void USART_Init( uint16_t ui16UBRR )
{
	/* Set baud rate */
	UBRR0H = (uint8_t) (ui16UBRR>>8) ;
	UBRR0L = (uint8_t) ui16UBRR ;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0) | (1<<TXEN0) ;
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS0) | (3<<UCSZ00) ;
}



void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}
