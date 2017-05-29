import sys
import threading
import zmq

import lib_db_manager
import optionParser
import message_handler

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
list_card_doors = []
list_card_ids = []

class Processor(object):
    def __init__(self, host, port, topic=None):
        threading.Thread.__init__(self)
        self.host = host 
        self.port = port
        self.topic = topic
        self.context = zmq.Context()
        self.sock = self.context.socket(zmq.PAIR)
        self.list_doors = self.get_all_doors()
        self.list_card_ids = self.get_card_ids()
        self.list_card_doors = self.get_card_doors()

    def get_all_doors(self):
        lib_db_manager_obj = lib_db_manager.LibDBManager()
        db_door = lib_db_manager_obj.select_door_info()
        for door_index in db_door:
            print("\n\n door_index:", door_index)
            list_doors.append(door_index)
            print("\n\n list door:", list_doors)
        return list_doors
        

    def get_card_ids(self):
        lib_db_manager_obj = lib_db_manager.LibDBManager()
        db_card = lib_db_manager_obj.select_card_info()
        for card_index in db_card:
            print("\n\n door_index:", card_index)
            list_card_ids.append(card_index)
            print("\n\n list door:", list_card_ids)
        return list_card_ids

    def get_card_doors(self):
        lib_db_manager_obj = lib_db_manager.LibDBManager()
        db_card_door = lib_db_manager_obj.select_doorcard_info()
        for carddoor_index in db_card_door:
            print("\n\n door_index:", carddoor_index)
            list_card_doors.append(carddoor_index)
            print("\n\n list door:", list_card_doors)
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
            topic = self.sock.recv(2, zmq.NOBLOCK)
            message = self.sock.recv(2, zmq.NOBLOCK)
            print("message", topic)
            print("message", message)
            msg_handler = message_handler.MessageHandler(topic, message, list_doors, list_card_doors)
            msg_handler.run()
           

        self.sock.close()

if __name__ == '__main__':

    if len(sys.argv) < 4:
        print("Please provide at least 3 arguments.")
        sys.exit(2)

    host, port, topic = optionParser.parseCmdLineArg(sys.argv)    
    print("init topic: ", topic)
    processor = Processor(host, port, topic)
    processor.connect()

    try:
        processor.run()
    except KeyboardInterrupt:
        print("Keyboard Interruption Errors.")

