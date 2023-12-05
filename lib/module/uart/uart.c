/**
 * uart.c
 *
 *  @date Created at:	05/12/2023, 13:41:25
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
#include "uart.h"
#include <hardware.h>
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
static QueueHandle_t sxUartQueue[ UART_NUM_MAX ]	= { NULL };
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

void uart_vSetup( const Uart *uart ){
	
	uart_config_t uart_config = {
		.baud_rate		= uart->baud_rate,
		.data_bits		= UART_DATA_8_BITS,
		.parity			= UART_PARITY_DISABLE,
		.stop_bits		= UART_STOP_BITS_1,
		.flow_ctrl		= UART_HW_FLOWCTRL_DISABLE,
		.rx_flow_ctrl_thresh	= 122
	};
	
	ESP_ERROR_CHECK( uart_param_config( uart->num, &uart_config ) );
	ESP_ERROR_CHECK( uart_set_pin( uart->num, uart->tx_io_num, uart->rx_io_num, -1, -1 ) );
	ESP_ERROR_CHECK( uart_driver_install( uart->num, HARDWARE_uartBufferSize, HARDWARE_uartBufferSize, HARDWARE_uartQueueSize, &sxUartQueue[ ( int ) uart->num ], 0 ) ) ;
}



void uart_vSwapIo( const Uart * currentUart, const Uart *swapTo ){

	ESP_ERROR_CHECK( uart_set_pin( swapTo->num, swapTo->tx_io_num, swapTo->rx_io_num, -1, -1 ) );

	uart_flush(			currentUart->num				);
	uart_flush(			swapTo->num					);

	esp_rom_gpio_pad_select_gpio(	currentUart->rx_io_num				);
	gpio_set_direction(		currentUart->rx_io_num, GPIO_MODE_DEF_DISABLE	);

	esp_rom_gpio_pad_select_gpio(	currentUart->tx_io_num				);
	gpio_set_direction(		currentUart->tx_io_num, GPIO_MODE_DEF_DISABLE	);

}




/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*--------------------------------------------------------------------- Local Functions ------------------------------------------------------------------*/
/*########################################################################################################################################################*/


// void uart_vSetup( const Uart *uart ){
	
// 	uart_config_t uart_config = {
// 		.baud_rate		= uart->uart_num,
// 		.data_bits		= UART_DATA_8_BITS,
// 		.parity			= UART_PARITY_DISABLE,
// 		.stop_bits		= UART_STOP_BITS_1,
// 		.flow_ctrl		= UART_HW_FLOWCTRL_DISABLE,
// 		.rx_flow_ctrl_thresh	= 122
// 	};
	
// 	ESP_ERROR_CHECK( uart_param_config( uart->uart_num, &uart_config ) );
// 	ESP_ERROR_CHECK( uart_set_pin( uart->uart_num, uart->tx_io_num, uart->rx_io_num, -1, -1 ) );
// 	ESP_ERROR_CHECK( uart_driver_install( uart->uart_num, HARDWARE_uartBufferSize, HARDWARE_uartBufferSize, HARDWARE_uartQueueSize, &sxUartQueue[ ( int ) uart->uart_num ], 0 ) ) ;
// }



// void uart_vSwapIo( const Uart *uart ){

// 	uart_flush(			uart->uart_num				);

// 	esp_rom_gpio_pad_select_gpio(	uart->rx_io_num				);
// 	gpio_set_direction(		uart->rx_io_num, GPIO_MODE_DEF_DISABLE	);

// 	esp_rom_gpio_pad_select_gpio(	uart->tx_io_num				);
// 	gpio_set_direction(		uart->tx_io_num, GPIO_MODE_DEF_DISABLE	);


// 	ESP_ERROR_CHECK( uart_set_pin( uart->uart_num, uart->tx_io_num, uart->rx_io_num, -1, -1 ) );

// }