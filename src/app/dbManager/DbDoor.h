#ifndef __DB_DOOR_H__
#define __DB_DOOR_H__


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


#include "Door.h"



#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "hongha17"
#define DATABASE "SmartHome"

#define NUMOFFSET 100
#define COLNAME 200

class DbDoor
{
public:
    static std::string database;
    static DbDoor* instance;
    sql::Connection* getConn(std::string userName,std::string password,std::string url);
    void closeConn();
    void insert_node_to_db(sql::Connection* conn,Door door);
    void select_to_db(sql::Connection* conn);
    void update_to_db(sql::Connection* conn,Door door);
    void delete_to_db(sql::Connection* conn,Door door);
    static DbDoor* getInstance();
   

private:
    DbDoor();

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


