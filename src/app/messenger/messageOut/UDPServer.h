#ifndef __UDPSERVER_H__
#define __UDPSERVER_H__

#include "Poco/Net/Socket.h"
#include "Poco/Net/DatagramSocket.h"
#include "Poco/Thread.h"
#include "Poco/Event.h"

class UDPServer: public Poco::Runnable
{
public:
    UDPServer(int bufferSize = 256);
    UDPServer(const Poco::Net::SocketAddress& sa, int bufferSize = 256);
    ~UDPServer();
    Poco::UInt16 port() const;
    Poco::Net::SocketAddress address() const;
    void run();

private:
    Poco::Net::DatagramSocket socket;
    Poco::Thread thread;
    Poco::Event ready;
    bool stop;
    int bufferSize;
};

#endif
