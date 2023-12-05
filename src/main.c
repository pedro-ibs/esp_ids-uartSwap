/**
 * bbb.c
 *
 *  @date Created at:	01/12/2023, 10:34:16
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
#include <std.h>
#include <config.h>

#include <uart/uart.h>
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/

/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

void app_main ( void ){

	printf("Starting...\r\n");
	
	vTaskDelay( _1S );

	char message1[] = "alpacas";
	char message2[] = "ALPACAS";
	char new_line[] = "\r\n";

	const Uart uart1A = {
		.num		= HARDWARE_uartMainIndex,
		.baud_rate	= HARDWARE_uartMainBaudrate,
		.tx_io_num	= HARDWARE_uartMainTXD,
		.rx_io_num	= HARDWARE_uartMainRXD
	};

	const Uart uart1B = {
		.num		= HARDWARE_uartSecIndex,
		.baud_rate	= HARDWARE_uartSecBaudrate,
		.tx_io_num	= HARDWARE_uartSecTXD,
		.rx_io_num	= HARDWARE_uartSecRXD
	};

	uart_vSetup( &uart1A );

	char buffer[ HARDWARE_uartBufferSize ] = { 0x00 };
	int rec = 0;


	while ( true ){

		uart_vSwapIo( &uart1A, &uart1B  );
		rec = uart_read_bytes( uart1B.num, buffer, HARDWARE_uartBufferSize, 0 );
		printf(" uart1A -> uart1B [byres read rx] : %d%s", rec, new_line );
		if( rec > 0 ){
			uart_write_bytes( uart1B.num, ( const char* )buffer,	strlen( buffer ) );
		} else{
			uart_write_bytes( uart1B.num, ( const char* )message1,	strlen( message1 ) );
		}	
		uart_write_bytes( uart1B.num, ( const char* )new_line,	strlen( new_line ) );
		vTaskDelay( _1S );



		uart_vSwapIo( &uart1B, &uart1A  );
		rec = uart_read_bytes( uart1A.num, buffer, HARDWARE_uartBufferSize, 0 );
		printf(" uart1B -> uart1A [byres read rx] : %d%s", rec, new_line );
		if( rec > 0 ){
			uart_write_bytes( uart1A.num, ( const char* )buffer,	strlen( buffer ) );
		} else{
			uart_write_bytes( uart1A.num, ( const char* )message2,	strlen( message2 ) );
		}	
		uart_write_bytes( uart1A.num, ( const char* )new_line,	strlen( new_line ) );
		vTaskDelay( _1S );

	}
}





/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*--------------------------------------------------------------------- Local Functions ------------------------------------------------------------------*/
/*########################################################################################################################################################*/
