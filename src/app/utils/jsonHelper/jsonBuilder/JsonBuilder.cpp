#include <iostream>
#include <regex>
#include <string>
#include <string.h>

#include "JsonBuilder.h"

#ifdef UNITTEST
#define STATIC
#else
#define STATIC static
#endif


#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
/*!
 * @internal
 */
STATIC bool buildJsonMessageType(const MESSAGE_TYPE& messageType,
                                boost::property_tree::ptree& messageTypeTree)
{
    if (messageType == MESSAGE_TYPE_DEFAULT)
    {
        return false;
    }

    messageTypeTree.put(ATTR_JSON_MESSAGE_TYPE, ATTR_JSON_CARD_OPEN);

    return true;
}

/*!
 * @internal
 */
std::vector<std::string> splitWordRegex(const std::string& message,
                            const std::string& splitter)
{
    std::regex rgxSplitter(splitter);
    std::vector<std::string> token;
    std::sregex_token_iterator iter(message.begin(),
                                    message.end(),
                                    rgxSplitter,
                                    -1);

    std::sregex_token_iterator end;
    for(; iter != end; iter++)
    {
        token.push_back(*iter);
    }

    return token;
}

STATIC bool buildOpenDoorsityJson(const std::string& message,
                                    boost::property_tree::ptree& dataTree)
{
    if (getJSONMessageType(message) != MESSAGE_TYPE_CARD)
    {
        return false;
    }

    std::string msg = message.substr (1);
      
    dataTree.put(ATTR_JSON_CARD_OPEN, msg);
    
    return true;
}

/*!
 * built Time json
 */

STATIC bool buildTimeJson(const std::string& pTime,
                                    boost::property_tree::ptree& timeTree)
{
    std::vector<std::string> token = splitWordRegex(pTime,
                                    std::string(DATETIME_SPLITTER));

    std::vector<std::string> date = splitWordRegex(token[0],
                                    std::string(DATE_SPLITTER));

    timeTree.put(ATTR_JSON_DAY, date[0]);
    timeTree.put(ATTR_JSON_MONTH, date[1]);
    timeTree.put(ATTR_JSON_YEAR, date[2]);

    std::vector<std::string> time = splitWordRegex(token[1],
                                    std::string(IP_MESSAGE_SPLITTER));
    timeTree.put(ATTR_JSON_HOUR, time[0]);
    timeTree.put(ATTR_JSON_MIN, time[1]);
    timeTree.put(ATTR_JSON_SEC, time[2]);
    
    return true;
}

/*!
 * @internal
 */
STATIC bool buildIPSenderJSON(const std::string& ipAddress,
                                boost::property_tree::ptree& senderTree)
{
    boost::property_tree::ptree senderDataTree;

    std::vector<std::string> token = splitWordRegex(ipAddress,
                                    std::string(IP_MESSAGE_SPLITTER));

    if (token.size() != IP_PORT_TOKEN_SIZE)
    {
        return false;
    }

    senderTree.put(ATTR_JSON_CARD_IP, token[0]);
    senderTree.put(ATTR_JSON_CARD_PORT, token[1]);

    return true;
}

/*!
 * @internal
 */
std::string writeJsonToString(boost::property_tree::ptree& pTree)
{
    std::ostringstream buffer; 
    boost::property_tree::write_json(buffer, pTree, false); 
    
    return buffer.str();
}

/*!
 * @internal Using Regex to break message down into two part:
 *                 Data and IP of sender
 */
bool buildJson(const std::string& message, std::string& jsonString)
{
    boost::property_tree::ptree root;
    boost::property_tree::ptree messageTypeTree;
    boost::property_tree::ptree dataTree;
    boost::property_tree::ptree senderTree;
    boost::property_tree::ptree timeTree;

    std::vector<std::string> token = splitWordRegex(message,
                                    std::string(SENSOR_MESSAGE_SPLITTER));

    MESSAGE_TYPE messageType = getJSONMessageType(token[0].c_str());

    if (token.size() < 2)
    {
        return false;
    }

    std::string cardID = token[0].substr(1);
    

    if (!buildJsonMessageType(messageType, root)) 
    {
        
        return false;
    }
    
    if (!buildOpenDoorsityJson(token[0].c_str(), dataTree))
    {
       
        return false;
    }
    
    if (!buildIPSenderJSON(token[1].c_str(), senderTree))
    {
        
        return false;
    }
   
    if (!buildTimeJson(token[2].c_str(), timeTree))
    {
        std::cout << "08: " << std::endl;
        return false;
    }
    
    root.add_child(ATTR_JSON_DATA, dataTree);
    
    root.add_child(ATTR_JSON_SENDER, senderTree);
    
    root.add_child(ATTR_JSON_DATETIME, timeTree);
    
    jsonString = writeJsonToString(root);
    
    return true;
}
