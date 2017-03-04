import sys
import threading
import zmq

import optionParser
import handle_dbTmpStatus
import handle_dbCardDoor

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

from cffi_interfaces.__cffi_dbTmpStatus import dbTmpStatus_cffi
from cffi_interfaces.__cffi_dbTmpStatus import dbTmpStatus_c

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
                info[0].ip_port.port, info[0].dateTime.day,info[0].dateTime.mon,info[0].dateTime.year,\
                info[0].dateTime.hour,info[0].dateTime.min,info[0].dateTime.sec

    def buildJsonMessage(self, message):
        pass

    def sendMessageToArduino(self, message, host, port):
        messageStr = messageSender_cffi.new("char *")
        host = messageSender_cffi.new("char *")
        messageStr[0] = message
        host[0] = host
        messageSender_c.sendMessageUDPForC(messageStr, host, port)

    def run(self):
        print("Processor run on %s:%s" %(self.host, self.port))
        while True:
            topic = self.sock.recv()
            message = self.sock.recv()
            
            idCard, ip, port , day, mon, year, hour, mins, sec = self.parseOpenDoorJson(message)
            # self.dbCard(idCard)
            # self.dbTmpStatus(idCard, ip, port , day, mon, year, hour, mins, sec)
            # self.dbTmpStatus()
            self.dbCard()
            # print(idCard)
            # print(ip)
            # print(port)
            # print(day)
            # print(mon)
            # print(year)
            # print(hour)
            # print(mins)
            # print(sec)

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

