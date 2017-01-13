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
 * ---------------
 * 2016-Dec-08 Created Tien Nguyen Anh
 */
/*****************************************************************************/

#include "MessageSender.h"

/*!
 * @internal
 */
bool sendMessageTCP(const std::string& message, const std::string& host,
                                                        unsigned int port)
{
    

}

/*!
 * @internal
 */
bool sendMessageUDP(const std::string& message, const std::string& host,
                                                        unsigned int port)
{
	Poco::Net::DatagramSocket sender;
    Poco::Net::SocketAddress socketAddress(host, port);
    sender.connect(socketAddress);

    int sizePackage = sender.sendBytes(message.data(), message.size());

    return sizePackage > 0;
}
