#include "DbTmpStatusForC.h"
#include "DbTmpStatus.h"

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
bool insert_to_db_TmpStatus_ForC(const CardInfo* info)
{
    return DB_TMPSTATUS_MANAGER.insert_to_db_TmpStatus(*info);

}

// bool select_to_db_TmpStatus_ForC()
// {
//     return DB_TMPSTATUS_MANAGER.select_to_db_TmpStatus();

// }

// bool update_to_db_TmpStatus_ForC(const CardInfo* info)
// {
//     return DB_TMPSTATUS_MANAGER.update_to_db_TmpStatus(*info);

// }

// bool delete_to_db_TmpStatus_ForC(const CardInfo* info)
// {
//     return DB_TMPSTATUS_MANAGER.delete_to_db_TmpStatus(*info);
// }
