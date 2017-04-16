import threading
import json

import exceptions
import lib_db_manager
import constants
import json_parser

class MessageHandler(threading.Thread):
    def __init__(self, topic, message):
        threading.Thread.__init__(self)
        self.message = message
        self.topic = topic
        self.json_parser = json_parser.JsonParser()
 
    def process_smart_door_status(self):
        try:
            self.lib_db_manager.insert_status_card(smart_door_info)
        except exceptions.InsertingTableDeviceTimerForCFailure as ex:
            print("Error message: ", ex)
        except Exception as ex:
            print("Error message: ", ex)

    def process_message(self):
        if self.topic == constants.ATTR_SMART_DOOR_STATUS_VALUE:
            self.json_parser.parse_smart_door_status(self.message)
            self.process_smart_door_status()
 
    def run(self):
        self.lib_db_manager = lib_db_manager.LibDBManager()
        self.process_message()