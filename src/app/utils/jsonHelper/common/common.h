#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <string.h>
#include <string>
#include <stdint.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


#define MAX_SENSOR_MESSAGE_LENGTH 11
#define CARD_MESSAGE 'C'
#define ATTR_JSON_DATA "data"
#define ATTR_JSON_MESSAGE_TYPE "MESSAGE_TYPE"
#define ATTR_JSON_CARD_OPEN "RFID"
#define ATTR_JSON_CARD_ID "ID"

enum MESSAGE_TYPE
{
    MESSAGE_TYPE_DEFAULT = -1,
    MESSAGE_TYPE_CARD,
};

MESSAGE_TYPE getJSONMessageType(std::string message);

bool isSensorMessage(const std::string& message);

int convertHexToDec(char LSB, std::string MSB);

#endif