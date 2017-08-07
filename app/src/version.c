/*!****************************************************************************
* @file     version
* @author   d_el - Storozhenko Roman
* @date     07.08.2017 14:43:29
* @major    1
* @minor    0
* @revision 0
* @build    555
*/

#include "version.h"

const uint32_t fwinfoMajor    = 1;
const uint32_t fwinfoMinor    = 0;
const uint32_t fwinfoRevision = 0;
const uint32_t fwinfoBuild    = 555;
const char fwinfoVersion[] = {"1.0.0.555"};
const char fwinfoDate[]    = {"07.08.2017"};
const char fwinfoTime[]    = {"14:43:29"};

#include "stdint.h"

extern const uint32_t fwinfoMajor;
extern const uint32_t fwinfoMinor;
extern const uint32_t fwinfoRrevision;
extern const uint32_t fwinfoBuild;
extern const char fwinfoVersion[];
extern const char fwinfoDate[];

/***************** (C) COPYRIGHT ************** END OF FILE ******** d_el ****/
