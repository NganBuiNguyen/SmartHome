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
bool select_to_db_Card_ForC(const CardInfo** info, int *numberOfElement);
bool update_to_db_Card_ForC(const CardInfo* info);
bool delete_to_db_Card_ForC(const CardInfo* info);

bool insert_to_db_TmpStatus_ForC(const CardInfo* info);
bool select_to_db_TmpStatus_ForC(int ID_TmpStatus);


#ifdef __cplusplus
}
#endif

#endif