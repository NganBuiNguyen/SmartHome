

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
