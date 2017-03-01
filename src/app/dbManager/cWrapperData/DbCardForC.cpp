#include "DbCardForC.h"
#include "DbCard.h"

#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>

#include <mysql_driver.h>
#include <cppconn/connection.h>

static DbCard DB_CARD_MANAGER;

/*!
 * @internal
 */
bool insert_to_db_Card_ForC(const CardInfo* info)
{
    return DB_CARD_MANAGER.insert_to_db_Card(*info);

}

bool select_to_db_Card_ForC()
{
    return DB_CARD_MANAGER.select_to_db_Card();

}

bool update_to_db_Card_ForC(const CardInfo* info)
{
    return DB_CARD_MANAGER.update_to_db_Card(*info);

}

bool delete_to_db_Card_ForC(const CardInfo* info)
{
	return DB_CARD_MANAGER.delete_to_db_Card(*info);
}
