/**
 * uart.h
 *
 *  @date Created at:	05/12/2023, 13:41:06
 *	@author:	Pedro Igor B. S.
 *	@email:		pibscontato@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * ########################################################
 * TODO: Licence
 * ########################################################
 *
 * TODO: documentation or resume or Abstract
 *
 */

/* Includes ---------------------------------------------------------------------------------------------------------------------------------------------*/
#include <std.h>


#ifndef uart_H_
#define uart_H_

/* macro ------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/

typedef struct {

	uart_port_t num;
	int baud_rate;
	int rx_io_num;
	int tx_io_num;

} Uart;


void uart_vSetup( const Uart *uart );
void uart_vSwapIo( const Uart * currentUart, const Uart *swapTo  );




#endif /* uart_H_ */
