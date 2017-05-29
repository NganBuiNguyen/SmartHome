import threading
import json

import exceptions
import lib_db_manager
import constants
import json_parser
import processor

from cffi_interfaces.__cffi_dbCard import dbCard_cffi
from cffi_interfaces.__cffi_dbCard import dbCard_c

list_card_insert = []

class MessageHandler(threading.Thread):
    def __init__(self, topic, message, list_doors , list_card_doors):
        threading.Thread.__init__(self)
        self.message = message.decode('utf-8')
        self.topic = topic.decode('utf-8')
        self.json_parser = json_parser.JsonParser()
        self.list_doors = list_doors
        self.list_card_doors = list_card_doors

    def is_card_id_valid(self,message):
        card_info = self.json_parser.parse_smart_door_history(message)
        ip = card_info['door']['ip'].decode("utf-8")
        port = card_info['door']['port'] 
        db_door = self.list_doors
        id_door = card_info['door']['idDoor'].decode("utf-8")
        for door_index in db_door:
            if ip == door_index['ip']  and port == door_index['port']:
                id_door = door_index['idDoor']
        id_card = card_info['card']['idCard'].decode("utf-8")
        db_card_door = self.list_card_doors
        for info_index in db_card_door:
            if(id_card == info_index['idCard'] and id_door == info_index['idDoor']):
                return True
            else:
                return False
                

    
    def is_goin_goout(self,message):
        card_info = self.json_parser.parse_smart_door_history(message)
        list_door_infos_ptr = dbCard_cffi.new("CardInfo**")
        
        id_card = card_info['card']['idCard'].decode("utf-8")
        if id_card in list_card_insert:
            list_card_insert.remove(id_card)
            return False
        else: 
            list_card_insert.append(id_card)
            return True
    
    def id_doorcard(self,message):
        card_info = self.json_parser.parse_smart_door_history(message)
        db_card_door = self.list_card_doors
        ip = card_info['door']['ip'].decode("utf-8")
        port = card_info['door']['port'] 
        db_door = self.list_doors
        id_door = card_info['door']['idDoor'].decode("utf-8")
        for door_index in db_door:
            if ip == door_index['ip']  and port == door_index['port']:
                id_door = door_index['idDoor']
        id_card = card_info['card']['idCard'].decode("utf-8")
        print("\n\n select doorcard:",db_card_door)
        for info_index in db_card_door:
            print("\n\nindex info door1:",info_index['idCard'])
            if(id_card == info_index['idCard'] and id_door == info_index['idDoor']):
                return info_index['id']        
        return None

    def process_smart_door_history(self):
        try:
            # import pdb
            # pdb.set_trace()
            check_card = self.is_card_id_valid(self.message)
            status_door = self.is_goin_goout(self.message)
            id = self.id_doorcard(self.message)
            print("\n\n id:", id)
            if(id != None):
                smart_door_info = self.json_parser.parse_smart_door_history(self.message)
                print("smart_door_info:", smart_door_info)
                smart_door_info['history']['checkCard'] = check_card 
                smart_door_info['history']['statusDoor'] = status_door
                smart_door_info['history']['id'] = id
                print("\n\n check card:", check_card)
                self.lib_db_manager.insert_history_card(smart_door_info)
                print("\n\n smart door info test:", smart_door_info)
        except exceptions.InsertingTableDBCardForCFailure as ex:
            import traceback
            traceback.print_exc()
            print("Error message: ", ex)
        except Exception as ex:
            import traceback
            traceback.print_exc()
            print("Error message: ", ex)

    def process_send_message_to_arduino(self):
        try:
            json_message = json.loads(self.message)
            print("\n\n json_message_sender:", json_message)
            id_card = json_message[constants.ATTR_DATA][constants.ATTR_ID_CARD]
            print('id_card:', id_card)
            is_open_valid = self.is_card_id_valid(self.message)
            if is_open_valid == True:
                print('is_open_valid:',  is_open_valid)
                self.lib_db_manager.message_sender(id_card, "YES")
            else: 
                print('is_open_valid:',  is_open_valid)
                self.lib_db_manager.message_sender(id_card, "NO")
        except exceptions.SendMessageToArduinoFailure as ex:
            import traceback
            traceback.print_exc()
            print("Error message 01: ", ex)
        except Exception as ex:
            import traceback
            traceback.print_exc()
            print("Error message 02: ", ex)

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
        # elif self.topic == constants.ATTR_SMART_IS_OPEN_VALID:
            print('Send message Message Sender')
            self.process_send_message_to_arduino()

 
    def run(self):
        self.lib_db_manager = lib_db_manager.LibDBManager()
        self.process_message()