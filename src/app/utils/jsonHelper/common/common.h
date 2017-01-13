#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <string.h>
#include <string>
#include <stdint.h>
#include <regex>
#include <math.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

//#define MAX_SENSOR_MESSAGE_LENGTH 24
#define SENSOR_MESSAGE_SPLITTER ";"
#define IP_MESSAGE_SPLITTER ":"
#define JSON_PATH_SPLITTER "."

#define MAX_SENSOR_MESSAGE_LENGTH 50
#define IP_PORT_TOKEN_SIZE 2
#define CARD_MESSAGE 'R'
#define ATTR_JSON_DATA "data"
#define ATTR_JSON_MESSAGE_TYPE "MESSAGE_TYPE"
#define ATTR_JSON_CARD_OPEN "CARD_VALUE"
#define CARD_TOPIC "CARD_TOPIC"
#define ATTR_JSON_CARD_ID "ID"
#define ATTR_JSON_CARD_IP "IP"
#define ATTR_JSON_CARD_PORT "Port"
#define ATTR_JSON_SENDER "Sender"


/*#define IP_PORT_REGEX_SPLITTER ":"
#define SENSOR_MESSAGE_SPLITTER ";"
#define LIGHT_INTENSITY_MESSAGE_VALUE 'L'
#define ATTR_JSON_MESSAGE_TYPE "MESSAGE_TYPE"
#define ATTR_JSON_DATA "data"
#define ATTR_JSON_LIGHT_INTENSITY "LIGHT_INTENSITY_VALUE"
#define ATTR_JSON_MOMENT "moment"
#define LIGHT_INTENSITY_TOPIC "LIGHT_INTENSITY_TOPIC"
#define CONTROL_SMART_PLUG_TOPIC "LIGHT_CONTROL_SMART_PLUG_TOPIC"
#define ATTR_JSON_IP "IP"
#define ATTR_JSON_PORT "Port"
#define ATTR_JSON_SENDER "Sender"*/


enum MESSAGE_TYPE
{
    MESSAGE_TYPE_DEFAULT = -1,
    MESSAGE_TYPE_CARD,
};

MESSAGE_TYPE getJSONMessageType(const std::string& message);

bool isSensorMessage(const std::string& message);

std::string convertMessageTypeToStr(const MESSAGE_TYPE& messageType);

bool convertJsonStrToPtree(const std::string& jsonString,
                                    boost::property_tree::ptree& dataTree);

 

#endif
