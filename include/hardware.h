/**
 * hardware.h
 *
 *  @date Created at:	05/12/2023, 13:54:36
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

/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include "std.h"

#include <driver/uart.h>
#include <driver/gpio.h>



#ifndef hardware_H_
#define hardware_H_

/* macro -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/


/**
 *  ########################################################################################################################################################
 *  # uart																		   #
 *  ########################################################################################################################################################
 * 
 */

#define HARDWARE_uartMainIndex		( UART_NUM_1		)
#define HARDWARE_uartMainBaudrate	( 115200		)
#define HARDWARE_uartMainTXD		( 1			)
#define HARDWARE_uartMainRXD		( 2			)

#define HARDWARE_uartSecIndex		( UART_NUM_1		)
#define HARDWARE_uartSecBaudrate	( 115200		)
#define HARDWARE_uartSecTXD		( 42			)
#define HARDWARE_uartSecRXD		( 41			)

#define HARDWARE_uartBufferSize		( 255			)
#define HARDWARE_uartQueueSize		( 50			)


/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

#endif /* hardware_H_ */
