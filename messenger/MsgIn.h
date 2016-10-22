#ifndef __MSG_IN_H__
#define __MSG_IN_H__

#define PORT_NUM 8787
#define MAX_LISTEN_QUEUE 4096
#define MAX_THREADS 1000

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <string.h>

#include "Poco/Util/ServerApplication.h"
#include "Poco/Net/TCPServerParams.h"
#include "Poco/Net/ServerSocket.h"

#include "MsgInConnectionFactory.h"

class MsgIn : public Poco::Util::ServerApplication
{
public:
    MsgIn();
    virtual ~MsgIn();

protected:
    void initialize(Application& other);
    void uninitialize();
    void defineOptions(Poco::Util::OptionSet& option);
    void handleHelp(const std::string& name, const std::string& value);
    void handlePortNumber(const std::string& name, const std::string& value);
    void handleListenQueue(const std::string& name, const std::string& value);
    void handleThreads(const std::string& name, const std::string& value);

    int main(const std::vector<std::string>& args);

private:
    bool helpRequested;
    short int portNumber;
    int maxListenQueue;
    int threads;
};

#endif