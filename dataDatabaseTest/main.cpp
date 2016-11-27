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
#include "DbCard.h"


#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "hongha17"
#define DATABASE "SmartHome"

#define NUMOFFSET 100
#define COLNAME 200

 int main()
{
  Card card_User("Card 1");
  //card_User.setCardID("Card 1");
  //card_User.setKindCard("Loai 2");

  DbCard dbCard;
  sql::Connection* conn;
  dbCard.delete_to_db(conn,card_User);
  return 0;

}
