#ifndef __DATA_STRUCT_DEF_H__
#define __DATA_STRUCT_DEF_H__


#define SENSOR_MESSAGE_SPLITTER ";"
#define IP_MESSAGE_SPLITTER ":"
#define JSON_PATH_SPLITTER "."
#define TIME_SPLITTER "-"

#define MAX_SENSOR_MESSAGE_LENGTH 80
#define IP_PORT_TOKEN_SIZE 2
#define IP_PORT_DATE_TIME_SIZE 20
#define ID_CARD_SIZE 25

#define CARD_MESSAGE 'R'
#define ATTR_JSON_DATA "data"
#define ATTR_JSON_MESSAGE_TYPE "MESSAGE_TYPE"
#define ATTR_JSON_CARD_OPEN "CARD_VALUE"
#define CARD_TOPIC "CARD_TOPIC"
#define ATTR_JSON_CARD_ID "ID"
#define ATTR_JSON_CARD_IP "IP"
#define ATTR_JSON_CARD_PORT "Port"
#define ATTR_JSON_SENDER "Sender"
#define ATTR_JSON_DATE "Date"
#define ATTR_JSON_TIME "Time"
#define ATTR_JSON_REALTIME "RealTime"



typedef enum 
{
    MESSAGE_TYPE_DEFAULT = -1,
    MESSAGE_TYPE_CARD,
}MESSAGE_TYPE;


typedef struct
{
    char ip[IP_PORT_DATE_TIME_SIZE];
    long port;
}Sender;

typedef struct
{
    char date[IP_PORT_DATE_TIME_SIZE];
    char time[IP_PORT_DATE_TIME_SIZE];
}Timer;

typedef struct
{
    char cardID[ID_CARD_SIZE];
}OpenDoor;

typedef struct
{
    OpenDoor data;
    Sender sender;
    Timer timer;
}CardInfo;

#endif