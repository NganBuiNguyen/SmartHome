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


#include "DataDef.h"



#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "hongha17"
#define DATABASE "SmartHome"

#define NUMOFFSET 100
#define COLNAME 200

class DbDoor
{
public:
    DbDoor();
    void closeConn();
    bool insert_to_db_Door(CardInfo &info);
    bool select_to_db_Door();
    bool update_to_db_Door(CardInfo &info);
    bool delete_to_db_Door(CardInfo &info);

private:
    sql::ResultSet* res;
    sql::Statement* stmt;
    sql::Driver* driver;
    sql::Savepoint* savept;
};

#endif

<<<<<<< HEAD:src/app/dbManager/DbData/DbDoor.h
=======
  DbCard dbCard;
  sql::Connection* conn;
  dbCard.insert_to_db(conn,card_User);

  
  return 0;
>>>>>>> e550bd49a0035aca1c2386cf7142295f3d1c321c:src/app/dbManager/main.cpp

