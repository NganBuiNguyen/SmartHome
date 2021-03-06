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


#include "Card.h"



#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "hongha17"
#define DATABASE "SmartHome"

#define NUMOFFSET 100
#define COLNAME 200

class DbCard
{
public:
    DbCard();
    static std::string database;// lam cho chung mot cai
    static DbCard* instance;// lam cho chung mot cai
    static DbCard* getInstance();// lam cho chung mot cai
    sql::Connection* getConn(std::string userName,std::string password,std::string url);
    void closeConn();// lam cho chung mot cai
     void insert_to_db(sql::Connection* conn,Card card);
     void select_to_db(sql::Connection* conn);
     void update_to_db(sql::Connection* conn,Card card);
     void delete_to_db(sql::Connection* conn,Card card);
   

private:
   
    
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
