#ifndef __DB_EMPLOYEE_H__
#define __DB_EMPLOYEE_H__


#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept> //thu vien gi vay?


#include <mysql_driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/metadata.h>
#include <cppconn/resultset_metadata.h>
#include <cppconn/exception.h>
#include <cppconn/warning.h>


#include "Employee.h"



#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "hongha17"
#define DATABASE "SmartHome"

#define NUMOFFSET 100
#define COLNAME 200

class DbEmployee
{
public:
    static std::string database;
    static DbEmployee* instance;
    sql::Connection* getConn(std::string userName,std::string password,std::string url);
    void closeConn();
    void insert_node_to_db(sql::Connection* conn,Employee employee);
    static DbEmployee* getInstance();
   

private:
    DbEmployee();

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




