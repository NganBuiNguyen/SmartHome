#ifndef __DATABASE_STRUCT_H__
#define __DATABASE_STRUCT_H__

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


#include "/data/SmartHome/src/app/dataConverter/Card.h"



#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "hongha17"
#define DATABASE "SmartHome"

#define NUMOFFSET 100
#define COLNAME 200

typedef struct
  {
  	sql::PreparedStatement* prep_stmt;
    sql::Connection* conn;
    sql::ResultSet* res;
    sql::Statement* stmt;
    sql::Driver* driver;
    sql::Savepoint* savept;


	char url[20];
	char user[20];
    char password[20];

  }Connect;

  sql::Connection* DbCard::getConn(std::string userName,std::string password,std::string url)
    {
        this->driver = get_driver_instance();
        this->conn = driver->connect(url, userName, password);
        this->conn->setSchema(database);
        this->conn->setAutoCommit(0);
        return this->conn;
    }

#endif