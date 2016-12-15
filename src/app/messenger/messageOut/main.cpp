#include "UDPServer.h"
#include <iostream>


int main()
{
    Poco::Net::SocketAddress sa(Poco::Net::IPAddress(), 8787);
    std::cout << "sa port: " << sa.port() << std::endl;
    UDPServer server(sa, 256);
    std::cout << server.port() << std::endl;
    std::cout << server.address().toString() << std::endl;
    server.run();
    return 0;
}
