/*****************************************************************************/
/*!
 * @file MessageSender.h
 * @brief The blueprint of MessageSender
 *
 * Copyright (c) Tien Nguyen Anh
 *
 * @detail The class uses UDP protocol and poco library. 
 *
 * Modified History
 * ----------------
 * 2016-Dec-08 Created Tien Nguyen Anh
 */
/*****************************************************************************/

#ifndef __MESSAGE_SENDER_H__
#define __MESSAGE_SENDER_H__

#include <iostream>
#include <string>

#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"

#define PROCESSOR_PORT 6203

/*!
 * @brief
 * param[in] message
 * return
 */
bool sendMessageUDP(const std::string& message, const std::string& host,
                                                        unsigned int port);


/*!
 * @brief
 * param[in] message
 * return
 */
bool sendMessageTCP(const std::string& message, const std::string& host,
                                                        unsigned int port);

#endif
