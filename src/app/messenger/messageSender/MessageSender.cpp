

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
