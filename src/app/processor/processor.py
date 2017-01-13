"""
File: processor.py
=========================

Copyright (c) Tien Nguyen Anh

Modified History
----------------
2016-Dec-19 Created tien.nguyenanh94@gmail.com
"""

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

    def parseLightIntensityJson(self, jsonMessage):
        info = jsonParser_cffi.new("LightIntensityInfo* ");
        
        jsonParser_c.parseLightInteJsonForC(jsonMessage, info);

        return info[0].data.lightIntensity, jsonParser_cffi.string(info[0].sender.ip),\
                info[0].sender.port

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
            
            lightInte, ip, port = self.parseLightIntensityJson(message)

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

