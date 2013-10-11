/*
 * AVR_USART_lib.cpp
 *
 *  Created on: Oct 11, 2013
 *      Author: lhotse
 */



#include "AVR_USART_lib.h"



static FILE m_stdout = FDEV_SETUP_STREAM( USART_putchar_printf, NULL, _FDEV_SETUP_WRITE ) ;



void USART_Init( uint16_t ui16BaudRate )
{
	uint32_t ui32UBRR = F_CPU ;

	ui32UBRR >>= 4 ; // (=) to ui32UBRR /= 16 but more efficient
	ui32UBRR /= ui16BaudRate ;
	ui32UBRR -= 1 ;

	/* Set baud rate */
	UBRR0H = (uint8_t) ( (ui32UBRR>>8) & (0x000000FF) ) ;
	UBRR0L = (uint8_t) ( ui32UBRR & (0x000000FF) ) ;

	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0) | (1<<TXEN0) ;

	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS0) | (3<<UCSZ00) ;

	stdout = &m_stdout ;
}



void USART_Transmit( uint8_t ui8Data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = ui8Data ;
}



int USART_putchar_printf( char var, FILE *stream )
{
	USART_Transmit( (uint8_t) var ) ;

	return 0 ;
}
