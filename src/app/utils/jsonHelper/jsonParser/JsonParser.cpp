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
    // std::string ipStr = pTree.get<std::string>("Sender.IP");
    // std::string portStr = pTree.get<std::string>("Sender.Port");

    
    // std::string cardValueStr = 
    //                     pTree.get<std::string>("data.CARD_VALUE");

    // info->data.cardID = std::stol(cardValueStr);
    // info->sender.port = std::stol(portStr);
    // strcpy(info->sender.ip, ipStr.c_str());


    std::string jsonIPPath = getJsonPath(ATTR_JSON_SENDER, ATTR_JSON_CARD_IP);
    std::string jsonPortPath = getJsonPath(ATTR_JSON_SENDER, ATTR_JSON_CARD_PORT);
    std::string ipStr = pTree.get<std::string>(jsonIPPath);
    std::string portStr = pTree.get<std::string>(jsonPortPath);

    /*!
     * Parse Light Intensity
     */
    std::string jsonCardIntPath = getJsonPath(ATTR_JSON_DATA,
                                                ATTR_JSON_CARD_OPEN);
    std::string cardValueStr = 
                        pTree.get<std::string>(jsonCardIntPath);

    strcpy(info.data.cardID, cardValueStr.c_str());
    info.sender.port = std::stol(portStr);
    strcpy(info.sender.ip, ipStr.c_str());
    return true;
}

