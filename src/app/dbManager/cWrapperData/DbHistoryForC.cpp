#include "DbHistoryForC.h"
#include "DbHistory.h"

#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>

#include <mysql_driver.h>
#include <cppconn/connection.h>

static DbTmpStatus DB_TMPSTATUS_MANAGER;

/*!
 * @internal
 */
bool insertToDbHistoryForC (const CardInfo* info)
{
    return DB_TMPSTATUS_MANAGER.insertToDbHistory(*info);

}

bool selectToDbHistoryForC (int IdHistory)
{
    return DB_TMPSTATUS_MANAGER.selectToDbHistory(IdHistory);

}

// bool update_to_db_TmpStatus_ForC(const CardInfo* info)
// {
//     return DB_TMPSTATUS_MANAGER.update_to_db_TmpStatus(*info);

// }

// bool delete_to_db_TmpStatus_ForC(const CardInfo* info)
// {
//     return DB_TMPSTATUS_MANAGER.delete_to_db_TmpStatus(*info);
// }
