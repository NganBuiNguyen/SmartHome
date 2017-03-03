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


#include "Card.h"




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
<<<<<<< HEAD:src/app/dbManager/DbData/DbCard.h
=======
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
   
    static std::string database;
    static DbCard* instance;
    static DbCard* getInstance();
    sql::Connection* getConn(std::string userName,std::string password,std::string url);
>>>>>>> e550bd49a0035aca1c2386cf7142295f3d1c321c:src/app/dbManager/DbCard.h
    void closeConn();
    bool insert_to_db_Card(const CardInfo &info);
    char* select_to_db_Card();
    bool update_to_db_Card(const CardInfo &info);
    bool delete_to_db_Card(const CardInfo &info);
   
private:
<<<<<<< HEAD:src/app/dbManager/DbData/DbCard.h
=======
	
>>>>>>> e550bd49a0035aca1c2386cf7142295f3d1c321c:src/app/dbManager/DbCard.h
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;
    sql::Statement* stmt;
    sql::Savepoint* savept;
};


#endif
