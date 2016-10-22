#ifndef __MsgInConnection_H__
#define __MsgInConnection_H__

#include <iostream>
#include "Poco/Net/TCPServer.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/TCPServerConnection.h"

class MsgInConnection : public Poco::Net::TCPServerConnection
{
public:
    MsgInConnection(const Poco::Net::StreamSocket& s, const std::string& message);
    void run();
    
private:
    std::string message;
};

#endif