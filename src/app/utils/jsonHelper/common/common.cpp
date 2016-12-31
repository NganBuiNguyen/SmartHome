#include "common.h"


bool isSensorMessage(const std::string& message)
{
	if(message.length() > MAX_SENSOR_MESSAGE_LENGTH || message.length() <= 0)
	{
		return false;
	}
	return true;
}

MESSAGE_TYPE getJSONMessageType(const std::string& message)
{
    if (!isSensorMessage(message))
    {
        return MESSAGE_TYPE_DEFAULT;
    }

    switch(message[0])
    {
    case MESSAGE_TYPE_CARD:
        return MESSAGE_TYPE_CARD;
    default:
        return MESSAGE_TYPE_DEFAULT;
    }
}

int convertHexToDec(char LSB, std::string& MSB)
{
	int value = strtoul(MSB.substr(1, MSB.length()).c_str(), NULL, 16);
	return value;
}