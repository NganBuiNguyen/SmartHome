#include "DbCardForC.h"
#include "DbCard.h"
#include "DbTmpStatusForC.h"
#include "DbTmpStatus.h"

#include <iostream>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <vector>
#include <string.h>



#include <mysql_driver.h>
#include <cppconn/connection.h>

static DbCard DB_CARD_MANAGER;
static DbTmpStatus DB_TMPSTATUS_MANAGER;

/*!
 * @internal
 */
bool insert_to_db_Card_ForC(const CardInfo* info)
{
    return DB_CARD_MANAGER.insert_to_db_Card(*info);

}

bool select_to_db_Card_ForC(const CardInfo** info, int *numberOfElement)
{
    // std::vector<CardInfo> vectorCardInfos;
    // bool result = DB_CARD_MANAGER.select_to_db_Card(vectorCardInfos);
    // if (!result)
    // {
    //     return false;
    // }

    // memcpy(*info, &vectorCardInfos, vectorCardInfos.size() * sizeof(CardInfo));
    // *numberOfElement = vectorCardInfos.size();

    return true;
}

bool update_to_db_Card_ForC(const CardInfo* info)
{
    return DB_CARD_MANAGER.update_to_db_Card(*info);

}

bool delete_to_db_Card_ForC(const CardInfo* info)
{
	return DB_CARD_MANAGER.delete_to_db_Card(*info);
}


bool insert_to_db_TmpStatus_ForC (const CardInfo* info)
{
    return DB_TMPSTATUS_MANAGER.insert_to_db_TmpStatus(*info);

}

bool select_to_db_TmpStatus_ForC(int ID_TmpStatus)
{
    return DB_TMPSTATUS_MANAGER.select_to_db_TmpStatus(ID_TmpStatus);

}

