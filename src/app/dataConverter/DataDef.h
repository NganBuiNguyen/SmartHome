#ifndef __DATA_STRUCT_DEF_H__
#define __DATA_STRUCT_DEF_H__


#define SENSOR_MESSAGE_SPLITTER ";"
#define IP_MESSAGE_SPLITTER ":"
#define JSON_PATH_SPLITTER "."
#define DATETIME_SPLITTER " "
#define DATE_SPLITTER "/"

#define MAX_SENSOR_MESSAGE_LENGTH 50
#define IP_PORT_TOKEN_SIZE 2
#define NAME_CARD_PERSON_LENGTH 20
#define NAME_DOOR_ROOM 10

#define CARD_MESSAGE 'R'
#define ATTR_JSON_DATA "data"
#define ATTR_JSON_MESSAGE_TYPE "MESSAGE_TYPE"
#define ATTR_JSON_CARD_OPEN "CARD_VALUE"
#define CARD_TOPIC "CARD_TOPIC"
#define ATTR_JSON_CARD_ID "ID"
#define ATTR_JSON_CARD_IP "IP"
#define ATTR_JSON_CARD_PORT "Port"
#define ATTR_JSON_SENDER "Sender"
#define ATTR_JSON_DAY "Day"
#define ATTR_JSON_MONTH "Month"
#define ATTR_JSON_YEAR "Year"
#define ATTR_JSON_HOUR "Hour"
#define ATTR_JSON_MIN "Min"
#define ATTR_JSON_SEC "Sec"
#define ATTR_JSON_DATETIME "DateTime"



typedef enum 
{
    MESSAGE_TYPE_DEFAULT = -1,
    MESSAGE_TYPE_CARD,
}MESSAGE_TYPE;


typedef struct
  {
     char ip[20];
     long port;
  }Sender;

typedef struct
  {
    int year ;
    int mon ;
    int day ;
    int sec ;   
    int min ;   
    int hour ;
  }Date_Time;

typedef struct
  {
      char cardID[25];
  }OpenDoor;

typedef struct
  {
     OpenDoor data;
     Sender sender;
     Date_Time dateTime;
  }CardInfo;
/*!
 * @Struct data
 */

typedef struct
{
    int idPerson;
    char namePerson[NAME_CARD_PERSON_LENGTH];
    int age;
    bool grantPerson;
    char idCard[NAME_CARD_PERSON_LENGTH];
    int idRoom;
}Person;

typedef struct
{
    char idCard[NAME_CARD_PERSON_LENGTH];
    char nameKindCard[NAME_CARD_PERSON_LENGTH];
    int idStatus;
}Card;

typedef struct
{
    int idStatus;
    bool nameStatus;
    time_t timeIn;
    time_t timeOut;
}Status;

typedef struct
{
    int idDoor;
    char nameDoor[NAME_DOOR_ROOM];
}Door;

typedef struct
{
    int idRoom;
    char nameRoom[NAME_DOOR_ROOM];
     //int countRoom;
}Room;

  typedef struct
{
    Card card;
    Person person;
    Door door;
    Room room;
    Status status;
}Info;

#endif