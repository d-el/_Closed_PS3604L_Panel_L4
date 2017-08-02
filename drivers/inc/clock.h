/*!****************************************************************************
 * @file    clock.h
 * @author  d_el
 * @version V1.0
 * @date    13.01.2017, by d_el
 * @brief   --
 */
#ifndef clock_H
#define clock_H

/*!****************************************************************************
 * Include
 */
#include "stm32l4xx.h"
#include "stm32l4xx_hal.h"

/*!****************************************************************************
 * User define
 */
#define RCC_CRYSTAL_ISCILLATOR_FREQ     24000000
#define RCC_RC_ISCILLATOR_FREQ          8000000
#define HSE_PLL_MUL                     2           //2-16, Коэффициент умножения PLL
#define HSE_PLL_PREDIV                  2           //1-16, Коэффициент деления PLL
#define HSI_PLL_MUL                     6           //2-16, Коэффициент умножения PLL
#define HSI_PLL_PREDIV                  1           //1-16, Коэффициент деления PLL
#define RCC_WAIN_TIMEOUT                100000

/*!****************************************************************************
 * User enum
 */
typedef enum {
	useHsi, useHse
} useGen_type;

/*!****************************************************************************
 * User typedef
 */
typedef struct {
	uint32_t currentSysFrec;
	useGen_type useGen;
} clock_type;

/*!****************************************************************************
 * Extern viriables
 */
extern clock_type clockSource;

/*!****************************************************************************
 * Macro functions
 */

/*!****************************************************************************
 * Prototypes for the functions
 */
void clock_init(void);
void Error_Handler(void);

#endif //clock_H
/***************** (C) COPYRIGHT ************** END OF FILE ******** d_el ****/
