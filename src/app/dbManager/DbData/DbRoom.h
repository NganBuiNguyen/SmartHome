#ifndef __DB_ROOM_H__
#define __DB_ROOM_H__


#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <string.h>
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

class DbRoom
{
public:
    DbRoom();
    void closeConn();
    bool insertToDbRoom(const CardInfo &info);
    bool selectToDbRoom(std::vector<CardInfo>& vectorCardInfos);
    bool updateToDbRoom(const CardInfo &info);
    bool deleteToDbRoom(const CardInfo &info);
   
private:
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;
    sql::Statement* stmt;
    sql::Savepoint* savept;
};

#endif


