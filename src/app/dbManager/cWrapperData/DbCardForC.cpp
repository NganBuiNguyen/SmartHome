#include "DbCardForC.h"
#include "DbCard.h"

/*!
 * @internal
 */
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>

#include <cppconn/connection.h>


void insert_to_db_Card_ForC(const CardInfo* info)
{
	DbCard dbCard;
	sql::Connection* conn;
	dbCard.insert_to_db(conn, *info);
}