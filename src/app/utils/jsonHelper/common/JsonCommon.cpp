
#include "JsonCommon.h"


bool isSensorMessage(const std::string& message)
{
    std::string messageStr(message);

    if (messageStr.length() >= MAX_SENSOR_MESSAGE_LENGTH
        || messageStr.length() <= 0)
    {
        return false;
    }

    if (messageStr.find(SENSOR_MESSAGE_SPLITTER) == std::string::npos)// co nghia la -1
    {
        return false;
    }

    if (messageStr.find(IP_MESSAGE_SPLITTER) == std::string::npos)// co nghia la -1
    {
        return false;
    }

    return true;
}

MESSAGE_TYPE getJSONMessageType(const std::string& message)
{
    switch(message[0])
    {
    case CARD_MESSAGE:
        return MESSAGE_TYPE_CARD;
    default:
        return MESSAGE_TYPE_DEFAULT;
    }
}


std::string convertMessageTypeToStr(const MESSAGE_TYPE& messageType)
{
    switch(messageType)
    {
    case MESSAGE_TYPE_CARD:
        return std::string(CARD_TOPIC);
    default:
        return std::string("MESSAGE_TYPE_DEFAULT");
    }
}

bool convertJsonStrToPtree(const std::string& jsonString,
                                    boost::property_tree::ptree& dataTree)
{
    std::istringstream buffer(jsonString);
    boost::property_tree::read_json(buffer, dataTree);

    return true;
}


