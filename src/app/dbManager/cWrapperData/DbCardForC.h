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
bool insertToDbCardForC(const CardInfo* info);
bool selectToDbCardForC(CardInfo** info, int *numberOfElement);
bool updateToDbCardForC(const CardInfo* info);
bool deleteToDbCardForC(const CardInfo* info);


bool insertToDbDoorForC(const CardInfo* info);
bool selectToDbDoorForC(CardInfo** info, int *numberOfElement);
bool updateToDbDoorForC(const CardInfo* info);
bool deleteToDbDoorForC(const CardInfo* info);


bool insertToDbRoomForC(const CardInfo* info);
bool selectToDbRoomForC(CardInfo** info, int *numberOfElement);
bool updateToDbRoomForC(const CardInfo* info);
bool deleteToDbRoomForC(const CardInfo* info);

bool insertToDbPersonForC(const CardInfo* info);
bool selectToDbPersonForC(CardInfo** info, int *numberOfElement);
bool updateToDbPersonForC(const CardInfo* info);
bool deleteToDbPersonForC(const CardInfo* info);

bool insertToDbDoorCardForC(const CardInfo* info);
bool selectToDbDoorCardForC(CardInfo** info, int *numberOfElement);
bool updateToDbDoorCardForC(const CardInfo* info,int id);
bool deleteToDbDoorCardForC(const CardInfo* info,int id);

bool insertToDbAccountUserForC(const CardInfo* info);
bool selectToDbAccountUserForC(CardInfo** info, int *numberOfElement);
bool updateToDbAccountUserForC(const CardInfo* info);
bool deleteToDbAccountUserForC(const CardInfo* info);

// bool insertToDbHistoryForC(const CardInfo* info);
// bool selectToDbHistoryForC(CardInfo** info, int *numberOfElement);
bool insertToDbHistoryUserForC(const CardInfo* info);

#ifdef __cplusplus
}
#endif
#endif