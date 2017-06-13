import sys
import threading
import zmq

import lib_db_manager
import optionParser
import message_handler
import time
import json_parser
import constants

from cffi_interfaces import dbCard_c
from cffi_interfaces import dbCard_cffi

from cffi_interfaces import jsonCommon_c
from cffi_interfaces import jsonCommon_cffi

from cffi_interfaces import jsonBuilder_c
from cffi_interfaces import jsonBuilder_cffi

from cffi_interfaces import jsonParser_c
from cffi_interfaces import jsonParser_cffi

from cffi_interfaces import messageSender_c
from cffi_interfaces import messageSender_cffi

list_doors = []
list_card_ids = []
list_card_doors = []

class Processor(object):
    def __init__(self, host, port, topic=None):
        threading.Thread.__init__(self)
        self.host = host 
        self.port = port
        self.topic = topic
        self.db_manager = lib_db_manager.LibDBManager()
        self.context = zmq.Context()
        self.sock = self.context.socket(zmq.PAIR)
        self.json_parser = json_parser.JsonParser()
        self.list_doors = self.get_all_doors()
        self.list_card_ids = self.get_card_ids()
        self.list_card_doors = self.get_card_doors()

    def get_all_doors(self):
        db_door = self.db_manager.select_door_info()
        for door_index in db_door:
            list_doors.append(door_index)
        return list_doors
        
    def get_card_ids(self):
        db_card = self.db_manager.select_card_info()
        list_card_ids = []
        for card_index in db_card:
            list_card_ids.append(card_index)
        return list_card_ids

    def get_card_doors(self):
        db_card_door = self.db_manager.select_doorcard_info()
        for carddoor_index in db_card_door:
            list_card_doors.append(carddoor_index)
        return list_card_doors

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

    def sendMessageToArduino(self, message, host, port):
        messageStr = messageSender_cffi.new("char *")
        host = messageSender_cffi.new("char *")
        messageStr[0] = message
        host[0] = host
        messageSender_c.sendMessageUDPForC(messageStr, host, port)

    def run(self):
        print("Processor run on %s:%s" %(self.host, self.port))
        while True:
            message = self.sock.recv()
            print("message ",message)
            message = message.decode('utf-8')
            topic = self.json_parser.parse_json_message_topic(message)

            if topic == constants.ATTR_UDATE_PROCESS:
                self.list_doors = self.get_all_doors()
                self.list_card_ids = self.get_card_ids()
                self.list_card_doors = self.get_card_doors()
                print("\n\nself.list_card_ids",self.list_card_ids )
                print("\n\nself.list_doors")
                print(self.list_doors)
                print('\n\nself.list_card_doors')
                print(self.list_card_doors)
            else:
                msg_handler = message_handler.MessageHandler(topic, message,\
                                         self.list_doors, self.list_card_doors)
                msg_handler.run()
                time.sleep(1)

        self.sock.close()

if __name__ == '__main__':

    if len(sys.argv) < 4:
        print("Please provide at least 3 arguments.")
        sys.exit(2)

    host, port, topic = optionParser.parseCmdLineArg(sys.argv)    
    print("init topic: ", topic)
    # import pdb
    # pdb.set_trace()
    processor = Processor(host, port, topic)
    processor.connect()

    try:
        processor.run()
    except KeyboardInterrupt:
        print("Keyboard Interruption Errors.")

