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

/*!
 * get realtime
 */
char* realTime ()
{
    char* pTime = new char[30];
    time_t rawtime;
    tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    int year = timeinfo->tm_year;
    int mon = timeinfo->tm_mon;
    int day = timeinfo->tm_mday;
    int sec = timeinfo->tm_sec;   
    int min = timeinfo->tm_min;   
    int hour = timeinfo->tm_hour;

    std::string yearStr = std::to_string(year);
    std::string monStr = std::to_string(mon);
    std::string dayStr = std::to_string(day);
    std::string secStr = std::to_string(sec);
    std::string minStr = std::to_string(min);
    std::string hourStr = std::to_string(hour);

    strcat(pTime,yearStr.c_str());
    strcat(pTime,"/");
    strcat(pTime,monStr.c_str());
    strcat(pTime,"/");
    strcat(pTime,dayStr.c_str());
    strcat(pTime,"  ");
    strcat(pTime,secStr.c_str());
    strcat(pTime,":");
    strcat(pTime,minStr.c_str());
    strcat(pTime,":");
    strcat(pTime,hourStr.c_str());

    return pTime;
}

Poco::UInt16 MessageReceiver::port() const
{
    return this->socket.address().port();
}

void MessageReceiver::run()
{
    this->ready.set();
    Poco::Timespan span(250000);
    char* pBuffer = new char[this->bufferSize];
    char* pTime;

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

                std::string jsonString;

                /*!
                 * Appending IP of Sender to message
                 */
                strcat(pBuffer, SENSOR_MESSAGE_SPLITTER);
                strcat(pBuffer, sender.toString().c_str());
                strcat(pBuffer, SENSOR_MESSAGE_SPLITTER);
                strcat(pBuffer, pTime.c_str());

                std::cout << "01: " << pBuffer << std::endl;


                if (isSensorMessage(pBuffer))
                {
                    std::cout << "03: " << pBuffer << std::endl;
                    if (!buildJson(pBuffer, jsonString))
                    {
                        std::cout << "04: " << pBuffer << std::endl;
                        continue;
                    }

                    MESSAGE_TYPE messageType = getJSONMessageType(pBuffer);

                    std::cout<< "02: " << pBuffer << std::endl;
                    
                    std::string topic = convertMessageTypeToStr(messageType);
                    s_sendmore (publisher, (char*)topic.c_str());
                    s_send (publisher, (char*)jsonString.c_str());

                    std::cout<< "05: " << topic << std::endl;
                    sleep (1);
                }

            }
            catch(Poco::Exception& ex)
            {
                std::cout << "MessageReceiver: " << ex.displayText() << std::endl;
            }
        }
    }

    if (pBuffer != NULL)
    {
        delete pBuffer;
    }
}

Poco::Net::SocketAddress MessageReceiver::address() const
{
    return this->socket.address();
}


