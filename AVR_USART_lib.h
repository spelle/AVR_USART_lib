/*
 * AVR_USART_lib.h
 *
 *  Created on: Oct 11, 2013
 *      Author: lhotse
 */



#ifndef AVR_USART_LIB_H
#define AVR_USART_LIB_H



#include <avr/io.h>

#include <stdio.h>


/*! \brief USART Initialization
 *  \details This function will initialize the USART using selected baudrate.
 *  		 User must pay attention to select one of the usually used Baud Rate (9600, 19200, 38400, 57600)
 *  		 Note that since an uint16 is used as argument, Baud rate cannot be more than 57600
 *  \param [in] uint16_t ui16BaudRate : Desired Baud Rate (16 bit) - up to 57600
 *  \return Nothing.
 */
void USART_Init( uint16_t ui16BaudRate ) ;



/*! \brief USART Transmit data
 *  \details Nothing Special. It just wait for the transmit buffer is empty before writing it again.
 *  \param [in] uint8_t ui8Data : Desired data char to transmit
 *  \param None.
 *  \return Nothing.
 */
void USART_Transmit( uint8_t ui8Data ) ;



int USART_putchar_printf( char var, FILE *stream ) ;



#endif /* AVR_USART_LIB_H */
