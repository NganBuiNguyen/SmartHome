/***************************************************************************/
/*!
 * @file JsonCommonForC.c
 * @brief
 *
 * Copyright (c) Tien Nguyen Anh
 *
 * @detail
 *
 * Modified History
 * ---------------
 * 2017-Jan-06 Created tien.nguyenanh94@gmail.com
 */
/***************************************************************************/
#include "JsonCommon.h"
#include "JsonCommonForC.h"

/*!
 * @internal
 */
void getJSONMessageTypeForC(const char* message, MESSAGE_TYPE* messageType)
{
    *messageType = getJSONMessageType(std::string(message));
}

/*!
 * @internal
 */
bool convertMessageTypeToStrForC(const MESSAGE_TYPE* messageType,
                                                        char** messageTypeStr)
{
    std::string messageTypeString = convertMessageTypeToStr(*messageType);
    *messageTypeStr = strdup(messageTypeString.c_str());
}

/*!
 * @internal
 */
bool isSensorMessageForC(const char* message)
{

    return isSensorMessage(std::string(message));
}