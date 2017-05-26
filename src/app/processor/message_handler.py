import threading
import json

import exceptions
import lib_db_manager
import constants
import json_parser

from cffi_interfaces.__cffi_dbCard import dbCard_cffi
from cffi_interfaces.__cffi_dbCard import dbCard_c

list_card_insert = []

class MessageHandler(threading.Thread):
    def __init__(self, topic, message):
        threading.Thread.__init__(self)
        self.message = message.decode('utf-8')
        self.topic = topic.decode('utf-8')
        self.json_parser = json_parser.JsonParser()

    def is_card_id_valid(self,message):
        card_info = self.json_parser.parse_smart_door_history(message)
        print("\n\ncard info:",card_info)
        lib_db_manager_obj = lib_db_manager.LibDBManager()

        # check_card = card_info['history']['checkCard']
        
        ip = card_info['door']['ip'].decode("utf-8")
        port = card_info['door']['port'] 
        db_door = lib_db_manager_obj.select_door_info()
        id_door = card_info['door']['idDoor'].decode("utf-8")
        for door_index in db_door:
            if ip == door_index['ip']  and port == door_index['port']:
                id_door = door_index['idDoor']
        
        id_card = card_info['card']['idCard'].decode("utf-8")
        db_card_door = lib_db_manager_obj.select_doorcard_info()
        for info_index in db_card_door:
            # print("info_index:" , info_index)
            if(id_card == info_index['idCard'] and id_door == info_index['idDoor']):
                return True
                print("check card True:",check_card)
            else:
                return False
                # print("check card False:",check_card)

    
    def is_goin_goout(self,message):
        card_info = self.json_parser.parse_smart_door_history(message)
        list_door_infos_ptr = dbCard_cffi.new("CardInfo**")
        # number_elements = dbCard_cffi.new("int*")
        # status_door = card_info['history']['statusDoor']
        id_card = card_info['card']['idCard'].decode("utf-8")
        if id_card in list_card_insert:
            list_card_insert.remove(id_card)
            print("\n\nList card insert:", list_card_insert)
            return False
        else: 
            list_card_insert.append(id_card)
            print("\n\nList card insert2:", list_card_insert)
            return True
             
 
    def process_smart_door_history(self):
        try:
            smart_door_info = self.json_parser.parse_smart_door_history(self.message)
            print("smart_door_info:", smart_door_info)
            check_card = smart_door_info['history']['checkCard']
            status_door = smart_door_info['history']['statusDoor']
            check_card = self.is_card_id_valid(self.message)
            status_door = self.is_goin_goout(self.message)
            print("\n\n check card:", check_card)
            self.lib_db_manager.insert_history_card(smart_door_info)
        except exceptions.InsertingTableDBCardForCFailure as ex:
            import traceback
            traceback.print_exc()
            print("Error message: ", ex)
        except Exception as ex:
            import traceback
            traceback.print_exc()
            print("Error message: ", ex)

    

    def process_message(self):
        print("smart_door_info: 01")
        print("self.topic: ", self.topic)
        print("ATTR_SMART_DOOR_STATUS_VALUE: ", constants.ATTR_SMART_DOOR_STATUS_VALUE)
        if self.topic == constants.ATTR_SMART_DOOR_STATUS_VALUE:
            print("smart_door_info: 02")
            self.is_card_id_valid(self.message)
            print("\nis card id valid:",self.is_card_id_valid(self.message))
            self.is_goin_goout(self.message)
            print("\nis goin goout:",self.is_goin_goout(self.message))
            self.process_smart_door_history()
 
    def run(self):
        self.lib_db_manager = lib_db_manager.LibDBManager()
        self.process_message()