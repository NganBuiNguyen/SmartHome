/*****************************************************************************/
/*!
 * @file MessageSender.h
 * @brief The blueprint of MessageSender
 * Copyright (c) Tien Nguyen Anh
 * @detail The class uses UDP protocol and poco library. 
 */
/*****************************************************************************/

#include "MessageSender.h"

bool sendMessage(std::string message, std::string host, unsigned int port)
{
    Poco::Net::SocketAddress socketAddress(host, port);
    this->sender.connect(socketAddress);

    int sizePackage = sender.sendBytes(message.data(), message.size());

    return sizePackage > 0;
}
