/*!****************************************************************************
* @file    prmSystem.h
* @author  Storozhenko Roman - D_EL
* @version V1.0
* @date    08.02.2016
* @brief   parametres system
*/
#ifndef PRMSYSTEM_H_
#define PRMSYSTEM_H_

/*!****************************************************************************
* Include
*/
#include "stdint.h"

/*!****************************************************************************
* User define
*/
#define typeu8Frmt		uint8_t
#define	types8Frmt		int8_t
#define	typeu16Frmt		uint16_t
#define	types16Frmt		int16_t
#define	typeu32Frmt		uint32_t
#define	types32Frmt		int32_t
#define	typesfloatFrmt	float

#define	power0			1U
#define	power1			10U
#define	power2			100U
#define	power3			1000U
#define	power4			10000U
#define	power5			100000U
#define	power6			1000000U

/*!****************************************************************************
* User enum
*/
#define parametres(_label, _units, _prm, _type, _chmod, _def, _min, _max, _step, _bigstep, _power, _save)	\
	N##_label,

typedef enum{
	#include "parametres.h"
	endOfNumberPrm,
}parametresNum_type;

#undef parametres

/*!****************************************************************************
* User typedef
*/
typedef union{
	uint8_t 	_u8Frmt;
	int8_t 		_s8Frmt;
	uint16_t 	_u16Frmt;
	int16_t 	_s16Frmt;
	uint32_t 	_u32Frmt;
	int32_t 	_s32Frmt;
	float		_floatFrmt;

	uint32_t	_unixTimeFrmt;
	uint32_t	_unixDateFrmt;
}prmval_type;

typedef enum{
    u8Frmt,
	s8Frmt,
	u16Frmt,
	s16Frmt,
	u32Frmt,
	s32Frmt,
	floatFrmt,

	unixTimeFrmt,
	unixDateFrmt,
}typePrm_type;

typedef enum{
	chmodNone,
	chmodAlways,
}chmodPrm_type;

typedef enum{
	prmNotSave,
	prmEeprom,
}nvSavePrm_type;

typedef struct{
	//char 			*label;
	//char 			*units;
	prmval_type		*prm;			//Pointer to parametr
	//uint32_t		(*pch)(void*);
	prmval_type		def;
	prmval_type		min;
	prmval_type		max;
	prmval_type		step;
	prmval_type		bigstep;

	typePrm_type	type		:4;
	chmodPrm_type	chmod		:2;
	uint8_t			power		:4;
	nvSavePrm_type	save		:2;

}prmHandle_type;

/*!****************************************************************************
* Extern viriables
*/
extern const prmHandle_type	prmh[] ;

/*!****************************************************************************
* Macro functions
*/

/*!****************************************************************************
* Prototypes for the functions
*/


#endif /* PRMSYSTEM_H_ */
/******************* (C) COPYRIGHT ***************** END OF FILE ********* D_EL *****/
