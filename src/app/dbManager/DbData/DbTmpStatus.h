#ifndef __DB_TMPSTATUS_H__
#define __DB_TMPSTATUS_H__

#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>

#include <mysql_driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/metadata.h>
#include <cppconn/resultset_metadata.h>
#include <cppconn/exception.h>
#include <cppconn/warning.h>


#include "DataDef.h"

#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "hongha17"
#define DATABASE "SmartHome"

#define NO_ROW_EFFECTED 0
#define NUMOFFSET 100
#define COLNAME 200
#define INSERT_DB_TMP_STATUS "INSERT INTO tbl_TmpStatus(ID_Tmp_Status,IDCard,IP, Port, Day, Mon, Year, Hour, Min, Sec) values(?,?,?,?,?,?,?,?,?,?)"

class DbTmpStatus
{
public:
    DbTmpStatus();
    void closeConn();
    bool insert_to_db_TmpStatus(const CardInfo &info);
    // bool select_to_db_TmpStatus();
    // bool update_to_db_TmpStatus(const CardInfo &info);
    // bool delete_to_db_TmpStatus(const CardInfo &info);
   
private:
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;
    sql::Statement* stmt;
    sql::Savepoint* savept;
};


#endif
