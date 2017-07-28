/*!****************************************************************************
* @file    prmSystem.c
* @author  Storozhenko Roman - D_EL
* @version V1.0
* @date    08.02.2016
* @brief   parametres system
*/

/*!****************************************************************************
* Include
*/
#include "prmSystem.h"
#include "systemTSK.h"
#include "rtc.h"

/*!****************************************************************************
* MEMORY
*/
uint8_t testU8 = 100;
int16_t testS16 = -2805;
float  testFloat = -2.805f;



#define parametres(_label, _units, _prm, _type, _chmod, _def, _min, _max, _step, _bigstep, _power, _save)	\
{	/*.label 				= _label,*/					\
	/*.units 				= _units,*/					\
	.prm 				= (prmval_type*)&_prm,			\
	.def._##_type 		= (_def * power##_power),		\
	.min._##_type 		= (_min * power##_power),		\
	.max._##_type 		= (_max * power##_power),		\
	.step._##_type 		= (_step * power##_power),		\
	.bigstep._##_type 	= (_bigstep * power##_power),	\
	.type 				= _type,						\
	.chmod 				= _chmod,						\
	.power				= _power,						\
	.save				= _save,						\
},

const prmHandle_type	prmh[] = {
	#include "parametres.h"
};

#undef parametres

/******************* (C) COPYRIGHT ***************** END OF FILE ********* D_EL *****/
