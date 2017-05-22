import threading
import json

import exceptions
import lib_db_manager
import constants
import json_parser

class MessageHandler(threading.Thread):
    def __init__(self, topic, message):
        threading.Thread.__init__(self)
        self.message = message.decode('utf-8')
        self.topic = topic.decode('utf-8')
        self.json_parser = json_parser.JsonParser()
 
    def process_smart_door_history(self):
        try:
            smart_door_info = self.json_parser.parse_smart_door_history(self.message)
            print("smart_door_info:", smart_door_info)
            self.lib_db_manager.insert_history_card(smart_door_info)
        except exceptions.InsertingTableDBCardForCFailure as ex:
            import traceback
            traceback.print_exc()
            print("Error message: ", ex)
        except Exception as ex:
            import traceback
            traceback.print_exc()
            print("Error message: ", ex)

    def is_card_id_valid(self,message):
        card_info = self.json_parser.parse_smart_door_history(message)
        lib_db_manager_obj = lib_db_manager.LibDBManager()
        print("\n\n\nsmart_info:", card_info)
        print("\n\n\ninfo:", card_info['card']['idCard'].decode("utf-8"))
        print("\n\n\ninfo_ip:", card_info['door']['ip'].decode("utf-8"))
        print("\n\n\ninfo_port:", card_info['door']['port'])
        ip = card_info['door']['ip'].decode("utf-8")
        port = card_info['door']['port'] 
        db_door = lib_db_manager_obj.select_door_info()
        print("\ndb door:", db_door)
        print("\ndb door port:", db_door[0]['port'])

        for door_index in db_door:
            if ip == door_index['ip']  and port == door_index['port']:
                id_door = door_index['idDoor']
        print("\nid_door:", id_door)

        id_card = card_info['card']['idCard'].decode("utf-8")
        db_card_door = lib_db_manager_obj.select_doorcard_info()
        print("\n\nData card:" , db_card_door)
        for info_index in db_card_door:
            print("info_index:" , info_index)
            if(id_card == info_index['idCard'] and id_door == info_index['idDoor']):
                return True
            else:
                return False
            
    def process_message(self):
        print("smart_door_info: 01")
        print("self.topic: ", self.topic)
        print("ATTR_SMART_DOOR_STATUS_VALUE: ", constants.ATTR_SMART_DOOR_STATUS_VALUE)
        if self.topic == constants.ATTR_SMART_DOOR_STATUS_VALUE:
            print("smart_door_info: 02")
            self.process_smart_door_history()
 
    def run(self):
        self.lib_db_manager = lib_db_manager.LibDBManager()
        self.process_message()