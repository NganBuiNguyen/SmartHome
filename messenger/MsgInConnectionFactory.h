#ifndef __MsgInConnectionFactory_H__
#define __MsgInConnectionFactory_H__

#include <iostream>
#include <unistd.h>
#include <string>
#include <string.h>

#include "Poco/Net/TCPServerConnectionFactory.h"

#include "MsgInConnection.h"

class MsgInConnectionFactory : public Poco::Net::TCPServerConnectionFactory
{
public:
    MsgInConnectionFactory();
    MsgInConnectionFactory(const std::string& message);

    Poco::Net::TCPServerConnection* createConnection(
    								const Poco::Net::StreamSocket& socket);

private:
    std::string message;
};

#endif