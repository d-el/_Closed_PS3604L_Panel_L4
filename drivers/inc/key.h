/*!****************************************************************************
* @file    		key.h
* @author  		Storozhenko Roman - D_EL
* @version 		V2.0
* @date    		07.06.2017
* @copyright 	GNU Public License
*/
#ifndef key_H
#define key_H

/*!****************************************************************************
* Include
*/
#include "stdint.h"
#include "math.h"
#include "gpio.h"

/*!****************************************************************************
* User include
*/

/*!****************************************************************************
* User define
*/
#define KEY_NUM             7
#define KEY_SAMPLES         4
//#define KEY_T_SAMPLES       50      ///< [ms]
//#define KEY_T_PRESS_POWER   1000    ///< [ms]

/*!****************************************************************************
* User typedef
*/
typedef enum{
	kMode		= (1 << 0),
	kView		= (1 << 1),
	kOnOff		= (1 << 2),
	kNext		= (1 << 3),
	kZero		= (1 << 4),
	kUp			= (1 << 5),
	kDown		= (1 << 6),
}kKey_type;

typedef struct{
	uint32_t	dInState;
	uint32_t	dInPrevState;
    uint32_t	keyState;
    uint32_t	reiterationSelect;
    uint8_t		toFirstReiteration;
    uint8_t		toReiteration;
    uint8_t		dInFilterCnt[KEY_NUM];
    uint8_t		toFirstReiterationCnt[KEY_NUM];
    uint8_t		toReiterationCnt[KEY_NUM];
}key_type;

/*!****************************************************************************
* User enum
*/

/*!****************************************************************************
* External variables
*/
extern key_type    key;

/*!****************************************************************************
* Macro functions
*/

/*!****************************************************************************
* Prototypes for the functions
*/
uint32_t keyProc(void);
uint32_t keyState(kKey_type keyMask);
void ksSet(uint16_t toFirstReiteration, uint16_t toReiteration, kKey_type reiterationKeyMask);

#endif //key_H
/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
