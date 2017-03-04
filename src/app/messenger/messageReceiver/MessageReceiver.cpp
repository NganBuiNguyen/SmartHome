#include "MessageReceiver.h"



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
    
    void *context = zmq_ctx_new ();
    void *publisher = zmq_socket (context, ZMQ_PUB);
    zmq_bind(publisher, "tcp://*:5563");

    while(!this->stop)
    {
        if (this->socket.poll(span, Poco::Net::Socket::SELECT_READ))
        {
            try
            {
                char* pBuffer = new char[this->bufferSize];
                memset(pBuffer, 0, this->bufferSize * sizeof(char));
                Poco::Net::SocketAddress sender;
                int n = this->socket.receiveFrom(pBuffer, this->bufferSize, sender);

                MESSAGE_TYPE messageType = getJSONMessageType(pBuffer.c_str());

                if(strcmp(messageType,MESSAGE_TYPE_CARD)<0)
                {
                    std::string jsonString;
                    char* pTime = getTime();
                    /*!
                     * Appending IP of Sender to message
                     */
                    strcat(pBuffer, SENSOR_MESSAGE_SPLITTER);
                    strcat(pBuffer, sender.toString().c_str());
                    strcat(pBuffer, SENSOR_MESSAGE_SPLITTER);
                    strcat(pBuffer, pTime);

                    printf("%s\n",pBuffer);
                

                    if (isSensorMessage(pBuffer))
                    {
                        
                        if (!buildJson(pBuffer, jsonString))
                        {
                            
                            continue;
                        }

                        MESSAGE_TYPE messageType = getJSONMessageType(pBuffer);
                        std::string topic = convertMessageTypeToStr(messageType);
                        s_sendmore (publisher, (char*)topic.c_str());
                        s_send (publisher, (char*)jsonString.c_str());
                        sleep (1);
                    }

                    if (pBuffer != NULL)
                    {
                        pBuffer = NULL;
                        delete pBuffer;
                    }
                }else
                    {
                        std::cout << "Type of message is failed " << std::endl;
                    }
            }
            catch(Poco::Exception& ex)
            {
                std::cout << "MessageReceiver: " << ex.displayText() << std::endl;
            }
        }
    }
}

Poco::Net::SocketAddress MessageReceiver::address() const
{
    return this->socket.address();
}


