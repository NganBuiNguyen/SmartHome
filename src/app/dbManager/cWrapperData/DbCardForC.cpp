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

bool selectToDbDoorForC(CardInfo** info, int *numberOfElement)
{
    if (*info != NULL)
    {
        delete *info;
        *info = NULL;
    }

    int index = 0;
    std::vector<CardInfo> vectorDoorInfos;
    bool result = DB_DOOR_MANAGER.selectToDbDoor(vectorDoorInfos);

    if (!result)
    {
        return false;
    }

    CardInfo* listDoorInfoTmp = new CardInfo[vectorDoorInfos.size()];
    *numberOfElement = vectorDoorInfos.size();

    for (index = 0; index < *numberOfElement; index++)
    {
        strcpy((listDoorInfoTmp[index]).door.idDoor,
                                        vectorDoorInfos[index].door.idDoor);
        strcpy((listDoorInfoTmp[index]).door.nameDoor,
                                        vectorDoorInfos[index].door.nameDoor);
        strcpy((listDoorInfoTmp[index]).door.ip,
                                        vectorDoorInfos[index].door.ip);

        (listDoorInfoTmp[index]).door.port = vectorDoorInfos[index].door.port;
        
        strcpy((listDoorInfoTmp[index]).door.idRoom,
                                        vectorDoorInfos[index].door.idRoom);
    }
   
    *info = listDoorInfoTmp;

    return true;
}

bool updateToDbDoorForC(const CardInfo* info)
{
    return DB_DOOR_MANAGER.updateToDbDoor(*info);
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

bool selectToDbRoomForC(CardInfo** info, int *numberOfElement)
{
    if (*info != NULL)
    {
        delete *info;
        *info = NULL;
    }

    int index = 0;
    std::vector<CardInfo> vectorRoomInfos;
    bool result = DB_ROOM_MANAGER.selectToDbRoom(vectorRoomInfos);

    if (!result)
    {
        return false;
    }

    CardInfo* listRoomInfoTmp = new CardInfo[vectorRoomInfos.size()];
    *numberOfElement = vectorRoomInfos.size();

    for (index = 0; index < *numberOfElement; index++)
    {
        strcpy((listRoomInfoTmp[index]).room.idRoom,
                                        vectorRoomInfos[index].room.idRoom);
        strcpy((listRoomInfoTmp[index]).room.nameRoom,
                                        vectorRoomInfos[index].room.nameRoom);
    }
   
    *info = listRoomInfoTmp;

    return true;
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

bool selectToDbPersonForC(CardInfo** info, int *numberOfElement)
{
    if (*info != NULL)
    {
        delete *info;
        *info = NULL;
    }

    int index = 0;
    std::vector<CardInfo> vectorPersonInfos;
    bool result = DB_PERSON_MANAGER.selectToDbInfoUser(vectorPersonInfos);

    if (!result)
    {
        return false;
    }

    CardInfo* listPersonInfoTmp = new CardInfo[vectorPersonInfos.size()];
    *numberOfElement = vectorPersonInfos.size();

    for (index = 0; index < *numberOfElement; index++)
    {
        strcpy((listPersonInfoTmp[index]).person.idPerson,
                                        vectorPersonInfos[index].person.idPerson);
        strcpy((listPersonInfoTmp[index]).person.namePerson,
                                        vectorPersonInfos[index].person.namePerson);

        (listPersonInfoTmp[index]).person.age = vectorPersonInfos[index].person.age;
    }
   
    *info = listPersonInfoTmp;

    return true;
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

bool selectToDbDoorCardForC(CardInfo** info, int *numberOfElement)
{
    if (*info != NULL)
    {
        delete *info;
        *info = NULL;
    }

    int index = 0;
    std::vector<CardInfo> vectorDoorCardInfos;
    bool result = DB_DOORCARD_MANAGER.selectToDbDoorCard(vectorDoorCardInfos);

    if (!result)
    {
        return false;
    }

    CardInfo* listDoorCardInfoTmp = new CardInfo[vectorDoorCardInfos.size()];
    *numberOfElement = vectorDoorCardInfos.size();

    for (index = 0; index < *numberOfElement; index++)
    {
        strcpy((listDoorCardInfoTmp[index]).card.idCard,
                                        vectorDoorCardInfos[index].card.idCard);
        strcpy((listDoorCardInfoTmp[index]).door.idDoor,
                                        vectorDoorCardInfos[index].door.idDoor);
    }
   
    *info = listDoorCardInfoTmp;

    return true;
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

bool selectToDbAccountUserForC(CardInfo** info, int *numberOfElement)
{
    if (*info != NULL)
    {
        delete *info;
        *info = NULL;
    }

    int index = 0;
    std::vector<CardInfo> vectorAccountUserInfos;
    bool result = DB_ACCOUNTUSER_MANAGER.selectToDbAccountUser(vectorAccountUserInfos);

    if (!result)
    {
        return false;
    }

    CardInfo* listAccountUserInfoTmp = new CardInfo[vectorAccountUserInfos.size()];
    *numberOfElement = vectorAccountUserInfos.size();

    for (index = 0; index < *numberOfElement; index++)
    {
        strcpy((listAccountUserInfoTmp[index]).person.idPerson,
                                        vectorAccountUserInfos[index].person.idPerson);
        (listAccountUserInfoTmp[index]).person.grantPerson = 
                                        vectorAccountUserInfos[index].person.grantPerson;
        strcpy((listAccountUserInfoTmp[index]).person.userName,
                                        vectorAccountUserInfos[index].person.userName);
        strcpy((listAccountUserInfoTmp[index]).person.password,
                                        vectorAccountUserInfos[index].person.password);
    }
   
    *info = listAccountUserInfoTmp;

    return true;
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

bool selectToDbHistoryForC(CardInfo** info, int *numberOfElement)
{
    if (*info != NULL)
    {
        delete *info;
        *info = NULL;
    }

    int index = 0;
    std::vector<CardInfo> vectorHistoryInfos;
    bool result = DB_HISTORY_MANAGER.selectToDbHistory(vectorHistoryInfos);

    if (!result)
    {
        return false;
    }

    CardInfo* listHistoryInfoTmp = new CardInfo[vectorHistoryInfos.size()];
    *numberOfElement = vectorHistoryInfos.size();

    for (index = 0; index < *numberOfElement; index++)
    {
        
        (listHistoryInfoTmp[index]).dateTime.day = 
                                        vectorHistoryInfos[index].dateTime.day;
        (listHistoryInfoTmp[index]).dateTime.month = 
                                        vectorHistoryInfos[index].dateTime.month;
        (listHistoryInfoTmp[index]).dateTime.year = 
                                        vectorHistoryInfos[index].dateTime.year;
        (listHistoryInfoTmp[index]).dateTime.hour = 
                                        vectorHistoryInfos[index].dateTime.hour;
        (listHistoryInfoTmp[index]).dateTime.min = 
                                        vectorHistoryInfos[index].dateTime.min;
        (listHistoryInfoTmp[index]).dateTime.sec = 
                                        vectorHistoryInfos[index].dateTime.sec;                                                                                                
        (listHistoryInfoTmp[index]).history.statusDoor = 
                                        vectorHistoryInfos[index].history.statusDoor;
        (listHistoryInfoTmp[index]).history.checkCard = 
                                        vectorHistoryInfos[index].history.checkCard;
    }
   
    *info = listHistoryInfoTmp;

    return true;
}

