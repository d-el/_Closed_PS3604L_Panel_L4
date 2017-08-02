/*!****************************************************************************
 * @file    rtc
 * @author  d_el
 * @version V1.0
 * @date    05.12.2015, by d_el
 * @brief   --
 * @copyright GNU Public License
 */
#ifndef rtc_H
#define rtc_H

/*!****************************************************************************
 * Include
 */
#include "stm32l4xx.h"
#include "stdint.h"
#include "specificMath.h"
#include <time.h>

/*!****************************************************************************
 * User define
 */
#define RTC_LSE_TIMEOUT	(10000)
/*!****************************************************************************
 * User typedef
 */
typedef enum {
	rtc_wasOn, rtc_initOk, rtc_setOk, rtc_error,
} rtcStatus_type;

typedef struct {
	uint16_t year;  ///< Year
	uint8_t mon;   ///< Month
	uint8_t mday;  ///< The day of the month
	uint8_t hour;  ///< Hour
	uint8_t min;   ///< Minutes
	uint8_t sec;   ///< Second
	uint8_t wday;  ///< The day of week (0-6, Sunday is zero)
} time_type;

/*!****************************************************************************
 * User enum
 */

/*!****************************************************************************
 * Extern viriables
 */
extern time_t unixTime;
extern struct tm timeStrct;

/*!****************************************************************************
 * Macro functions
 */

/*!****************************************************************************
 * Prototypes for the functions
 */
rtcStatus_type rtc_init(void);
void rtc_getTime(struct tm *time);
rtcStatus_type rtc_setTime(const struct tm *t);
rtcStatus_type rtc_setTimeUnix(time_t time);
void rtc_writeToBkp(uint32_t val);
uint32_t rtc_ReadFromBkp(void);

#endif //rtc_H
/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
