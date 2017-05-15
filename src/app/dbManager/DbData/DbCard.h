#ifndef __DB_CARD_H__
#define __DB_CARD_H__

#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>
#include <vector>
#include <string>
#include <string.h>


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

class DbCard
{
public:
    DbCard();
    void closeConn();
    bool insertToDbCard(const CardInfo &info);
    bool selectToDbCard(std::vector<CardInfo>& vectorCardInfos);
    bool updateToDbCard(const CardInfo &info);
    bool deleteToDbCard(const CardInfo &info);
   
private:
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;
    sql::Statement* stmt;
    sql::Savepoint* savept;
};


#endif
