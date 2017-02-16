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
#include "DbCard.h"


#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "hongha17"
#define DATABASE "SmartHome"

#define NUMOFFSET 100
#define COLNAME 200

 int main()
{

  CardInfo card_User;
  strcpy(card_User.card.idCard,"C1");
  strcpy(card_User.card.nameKindCard,"L1");

  DbCard dbCard;
  sql::Connection* conn;
  dbCard.insert_to_db(conn,card_User);
  return 0;

}
