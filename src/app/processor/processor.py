import sys
import threading
import zmq

import optionParser

from cffi_interfaces.__cffi_jsonCommon import jsonCommon_cffi
from cffi_interfaces.__cffi_jsonCommon import jsonCommon_c

from cffi_interfaces.__cffi_jsonParser import jsonParser_cffi
from cffi_interfaces.__cffi_jsonParser import jsonParser_c

from cffi_interfaces.__cffi_jsonBuilder import jsonBuilder_cffi
from cffi_interfaces.__cffi_jsonBuilder import jsonBuilder_c

from cffi_interfaces.__cffi_messageSender import messageSender_cffi
from cffi_interfaces.__cffi_messageSender import messageSender_c

from cffi_interfaces.__cffi_dbCard import dbCard_cffi
from cffi_interfaces.__cffi_dbCard import dbCard_c

class Processor(threading.Thread):
    def __init__(self, host, port, topic=None):
        threading.Thread.__init__(self)
        self.host = host 
        self.port = port
        self.topic = topic
        self.context = zmq.Context()
        self.sock = self.context.socket(zmq.SUB)

        if topic != None:
            for item in self.topic:
                self.sock.setsockopt_string(zmq.SUBSCRIBE, item)

    def connect(self):
        cmd = "tcp://" + self.host
        cmd = cmd + ":"
        cmd = cmd + self.port
        self.sock.connect(cmd)

    def subscribeTopic(self, topic):

        if self.topic == None:
            self.topic = topic
        else:    
            self.topic + topic

        for item in topic:
            self.sock.setsockopt_string(zmq.SUBSCRIBE, item)            

    def parseOpenDoorJson(self, jsonMessage):
        info = jsonParser_cffi.new("CardInfo* ");
        
        jsonParser_c.parseOpenDoorJsonForC(jsonMessage, info);
        print("Message: ", jsonMessage)
        return jsonParser_cffi.string(info[0].card.idCard), jsonParser_cffi.string(info[0].ip_port.ip),\
                info[0].ip_port.port 

    def buildJsonMessage(self, message):
        pass

    def sendMessageToArduino(self, message, host, port):
        messageStr = messageSender_cffi.new("char *")
        host = messageSender_cffi.new("char *")
        messageStr[0] = message
        host[0] = host

        messageSender_c.sendMessageUDPForC(messageStr, host, port)

    #def dbCard(self, IDCard , NameKindCard , IDPerson):
    def dbCard(self, IDCard):
        print("1");
        info = dbCard_cffi.new("CardInfo* ");
        print("2");
        info.card.idCard = IDCard;
        print("3");
        # info.card.nameKindCard = NameKindCard;
        # print("4");
        # info.card.idPerson = IDPerson;
        # print("5");
        # dbCard_c.insert_to_db_Card_ForC(info);
        # dbCard_c.select_to_db_Card_ForC();
        # dbCard_c.update_to_db_Card_ForC(info);
        dbCard_c.delete_to_db_Card_ForC(info);
        print("6")


    def run(self):
        print("Processor run on %s:%s" %(self.host, self.port))
        
        while True:
            topic = self.sock.recv()
            message = self.sock.recv()
            
            idCard, ip, port = self.parseOpenDoorJson(message)
            self.dbCard(idCard)

            print(idCard)
            print(ip)
            print(port)

if __name__ == '__main__':

    if len(sys.argv) < 4:
        print("Please provide at least 3 arguments.")
        sys.exit(2)

    host, port, topic = optionParser.parseCmdLineArg(sys.argv)    

    processor = Processor(host, port, topic)
    processor.connect()

    
    try:
        processor.run()
    except KeyboardInterrupt:
        print("Keyboard Interruption Errors.")

