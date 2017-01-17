#include <iostream>

#include "MessageReceiver.h"

#define SERVER_PORT 8787
#define MESSAGE_BUFFER 256

int main()
{
    Poco::Net::SocketAddress socketAddress(Poco::Net::IPAddress(), SERVER_PORT);
    MessageReceiver messageReceiver(socketAddress, MESSAGE_BUFFER);
    
    std::cout << "Server is on : "
              << messageReceiver.address().toString()
              << std::endl;

    messageReceiver.run();
    
    return 0;
}
