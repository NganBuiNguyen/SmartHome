
#include "messageReceiver.h"



MessageReceiver::MessageReceiver(int bufferSize):
    thread("MessageReceiver"),
    stop(false),
    bufferSize(bufferSize)
{
    this->socket.bind(Poco::Net::SocketAddress(), true);
    this->thread.start(*this);
    this->ready.wait();
}

MessageReceiver::MessageReceiver(const Poco::Net::SocketAddress& sa, int bufferSize):
    thread("MessageReceiver"),
    stop(false),
    bufferSize(bufferSize)
{
    this->socket.bind(sa, true);
    this->thread.start(*this);
    this->ready.wait();
}

MessageReceiver::~MessageReceiver()
{
    this->stop = true;
    this->thread.join();
    
    zmq_close(this->publisher);
    zmq_ctx_destroy(this->zmq_context);
}

Poco::UInt16 MessageReceiver::port() const
{
    return this->socket.address().port();
}

void MessageReceiver::run()
{
    this->ready.set();
    Poco::Timespan span(250000);
    char* pBuffer =new char[this->bufferSize];
    std::string pBuffer1= std::string(pBuffer);

    void *context = zmq_ctx_new ();
    void *publisher = zmq_socket (context, ZMQ_PUB);
    zmq_bind(publisher, "tcp://*:5563");

    while(!this->stop)
    {
        if (this->socket.poll(span, Poco::Net::Socket::SELECT_READ))
        {
            try
            {
                Poco::Net::SocketAddress sender;
                int n = this->socket.receiveFrom(pBuffer, this->bufferSize, sender);

                char* jsonString = NULL;

                std::string jsonString1(jsonString);
                std::string& jsonStr= jsonString1;
                /*!
                 * Appending IP of Sender to message
                 */
                strcat(pBuffer, SENSOR_MESSAGE_SPLITTER);
                strcat(pBuffer, sender.toString().c_str());

                if (isSensorMessage(pBuffer1))
                {
                    if (!buildJson(pBuffer1, jsonStr))
                    {
                        continue;
                    }

                    MESSAGE_TYPE messageType = getJSONMessageType(pBuffer1);
                    
                    std::string topic = convertMessageTypeToStr(messageType);
                    s_sendmore (publisher, (char*)topic.c_str());
                    s_send (publisher, jsonString);
                    sleep (1);
                }

            }
            catch(Poco::Exception& ex)
            {
                std::cout << "MessageReceiver: " << ex.displayText() << std::endl;
            }
        }
    }

    if (pBuffer1.compare("")==0)
    {
       pBuffer1.erase(pBuffer1.begin(),pBuffer1.end());
    }
}

Poco::Net::SocketAddress MessageReceiver::address() const
{
    return this->socket.address();
}
