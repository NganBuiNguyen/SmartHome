#include "Poco/Timespan.h"
#include "UDPServer.h"
#include <iostream>

UDPServer::UDPServer(int bufferSize):
    thread("UDPServer"),
    stop(false),
    bufferSize(bufferSize)
{
    this->socket.bind(Poco::Net::SocketAddress(), true);
    this->thread.start(*this);
    this->ready.wait();
}

UDPServer::UDPServer(const Poco::Net::SocketAddress& sa, int bufferSize): 
    thread("UDPServer"),
    stop(false),
    bufferSize(bufferSize)
{
    this->socket.bind(sa, true);
    this->thread.start(*this);
    this->ready.wait();
}

UDPServer::~UDPServer()
{
    this->stop = true;
    this->thread.join();
}

Poco::UInt16 UDPServer::port() const
{
    return this->socket.address().port();
}

void UDPServer::run()
{
    this->ready.set();
    Poco::Timespan span(250000);
    char* pBuffer = new char[this->bufferSize];
    while(!this->stop)
    {
        if (this->socket.poll(span, Poco::Net::Socket::SELECT_READ))
	{
	    try
            {
	        Poco::Net::SocketAddress sender;
		int n = this->socket.receiveFrom(pBuffer, this->bufferSize, sender);
		std::cout << "Receive from: " << pBuffer << std::endl;
            }
	    catch(Poco::Exception& ex)
	    {
	        std::cout << "UDPServer: " << ex.displayText() << std::endl;
	    }
	}
    }

    if (pBuffer != NULL)
    {
        delete pBuffer;
    }
}

Poco::Net::SocketAddress UDPServer::address() const
{
    return this->socket.address();
}
