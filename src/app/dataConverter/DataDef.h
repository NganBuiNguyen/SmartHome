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
#define PORT 10

#define CARD_MESSAGE 'R'
#define ATTR_JSON_DATA "data"
#define ATTR_JSON_MESSAGE_TYPE "MESSAGE_TYPE"
#define ATTR_JSON_CARD_OPEN "CARD_VALUE"
#define CARD_TOPIC "CARD_VALUE_TOPIC"
#define ATTR_SMART_IS_OPEN_VALID = "CARD_OPEN_VALID_TOPIC"

#define MESSAGE_TYPE_CARD_VALUE "SMART_DOOR_VALUE"
#define MESSAGE_TYPE_DJANGO_VALUE "DJANGO_STATUS_VALUE"
#define MESSAGE_TYPE_DEFAULT_VALUE "MESSAGE_TYPE_DEFAULT"

#define ATTR_JSON_CARD_ID "ID"
#define ATTR_JSON_CARD_IP "ip"
#define ATTR_JSON_CARD_PORT "port"
#define ATTR_JSON_SENDER "Sender"
#define ATTR_JSON_DAY "day"
#define ATTR_JSON_MONTH "month"
#define ATTR_JSON_YEAR "year"
#define ATTR_JSON_HOUR "hour"
#define ATTR_JSON_MIN "min"
#define ATTR_JSON_SEC "sec"
#define ATTR_JSON_DATETIME "dateTime"


#define ATTR_JSON_IDCard "IDCard"
#define ATTR_JSON_TYPE_CARD "TypeCard"
#define ATTR_JSON_IDPerson "IDPerson"
#define ATTR_JSON_ARR_CARD "ARR_CARD"

// #include <stdbool.h>

typedef enum 
{
    MESSAGE_TYPE_DEFAULT = -1,
    MESSAGE_TYPE_DJANGO,
    MESSAGE_TYPE_CARD,
}MESSAGE_TYPE;


typedef struct
{
    int year ;
    int month ;
    int day ;
    int sec ;   
    int min ;   
    int hour ;
}Date_Time;

typedef struct
{
    char idPerson[PORT];
    char namePerson[NAME_CARD_PERSON_LENGTH];
    int age;
    bool grantPerson;
    char userName[NAME_CARD_PERSON_LENGTH];
    char password[PORT];
}Person;

typedef struct
{
    char idCard[NAME_CARD_PERSON_LENGTH];
    char idPerson[PORT];
}Card;

typedef struct
{
    char idDoor[PORT];
    char nameDoor[NAME_DOOR_ROOM];
    char ip[20];
    long port;
    char idRoom[PORT];
}Door;

typedef struct
{
    char idRoom[PORT];
    char nameRoom[NAME_DOOR_ROOM];
}Room;

typedef struct  
{
    bool statusDoor;
    bool checkCard;
    int id;
    char countTime[NAME_CARD_PERSON_LENGTH];
}History;

typedef struct
{
    Date_Time dateTime;
    Card card;
    Person person;
    Door door;
    Room room;
    History history;
}CardInfo; 



#endif