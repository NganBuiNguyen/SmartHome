#include "DbCardForC.h"
#include "DbCard.h"

#include <iostream>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <vector>
#include <string.h>



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

char *select_to_db_Card_ForC()
{
     return DB_CARD_MANAGER.select_to_db_Card();
    // std::vector<std::string> v = DB_CARD_MANAGER.select_to_db_Card();
    // char *arr;
    // for(std::vector<std::string>::iterator it = v.begin(); it != v.end() ; ++it )
    //     {
    //         std::cout << *it <<std::endl;
            
    //             strcpy(arr,*it);
    //             std::cout<<"ArrCard"<<arr<<std::endl;
            
    //     }
    // return arr;
}

bool update_to_db_Card_ForC(const CardInfo* info)
{
    return DB_CARD_MANAGER.update_to_db_Card(*info);

}

bool delete_to_db_Card_ForC(const CardInfo* info)
{
	return DB_CARD_MANAGER.delete_to_db_Card(*info);
}
