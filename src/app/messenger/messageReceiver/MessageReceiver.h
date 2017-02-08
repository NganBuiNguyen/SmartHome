#ifndef __MESSAGE_RECEIVER__
#define __MESSAGE_RECEIVER__

#include <iostream>
#include <string.h>
#include <string>
#include <arpa/inet.h>

#include "zhelpers.h"
#include "Poco/Net/Socket.h"
#include "Poco/Net/DatagramSocket.h"
#include "Poco/Thread.h"
#include "Poco/Event.h"
#include "Poco/Timespan.h"

#include "JsonCommon.h"
#include "JsonBuilder.h"
#include "Timer.h"

#define PUBLISHER_PORT_OPT 5600

class MessageReceiver: public Poco::Runnable
{
public:
    MessageReceiver(int bufferSize = 256);
    MessageReceiver(const Poco::Net::SocketAddress& sa, int bufferSize = 256);
    ~MessageReceiver();
    Poco::UInt16 port() const;
    Poco::Net::SocketAddress address() const;
    void run();

private:
    Poco::Net::DatagramSocket socket;
    Poco::Thread thread;
    Poco::Event ready;
    bool stop;
    int bufferSize;
    void* zmq_context = NULL;
    void* publisher = NULL;
};

#endif
