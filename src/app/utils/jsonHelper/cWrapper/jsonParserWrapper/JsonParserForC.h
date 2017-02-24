#ifndef __JSON_PARSER_FOR_C__
#define __JSON_PARSER_FOR_C__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "DataDef.h"

#ifdef __cplusplus
extern "C"{
#endif

/*!
 * @brief
 * param[in] message
 * return
 */
bool parseOpenDoorJsonForC(const char* jsonString, CardInfo* info);

#ifdef __cplusplus
}
#endif
#endif