#include "DbCardForC.h"
#include "DbCard.h"
#include "DbHistory.h"
#include "DbDoor.h"
#include "DbRoom.h"
#include "DbPerson.h"
#include "DbDoorCard.h"
#include "DbAccountUser.h"

#include <iostream>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <vector>
#include <string.h>



#include <mysql_driver.h>
#include <cppconn/connection.h>

static DbCard DB_CARD_MANAGER;
static DbHistory DB_HISTORY_MANAGER;
static DbDoor DB_DOOR_MANAGER;
static DbRoom DB_ROOM_MANAGER;
static DbPerson DB_PERSON_MANAGER;
static DbDoorCard DB_DOORCARD_MANAGER;
static DbAccountUser DB_ACCOUNTUSER_MANAGER;


/*!
 * @internal
 */
bool insertToDbCardForC(const CardInfo* info)
{
    return DB_CARD_MANAGER.insertToDbCard(*info);

}

bool selectToDbCardForC(CardInfo** info, int *numberOfElement)
{
    if (*info != NULL)
    {
        delete *info;
        *info = NULL;
    }

    int index = 0;
    CardInfo* listCardInfoTmp = new CardInfo[2];
    std::vector<CardInfo> vectorCardInfos;
    bool result = DB_CARD_MANAGER.selectToDbCard(vectorCardInfos);

    if (!result)
    {
        return false;
    }

    *numberOfElement = vectorCardInfos.size();
    for (index = 0; index < *numberOfElement; index++)
    {
        strcpy((listCardInfoTmp[index]).card.idCard,
                                        vectorCardInfos[index].card.idCard);
        strcpy((listCardInfoTmp[index]).card.idPerson,
                                        vectorCardInfos[index].card.idPerson);
    }
   
    *info = listCardInfoTmp;

    return true;
}

bool updateToDbCardForC(const CardInfo* info)
{
    return DB_CARD_MANAGER.updateToDbCard(*info);

}

bool deleteToDbCardForC(const CardInfo* info)
{
	return DB_CARD_MANAGER.deleteToDbCard(*info);
}


/*!
 * @funtion of DbDoor
 */


bool insertToDbDoorForC(const CardInfo* info)
{
    return DB_DOOR_MANAGER.insertToDbDoor(*info);
}

bool selectToDbDoorForC(const CardInfo** info, int *numberOfElement)
{
    if (*info != NULL)
    {
        delete *info;
        *info = NULL;
    }

    int index = 0;
    std::vector<CardInfo> vectorCardInfos;
    bool result = DB_DOORCARD_MANAGER.selectToDbDoor(vectorCardInfos);

    if (!result)
    {
        return false;
    }

    CardInfo* listCardInfoTmp = new CardInfo[vectorCardInfos.size()];
    *numberOfElement = vectorCardInfos.size();

    for (index = 0; index < *numberOfElement; index++)
    {
        strcpy((listCardInfoTmp[index]).door.idDoor,
                                        vectorCardInfos[index].door.idDoor);
        strcpy((listCardInfoTmp[index]).door.nameDoor,
                                        vectorCardInfos[index].door.nameDoor);
        strcpy((listCardInfoTmp[index]).door.ip,
                                        vectorCardInfos[index].door.ip);

        (listCardInfoTmp[index]).door.ip = vectorCardInfos[index].door.ip;
        
        strcpy((listCardInfoTmp[index]).door.ip,
                                        vectorCardInfos[index].door.idRoom);
    }
   
    *info = listCardInfoTmp;

    return true;
}
bool updateToDbDoorForC(const CardInfo* info)
{
    return DB_DOOR_MANAGER.insertToDbDoor(*info);
}
bool deleteToDbDoorForC(const CardInfo* info)
{
    return DB_DOOR_MANAGER.deleteToDbDoor(*info);
}

/*!
 * @funtion of DbRoom
 */
bool insertToDbRoomForC(const CardInfo* info)
{
    return DB_ROOM_MANAGER.insertToDbRoom(*info);
}

bool selectToDbRoomForC(const CardInfo** info, int *numberOfElement)
{

}

bool updateToDbRoomForC(const CardInfo* info)
{
    return DB_ROOM_MANAGER.updateToDbRoom(*info);
}

bool deleteToDbRoomForC(const CardInfo* info)
{
    return DB_ROOM_MANAGER.deleteToDbRoom(*info);
}
/*!
 * @funtion of DbPerson
 */
bool insertToDbPersonForC(const CardInfo* info)
{
    return DB_PERSON_MANAGER.insertToDbInfoUser(*info);
}

bool selectToDbPersonForC(const CardInfo** info, int *numberOfElement)
{

}

bool updateToDbPersonForC(const CardInfo* info)
{
    return DB_PERSON_MANAGER.updateToDbInfoUser(*info);
}

bool deleteToDbPersonForC(const CardInfo* info)
{
    return DB_PERSON_MANAGER.deleteToDbInfoUser(*info);
}
/*!
 * @funtion of DbDoorCard
 */
bool insertToDbDoorCardForC(const CardInfo* info)
{
    return DB_DOORCARD_MANAGER.insertToDbDoorCard(*info);
}

bool selectToDbDoorCardForC(const CardInfo** info, int *numberOfElement)
{
    // if (*info != NULL)
    // {
    //     delete *info;
    //     *info = NULL;
    // }

    // int index = 0;
    // CardInfo* listCardInfoTmp = new CardInfo[2];
    // std::vector<CardInfo> vectorCardInfos;
    // bool result = DB_DOORCARD_MANAGER.selectToDbDoorCard(vectorCardInfos);

    // if (!result)
    // {
    //     return false;
    // }

    // *numberOfElement = vectorCardInfos.size();
    // for (index = 0; index < *numberOfElement; index++)
    // {
    //     strcpy((listCardInfoTmp[index]).door.idCard,
    //                                     vectorCardInfos[index].card.idCard);
    //     strcpy((listCardInfoTmp[index]).card.idPerson,
    //                                     vectorCardInfos[index].card.idPerson);
    // }
   
    // *info = listCardInfoTmp;

    // return true;
}
bool updateToDbDoorCardForC(const CardInfo* info, int id)
{
    return DB_DOORCARD_MANAGER.updateToDbDoorCard(*info,id);
}

bool deleteToDbDoorCardForC(const CardInfo* info, int id)
{
    return DB_DOORCARD_MANAGER.deleteToDbDoorCard(*info, id);
}
/*!
 * @funtion of DbDoorCard
 */
bool insertToDbAccountUserForC(const CardInfo* info)
{
    return DB_ACCOUNTUSER_MANAGER.insertToDbAccountUser(*info);
}

bool selectToDbAccountUserForC(const CardInfo** info, int *numberOfElement)
{

}

bool updateToDbAccountUserForC(const CardInfo* info)
{
    return DB_ACCOUNTUSER_MANAGER.updateToDbAccountUser(*info);
}

bool deleteToDbAccountUserForC(const CardInfo* info)
{
    return DB_ACCOUNTUSER_MANAGER.deleteToDbAccountUser(*info);
}

/*!
 * @funtion of DbHistory
 */
bool insertToDbHistoryForC (const CardInfo* info)
{
    return DB_HISTORY_MANAGER.insertToDbHistory(*info);

}

bool selectToDbHistoryForC(const CardInfo** info, int *numberOfElement)
{
    // return DB_HISTORY_MANAGER.selectToDbHistory(IdHistory);
}

