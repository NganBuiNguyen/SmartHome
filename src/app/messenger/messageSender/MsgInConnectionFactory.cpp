#include "MsgInConnectionFactory.h"

MsgInConnectionFactory::MsgInConnectionFactory()
{
}

MsgInConnectionFactory::MsgInConnectionFactory(const std::string& message)
{
    this->message = message;
}

Poco::Net::TCPServerConnection* MsgInConnectionFactory::createConnection(
									const Poco::Net::StreamSocket& socket)
{
    return new MsgInConnection(socket, this->message);
}