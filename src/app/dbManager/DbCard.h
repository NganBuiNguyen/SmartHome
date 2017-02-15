#ifndef __DB_CARD_H__
#define __DB_CARD_H__

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

#define NUMOFFSET 100
#define COLNAME 200

class DbCard
{
public:
    static std::string database;
    static DbCard* instance;
    static DbCard* getInstance();
    sql::Connection* getConn(std::string userName,std::string password,std::string url);
    void closeConn();
    void insert_to_db(sql::Connection* conn,CardInfo &info);
    void select_to_db(sql::Connection* conn);
    void update_to_db(sql::Connection* conn,CardInfo &info);
    void delete_to_db(sql::Connection* conn,CardInfo &info);
   

private:
	DbCard();

    sql::PreparedStatement* prep_stmt;
    sql::Connection* conn;
    sql::ResultSet* res;
    sql::Statement* stmt;
    sql::Driver* driver;
    sql::Savepoint* savept;

    std::string url;
    std::string user;
    std::string password;

};


#endif
