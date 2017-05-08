#include "DbCardForC.h"
#include "DbCard.h"
#include "DbHistoryForC.h"
#include "DbHistory.h"

#include <iostream>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <vector>
#include <string.h>



#include <mysql_driver.h>
#include <cppconn/connection.h>

static DbCard DB_CARD_MANAGER;
static DbHistory DB_HISTORY_MANAGER;

/*!
 * @internal
 */
bool insert_to_db_Card_ForC(const CardInfo* info)
{
    return DB_CARD_MANAGER.insert_to_db_Card(*info);

}

bool selectToDbCardForC(const CardInfo** info, int *numberOfElement)
{
    // std::vector<CardInfo> vectorCardInfos;
    // bool result = DB_CARD_MANAGER.selectToDbCard(vectorCardInfos);
    // if (!result)
    // {
    //     return false;
    // }

    // memcpy(*info, &vectorCardInfos, vectorCardInfos.size() * sizeof(CardInfo));
    // *numberOfElement = vectorCardInfos.size();

    // return true;
}

bool update_to_db_Card_ForC(const CardInfo* info)
{
    return DB_CARD_MANAGER.update_to_db_Card(*info);

}

bool delete_to_db_Card_ForC(const CardInfo* info)
{
	return DB_CARD_MANAGER.delete_to_db_Card(*info);
}


bool insertToDbHistoryForC (const CardInfo* info)
{
    return DB_HISTORY_MANAGER.insertToDbHistory(*info);

}

// bool selectToDbHistoryForC(int IdHistory)
// {
//     return DB_HISTORY_MANAGER.selectToDbHistory(IdHistory);

// }

