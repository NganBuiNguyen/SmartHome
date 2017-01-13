/***************************************************************************/
/*!
 * @file JsonSenderForC.c
 * @brief
 *
 * Copyright (c) Tien Nguyen Anh
 *
 * @detail
 *
 * Modified History
 * ---------------
 * 2017-Jan-08 Created tien.nguyenanh94@gmail.com
 */
/***************************************************************************/

#include "MessageSender.h"
#include "MessageSenderForC.h"

/*!
 * @internal
 */
bool sendMessageUDPForC(const char* data, const char* host,
                                                        unsigned int port)
{
    if (data == NULL || host == NULL)
    {
        return false;
    }

    std::string message(data);
    std::string hostStr(host);

    return sendMessageUDP(message, host, port);
}

/*!
 * @internal
 */
bool sendMessageTCPForC(const char* data, const char* host,
                                                        unsigned int port)
{
    return false;
}