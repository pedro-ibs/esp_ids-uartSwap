/**
 * std.h
 *
 *  @date Created at:	01/12/2023, 10:27:05
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
/* Standard includes. */
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <strings.h>
#include <ctype.h>


/* Standard includes  esp32*/
#include <esp_log.h>
#include <sdkconfig.h>
#include <esp_system.h>
#include <esp_timer.h>
#include <spi_flash_mmap.h>
#include <nvs_flash.h>
#include <nvs.h>
#include <esp_wifi.h>
#include <esp_wps.h>
#include <esp_event.h>
#include <esp_sleep.h>

/* Standard driver */
#include <driver/uart.h>
#include <driver/gpio.h>


/* FreeRTOS standard includes.*/
#include <freertos/FreeRTOS.h>
#include <freertos/FreeRTOSConfig.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/list.h>
#include <freertos/queue.h>
#include <freertos/timers.h>
#include <freertos/event_groups.h>
#include <freertos/portable.h>
#include <freertos/semphr.h>
#include <freertos/portmacro.h>


#ifndef std_H_
#define std_H_

/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/
typedef const char 		( CCHR	);

typedef uint16_t		( u16	);
typedef uint8_t			( u8	);
typedef uint32_t 		( u32	);
typedef uint64_t 		( u64	);

typedef const uint16_t		( cu16	);
typedef const uint8_t		( cu8	);
typedef const uint32_t 		( cu32	);
typedef const uint64_t 		( cu64	);

/* macro -------------------------------------------------------------------------------------------------------------------------------------------------*/
#define NOT( var )		( ( var == false )?( true ):( false )	)
#define SetBit( RES, BIT ) 	( RES |=   ( 1 << BIT )			)
#define ClrBit( RES, BIT ) 	( RES &= ~ ( 1 << BIT )			)
#define TstBit( RES, BIT ) 	( RES &    ( 1 << BIT )			)
#define CplBit( RES, BIT ) 	( RES ^=   ( 1 << BIT )			)

#define BIT_XX( BIT )		( ( 1 << BIT )				)
/* consts ------------------------------------------------------------------------------------------------------------------------------------------------*/
#define DEC			( 10					)
#define HEX			( 16					)


#define BIT00			( BIT_XX( 0	)			)
#define BIT01			( BIT_XX( 1	)			)
#define BIT02			( BIT_XX( 2	)			)
#define BIT03			( BIT_XX( 3	)			)
#define BIT04			( BIT_XX( 4	)			)
#define BIT05			( BIT_XX( 5	)			)
#define BIT06			( BIT_XX( 6	)			)
#define BIT07			( BIT_XX( 7	)			)
#define BIT08			( BIT_XX( 8	)			)
#define BIT09			( BIT_XX( 9	)			)
// #define BIT10		( BIT_XX( 10	)			)
// #define BIT11		( BIT_XX( 11	)			)
// #define BIT12		( BIT_XX( 12	)			)
// #define BIT13		( BIT_XX( 13	)			)
// #define BIT14		( BIT_XX( 14	)			)
// #define BIT15		( BIT_XX( 15	)			)
// #define BIT16		( BIT_XX( 16	)			)
// #define BIT17		( BIT_XX( 17	)			)
// #define BIT18		( BIT_XX( 18	)			)
// #define BIT19		( BIT_XX( 19	)			)
// #define BIT20		( BIT_XX( 20	)			)
// #define BIT21		( BIT_XX( 21	)			)
// #define BIT22		( BIT_XX( 22	)			)
// #define BIT23		( BIT_XX( 23	)			)



/**
 * delays fot vTaskDelay
 */
#define _10MS			( pdMS_TO_TICKS( 10	)		)
#define _20MS			( pdMS_TO_TICKS( 20	)		)
#define _40MS			( pdMS_TO_TICKS( 40	)		)
#define _50MS			( pdMS_TO_TICKS( 50	)		)
#define _70MS			( pdMS_TO_TICKS( 70	)		)
#define _75MS			( pdMS_TO_TICKS( 75	)		)
#define _80MS			( pdMS_TO_TICKS( 80	)		)
#define _85MS			( pdMS_TO_TICKS( 85	)		)
#define _90MS			( pdMS_TO_TICKS( 90	)		)
#define _100MS			( pdMS_TO_TICKS( 100	)		)
#define _110MS			( pdMS_TO_TICKS( 110	)		)
#define _120MS			( pdMS_TO_TICKS( 120	)		)
#define _130MS			( pdMS_TO_TICKS( 130	)		)
#define _140MS			( pdMS_TO_TICKS( 140	)		)
#define _150MS			( pdMS_TO_TICKS( 150	)		)
#define _160MS			( pdMS_TO_TICKS( 160	)		)
#define _170MS			( pdMS_TO_TICKS( 170	)		)
#define _173MS			( pdMS_TO_TICKS( 173	)		)
#define _180MS			( pdMS_TO_TICKS( 180	)		)
#define _190MS			( pdMS_TO_TICKS( 190	)		)
#define _200MS			( pdMS_TO_TICKS( 200	)		)
#define _250MS			( pdMS_TO_TICKS( 250	)		)
#define _260MS			( pdMS_TO_TICKS( 260	)		)
#define _270MS			( pdMS_TO_TICKS( 270	)		)
#define _280MS			( pdMS_TO_TICKS( 280	)		)
#define _290MS			( pdMS_TO_TICKS( 290	)		)
#define _300MS			( pdMS_TO_TICKS( 300	)		)
#define _350MS			( pdMS_TO_TICKS( 350	)		)
#define _400MS			( pdMS_TO_TICKS( 400	)		)
#define _450MS			( pdMS_TO_TICKS( 450	)		)
#define _500MS			( pdMS_TO_TICKS( 500	)		)
#define _800MS			( pdMS_TO_TICKS( 800	)		)
#define _1S			( pdMS_TO_TICKS( 1000	)		)
#define _2S			( pdMS_TO_TICKS( 2000	)		)
#define _3S			( pdMS_TO_TICKS( 3000	)		)
#define _4S			( pdMS_TO_TICKS( 4000	)		)
#define _5S			( pdMS_TO_TICKS( 5000	)		)
#define _6S			( pdMS_TO_TICKS( 6000	)		)
#define _7S			( pdMS_TO_TICKS( 7000	)		)
#define _8S			( pdMS_TO_TICKS( 8000	)		)
#define _9S			( pdMS_TO_TICKS( 9000	)		)
#define _10S			( pdMS_TO_TICKS( 10000	)		)
#define _20S			( pdMS_TO_TICKS( 20000	)		)

/**
 * times for RTC conter
 */
#define RTC_1S			( 1 					)
#define RTC_2S			( 2 					)
#define RTC_3S			( 3 					)
#define RTC_4S			( 4 					)
#define RTC_5S			( 5 					)
#define RTC_10S			( 10 					)
#define RTC_15S			( 15 					)
#define RTC_20S			( 20 					)
#define RTC_25S			( 25 					)
#define RTC_30S			( 30 					)
#define RTC_35S			( 35 					)
#define RTC_40S			( 40 					)
#define RTC_45S			( 45 					)
#define RTC_50S			( 50 					)
#define RTC_55S			( 55 					)
#define RTC_1MIN		( 60 					)
#define RTC_2MIN		( RTC_1MIN	* 2 			)
#define RTC_3MIN		( RTC_1MIN	* 3 			)
#define RTC_4MIN		( RTC_1MIN	* 4 			)
#define RTC_5MIN		( RTC_1MIN	* 5 			)
#define RTC_10MIN		( RTC_1MIN	* 10 			)
#define RTC_20MIN		( RTC_1MIN	* 20 			)
#define RTC_30MIN		( RTC_1MIN	* 30 			)
#define RTC_1HORA		( RTC_1MIN	* 60 			)
#define RTC_3HORA		( RTC_1HORA	* 3 			)
#define RTC_4HORA		( RTC_1HORA	* 4 			)
#define RTC_5HORA		( RTC_1HORA	* 5 			)
#define RTC_6HORA		( RTC_1HORA	* 6 			)
#define RTC_7HORA		( RTC_1HORA	* 7 			)
#define RTC_8HORA		( RTC_1HORA	* 8 			)
#define RTC_9HORA		( RTC_1HORA	* 9 			)
#define RTC_10HORA		( RTC_1HORA	* 10 			)
#define RTC_11HORA		( RTC_1HORA	* 11 			)
#define RTC_12HORA		( RTC_1HORA	* 12 			)
#define RTC_13HORA		( RTC_1HORA	* 13 			)
#define RTC_14HORA		( RTC_1HORA	* 14 			)
#define RTC_15HORA		( RTC_1HORA	* 15 			)
#define RTC_16HORA		( RTC_1HORA	* 16 			)
#define RTC_17HORA		( RTC_1HORA	* 17 			)
#define RTC_18HORA		( RTC_1HORA	* 18 			)
#define RTC_19HORA		( RTC_1HORA	* 19 			)
#define RTC_20HORA		( RTC_1HORA	* 20 			)
#define RTC_21HORA		( RTC_1HORA	* 21 			)
#define RTC_22HORA		( RTC_1HORA	* 22 			)
#define RTC_23HORA		( RTC_1HORA	* 23 			)
#define RTC_24HORA		( RTC_1HORA	* 24 			)

#endif /* std_H_ */
