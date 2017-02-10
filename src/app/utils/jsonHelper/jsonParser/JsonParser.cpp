#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "JsonParser.h"         

          
#ifdef UNITTEST
#define STATIC
#else
#define STATIC static
#endif

STATIC std::string getJsonPath(const std::string& source,
                                            const std::string& destination)
{
    std::string jsonPath;
    jsonPath.append(source);
    jsonPath.append(JSON_PATH_SPLITTER);
    jsonPath.append(destination);
    return jsonPath;
}


bool parseOpenDoorJson(const std::string& jsonString, CardInfo& info)
{
    boost::property_tree::ptree pTree;
    
    if (jsonString.compare("") == 0)
    {
        return false;
    }

    if (!convertJsonStrToPtree(jsonString, pTree))
    {
        return false;
    }

    /*!
     * Parse Information of Sender
     */


    std::string jsonIPPath = getJsonPath(ATTR_JSON_SENDER, ATTR_JSON_CARD_IP);
    std::string jsonPortPath = getJsonPath(ATTR_JSON_SENDER, ATTR_JSON_CARD_PORT);
    std::string ipStr = pTree.get<std::string>(jsonIPPath);
    std::string portStr = pTree.get<std::string>(jsonPortPath);

    
    std::string jsonCardIntPath = getJsonPath(ATTR_JSON_DATA,
                                                ATTR_JSON_CARD_OPEN);

    std::string cardValueStr = 
                        pTree.get<std::string>(jsonCardIntPath);


    std::string jsonDayPath = getJsonPath(ATTR_JSON_DATETIME, ATTR_JSON_DAY);
    std::string jsonMonthPath = getJsonPath(ATTR_JSON_DATETIME, ATTR_JSON_MONTH);
    std::string jsonYearPath = getJsonPath(ATTR_JSON_DATETIME, ATTR_JSON_YEAR);
    std::string jsonHourPath = getJsonPath(ATTR_JSON_DATETIME, ATTR_JSON_HOUR);
    std::string jsonMinPath = getJsonPath(ATTR_JSON_DATETIME, ATTR_JSON_MIN);
    std::string jsonSecPath = getJsonPath(ATTR_JSON_DATETIME, ATTR_JSON_SEC);


    std::string dayStr = pTree.get<std::string>(jsonDayPath);
    std::string monthStr = pTree.get<std::string>(jsonMonthPath);
    std::string yearStr = pTree.get<std::string>(jsonYearPath);
    std::string hourStr = pTree.get<std::string>(jsonHourPath);
    std::string minStr = pTree.get<std::string>(jsonMinPath);
    std::string secStr = pTree.get<std::string>(jsonSecPath);

    
    strcpy(info.data.cardID, cardValueStr.c_str());
    info.sender.port = std::stol(portStr);
    strcpy(info.sender.ip, ipStr.c_str());

    info.dateTime.day = std::stoi(dayStr);
    info.dateTime.month = std::stoi(monthStr);
    info.dateTime.year = std::stoi(yearStr);
    info.dateTime.hour = std::stoi(hourStr);
    info.dateTime.min = std::stoi(minStr);
    info.dateTime.sec = std::stoi(secStr);

    return true;
}

