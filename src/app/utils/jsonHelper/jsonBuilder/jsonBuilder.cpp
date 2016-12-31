#include "jsonBuilder.h"

#ifdef UNITTEST
#define STATIC
#else
#define STATIC static
#endif


STATIC bool buildJsonMessageType(const MESSAGE_TYPE& messageType,
                                boost::property_tree::ptree& messageTypeTree)
{
    messageTypeTree.put(ATTR_JSON_MESSAGE_TYPE, ATTR_JSON_CARD_OPEN);

    return true;
}

/*!
 * @internal
 */
STATIC bool buildCardOpenJson(const std::string& message,
                                    boost::property_tree::ptree& dataTree)
{
    if (!isSensorMessage(message))
    {
        return false;
    }

    if (getJSONMessageType(message) != CARD_MESSAGE)
    {
        return false;
    }


    int openCard = convertHexToDec(message[1], message);
    //int openCard;

    dataTree.put(ATTR_JSON_CARD_ID, openCard);   
    
    return true;
}

/*!
 * @internal
 */
 bool writeJsonToString(boost::property_tree::ptree& pTree,
                                                    std::string& jsonString)
 {
    std::ostringstream buffer; 
    boost::property_tree::write_json(buffer, pTree, false); 
    jsonString = buffer.str();

    return true;
 }

/*!
 * @internal
 */
bool buildJson(const std::string& message, std::string& jsonString)
{
    boost::property_tree::ptree root;
    boost::property_tree::ptree messageTypeTree;
    boost::property_tree::ptree dataTree;

    MESSAGE_TYPE messageType = getJSONMessageType(message);
    if (messageType == MESSAGE_TYPE_DEFAULT)
    {
        return false;
    }

    if (!buildJsonMessageType(messageType, messageTypeTree))
    {
        return false;
    }

    if (messageType == CARD_MESSAGE)
    {
        if (!buildCardOpenJson(message, dataTree))
        {
            return false;
        }
    }

    root.add_child(ATTR_JSON_MESSAGE_TYPE, messageTypeTree);
    root.add_child(ATTR_JSON_DATA, dataTree);

    if (!writeJsonToString(root, jsonString))
    {
        return false;
    }

    return true;
}
