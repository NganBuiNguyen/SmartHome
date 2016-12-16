#include "MsgIn.h"

MsgIn::MsgIn()
{
    this->helpRequested = false;
    this->portNumber = PORT_NUM;
    this->maxListenQueue = MAX_LISTEN_QUEUE;
    this->threads = MAX_THREADS;
}

MsgIn::~MsgIn()
{

}

void MsgIn::initialize(Poco::Util::Application& other)
{
    ServerApplication::initialize(other);
}

void MsgIn::uninitialize()
{
    ServerApplication::uninitialize();
}

void MsgIn::defineOptions(Poco::Util::OptionSet& options)
{
    ServerApplication::defineOptions(options);
}

void MsgIn::handlePortNumber(const std::string& name, const std::string& value)
{
    short int portNumber = atoi(value.c_str());
    if (portNumber > 0)
    {
        this->portNumber = portNumber;
    }
}

void MsgIn::handleThreads(const std::string& name, const std::string& value)
{
    short int threads = atoi(value.c_str());
    if (threads > 0)
    {
        this->threads = threads;
    }
}

void MsgIn::handleListenQueue(const std::string& name, const std::string& value)
{
    short int queue = atoi(value.c_str());

    if (queue > 0)
    {
        this->maxListenQueue = queue;
    }
}

void MsgIn::handleHelp(const std::string& name, const std::string& value)
{

}

int MsgIn::main(const std::vector<std::string>& args)
{
    if (this->helpRequested == false)
    {
        int maxQueued = config().getInt("MAX_LISTEN_QUEUE", 4096);
        int maxThreads = config().getInt("MAX_THREADS", 1000);

        Poco::ThreadPool::defaultPool().addCapacity(maxThreads);

        Poco::Net::TCPServerParams* params = new Poco::Net::TCPServerParams;

        params->setMaxQueued(maxQueued);
        params->setMaxThreads(maxThreads);

        Poco::Net::ServerSocket serverSocket(this->portNumber);

        MsgInConnectionFactory* msgInConnFactory = new MsgInConnectionFactory();
        Poco::Net::TCPServer server(msgInConnFactory, serverSocket, params);

        server.start();
        waitForTerminationRequest();
        server.stop();
    }

    return Application::EXIT_OK;
}