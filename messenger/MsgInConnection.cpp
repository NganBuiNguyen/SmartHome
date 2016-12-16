#include "MsgInConnection.h"

MsgInConnection::MsgInConnection(const Poco::Net::StreamSocket& socket,
                                const std::string& message):
                                TCPServerConnection(socket)
{
    this->message = message;
}

void MsgInConnection::run()
{
    std::cout << "Request from " + this->socket().peerAddress().toString() << std::endl;
}