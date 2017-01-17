#include <Time.h>
#include <SPI.h>
#include <Ethernet.h>
#include<Servo.h>
#include <EthernetUdp.h>
#include <MFRC522.h>

#define SS_PIN 6
#define RST_PIN 5
#define NEW_UID {0xDE, 0xAD, 0xBE, 0xEF}

Servo myservo;


MFRC522 mfrc522(SS_PIN, RST_PIN);

byte mac[] =
{
    0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED  
};

/*!
 * Server's IP
 */
IPAddress server(192, 168, 1, 152);
int pos = 0; 

/*!
 * Server's port
 */
int serverPort = 8787;

/*!
 * Ethernet Shield's IP
 */
IPAddress ip(192, 168, 1, 177);

/*!
 * Ethernet Shield's port
 */
int internalPort =8789 ;

/*!
 * Received buffer
 */
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];

/*!
 * Using UDP Protocol
 */
EthernetUDP udp;

/*!
 * Light Intensity sensor
 */


/*!
 * The last moment when I got the light intensity and sent it to server.
 */
unsigned long lastMoment = 0; 

/*!
 * Delay time
 */
const unsigned long delayInterval = 500L;

void setup()
{
    /*!
     * Serial is used for debug
     */
    Serial.begin(9600);

    /*!
     * Setup Ethernet Shield
     */
    Ethernet.begin(mac, ip);

    udp.begin(internalPort);
    myservo.attach(9);
    mfrc522.PCD_Init();
}

void convertInt16ToHexStr(unsigned long value, char* msg)
{
    unsigned long tmp = 0;
    char message[256];
    memset(message, 0, sizeof(message));

    while (value > 0)
    {
        tmp = value % 16;
        switch (tmp)
        {
        case 0:
            strcat(message, "0");
            break;
        case 1:
            strcat(message, "1");
            break;
        case 2:
            strcat(message, "2");
            break;
        case 3:
            strcat(message, "3");
            break;
        case 4:
            strcat(message, "4");
            break;
        case 5:
            strcat(message, "5");
            break;
        case 6:
            strcat(message, "6");
            break;
        case 7:
            strcat(message, "7");
            break;
        case 8:
            strcat(message, "8");
            break;
        case 9:
            strcat(message, "9");
            break;
        case 10:
            strcat(message, "A");
            break;
        case 11:
            strcat(message, "B");
            break;
        case 12:
            strcat(message, "C");
            break;
        case 13:
            strcat(message, "D");
            break;
        case 14:
            strcat(message, "E");
            break;
        case 15:
            strcat(message, "F");
            break;
        }
        value = value / 16;
    }
    strcat(message, '\0');
    strcat(msg, message);
}

void readCard()
{
  if (!mfrc522.PICC_IsNewCardPresent())
    {
        return;
    }

    if (!mfrc522.PICC_ReadCardSerial())
    {
        return;
    } 

 
    unsigned long uidDec = 0;
    unsigned long uidDecTemp = 0;
    
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
        uidDecTemp = mfrc522.uid.uidByte[i];
        uidDec = uidDec*256+uidDecTemp;
    }
    
    Serial.print("Data: ");
    Serial.println(uidDec);
    char message[11];
    memset(message, 0, sizeof(message));
    strcat(message, "R");
    convertInt16ToHexStr(uidDec, message);
    
    strcat(message ,"\0");
    sendCardID(message);

    delay(1000);
  
}

void sendCardID(char* msg)
{
    /*!
     * Send the message
     */
    Serial.println("I am here 01");
    Serial.print("Message: ");
    Serial.println(msg);
    udp.beginPacket(server, serverPort);
    udp.write(msg, strlen(msg) * sizeof(char));
    udp.endPacket();

    

}

void loop()
{
    readCard();
    int packetSize = udp.parsePacket();
    
    /*!
     * Handle the message from Server.
     * Execute the command line of 
     */
    if (packetSize)
    {
      
        /*!
         * Print the information of Sender for debug
         */
        Serial.print("Received packet of size ");
        Serial.println(packetSize);
        Serial.print("From ");
        IPAddress remote = udp.remoteIP();
        
        for (int i = 0; i < 4; i++)
        {
            Serial.print(remote[i], DEC);
            if (i < 3)
            {
                Serial.print(".");
            }
        }

        Serial.print(", port ");
        Serial.println(udp.remotePort());

        /*!
         * Reading the message
         */
        udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);

        /*
         * Print the content of message for debugging
         */
        Serial.println("Contents:");
        Serial.println(packetBuffer);
        if(packetBuffer)
        {
         for (pos = 0; pos <= 180; pos += 1) { 
           myservo.write(pos);              
           delay(15);                      
          
             }
         for (pos = 180; pos >= 0; pos -= 1) { 
            myservo.write(pos);            
            delay(15); 
                                  
            } 
        }
        /*!
         * Do a action
         */
         
    }  
}
