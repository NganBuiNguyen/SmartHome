#ifndef __DBCARD_FOR_C__
#define __DBCARD_FOR_C__

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
bool insert_to_db_Card_ForC(const CardInfo* info);
//bool select_to_db_Card_ForC();

#ifdef __cplusplus
}
#endif

#endif