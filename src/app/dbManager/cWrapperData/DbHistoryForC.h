#ifndef __DB_HISTORY_FOR_C__
#define __DB_HISTORY_FOR_C__

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
bool insertToDbHistoryForC(const CardInfo* info);
bool selectToDbHistoryForC(int IdHistory);
// bool update_to_db_TmpStatus_ForC(const CardInfo* info);
// bool delete_to_db_TmpStatus_ForC(const CardInfo* info);

#ifdef __cplusplus
}
#endif

#endif