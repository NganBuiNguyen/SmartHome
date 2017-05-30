#include <Time.h>
#include <SPI.h>
#include <Ethernet.h>
#include <Servo.h>
#include <EthernetUdp.h>
#include <MFRC522.h>

#define SS_PIN 6
#define RST_PIN 5
#define NEW_UID {0xDE, 0xAD, 0xBE, 0xEF}

Servo myservo;

long elapsed_time = 0;
long previousMillis = 0;
long previousMillis2 = 0;
long servointerval = 15;
long interval = 2000;




MFRC522 mfrc522(SS_PIN, RST_PIN);

byte mac[] =
{
    0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED  
};

/*!
 * Server's IP
 */
IPAddress server(192, 168, 3, 100);
int pos = 0; 

/*!
 * Server's port
 */
int SERVER_PORT = 8787;

/*!
 * Ethernet Shield's IP
 */
IPAddress ip(192, 168, 3, 177);

/*!
 * Ethernet Shield's port
 */
int internalPort = 6203 ;

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
    Serial.println("init");
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
  Serial.println("Starting read card function");
  if (!mfrc522.PICC_IsNewCardPresent())
    {
        return;
    }

    if (!mfrc522.PICC_ReadCardSerial())
    {
        return;
    } 

    Serial.println("Starting read card function 02");
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
    Serial.println(message);
    sendCardID(message);

    delay(1000);
    mfrc522.PICC_HaltA();
  
}

void sendCardID(char* msg)
{
    /*!
     * Send the message
     */
    Serial.println("I am here 01");
    Serial.print("Message: ");
    Serial.println(msg);
    udp.beginPacket(server, SERVER_PORT);
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
        if(strcmp(packetBuffer, "YES") == 0)
        {

           for(pos = 0; pos < 90; pos+=90) {      //opens the arm 90 degrees
                 unsigned long servoMillis = millis();
                if(servoMillis - previousMillis > servointerval)  //created to delay 15 milliseconds before next pulse
                  {
                   previousMillis = servoMillis;
                   myservo.write(pos);      //moves 5 degrees every 15 milliseconds
                  }
               
               }
                 
                unsigned long Starttimer=millis();      //starts one second delay timer?
                   do {
                      unsigned long current_time = millis();
                      elapsed_time = current_time - Starttimer;
                      }
                      while(elapsed_time < interval);      //leaves loop when 1 second has passed
                
                
                for(pos = 90; pos >=90; pos-=90) {    //closes the arm back to 0 degrees
                  unsigned long servoMillis2 = millis();
                  if(servoMillis2 - previousMillis2 > servointerval)
                  {
                  previousMillis2 = servoMillis2;
                  myservo.write(pos);
                  }
                 
              }
        }

     /*!
         * Do a action
         */
         
    }  
}
