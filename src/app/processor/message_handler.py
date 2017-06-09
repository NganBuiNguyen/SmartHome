import threading
import json

import exceptions
import lib_db_manager
import constants
import json_parser
import processor
import error_messages

from datetime import datetime
from cffi_interfaces.__cffi_dbCard import dbCard_cffi
from cffi_interfaces.__cffi_dbCard import dbCard_c

list_card_insert = []
list_time_info_count = []

class MessageHandler(threading.Thread):
    def __init__(self, topic, message, list_doors , list_card_doors):
        threading.Thread.__init__(self)
        self.message = message.decode('utf-8')
        self.topic = topic.decode('utf-8')
        self.json_parser = json_parser.JsonParser()
        # self.topic = self.get_message_topic(self.message)
        self.list_doors = list_doors
        self.list_card_doors = list_card_doors

    def is_card_id_valid(self,message):
        card_info = self.json_parser.parse_smart_door_history(message)
        db_card_door = self.list_card_doors
        ip = card_info[constants.ATTR_DOOR][constants.ATTR_NAME_IP].decode("utf-8")
        port = card_info[constants.ATTR_DOOR][constants.ATTR_PORT] 
        db_door = self.list_doors
        id_door = card_info[constants.ATTR_DOOR][constants.ATTR_ID_DOOR].decode("utf-8")
        for door_index in db_door:
            if ip == door_index[constants.ATTR_NAME_IP]  and port == door_index[constants.ATTR_PORT]:
                id_door = door_index[constants.ATTR_ID_DOOR]
        id_card = card_info[constants.ATTR_CARD][constants.ATTR_ID_CARD_INFO].decode("utf-8")
        for info_index in db_card_door:
            if(id_card == info_index[constants.ATTR_ID_CARD_INFO] and id_door == info_index['idDoor']):
                return True
        return False
                
    def is_goin_goout(self,message):
        card_info = self.json_parser.parse_smart_door_history(message)
        # list_door_infos_ptr = dbCard_cffi.new("CardInfo**")
        id_card = card_info[constants.ATTR_CARD][constants.ATTR_ID_CARD_INFO].decode("utf-8")
        if id_card not in list_card_insert:
            list_card_insert.append(id_card)
            return True
        else:
            list_card_insert.remove(id_card)
            return False
        
    def sum_time_info(self,message):
        card_info = self.json_parser.parse_smart_door_history(message)
        id_card = card_info[constants.ATTR_CARD][constants.ATTR_ID_CARD_INFO].decode("utf-8")
        date_time = datetime(card_info[constants.ATTR_DATE_TIME][constants.ATTR_YEAR], \
                    card_info[constants.ATTR_DATE_TIME][constants.ATTR_MONTH], \
                    card_info[constants.ATTR_DATE_TIME][constants.ATTR_DAY], \
                    card_info[constants.ATTR_DATE_TIME][constants.ATTR_HOUR], \
                    card_info[constants.ATTR_DATE_TIME][constants.ATTR_MIN], \
                    card_info[constants.ATTR_DATE_TIME][constants.ATTR_SEC])
        
        data_item = {}
        data_item[constants.ATTR_ID_CARD_INFO] = id_card
        data_item[constants.ATTR_DATE_TIME] = date_time
        
        
        if id_card in list_card_insert:
            list_time_info_count.append(data_item)
            print("\n\n list time count in if:",list_time_info_count)
            count_time = str(self.time_of_person(date_time,date_time))

        else:
            #print("\n\n datatime in go in go out:", data_item )
            # list_time_info_count.remove(data_item_index[constants.ATTR_ID_CARD_INFO])
            for data_item_index in list_time_info_count:
                print("\n\n data_item_index[constants.ATTR_DATE_TIME]",data_item_index[constants.ATTR_DATE_TIME])
                print("\n\n time current:", date_time)
                if data_item_index[constants.ATTR_ID_CARD_INFO] == id_card:
                    # date_time_index = datetime()
                    # print("\n\n date_time_index:", date_time_index)
                    # fmt = '%Y-%m-%d %H:%M:%S'
                    dstart = date_time
                    dend = data_item_index[constants.ATTR_DATE_TIME]
                    count_time = str(self.time_of_person(dstart,dend))
                    print("\n\n count_time", count_time)
                    list_time_info_count.remove(data_item_index)
        return count_time            
        
        
    
    def id_doorcard(self,message):
        card_info = self.json_parser.parse_smart_door_history(message)
        db_card_door = self.list_card_doors
        ip = card_info[constants.ATTR_DOOR][constants.ATTR_NAME_IP].decode("utf-8")
        port = card_info[constants.ATTR_DOOR][constants.ATTR_PORT] 
        db_door = self.list_doors
        id_door = card_info[constants.ATTR_DOOR][constants.ATTR_ID_DOOR].decode("utf-8")
        for door_index in db_door:
            if ip == door_index[constants.ATTR_NAME_IP]  and port == door_index['port']:
                id_door = door_index[constants.ATTR_ID_DOOR]
        id_card = card_info[constants.ATTR_CARD][constants.ATTR_ID_CARD_INFO].decode("utf-8")
        for info_index in db_card_door:
            if(id_card == info_index[constants.ATTR_ID_CARD_INFO] and id_door == info_index[constants.ATTR_ID_DOOR]):
                return info_index[constants.ATTR_ID]        
        return None

    def time_of_person(self,start_date,end_date):
        delta = abs(start_date - end_date)
        return delta

    # def 
    def process_smart_door_history(self):
        try:
            check_card = self.is_card_id_valid(self.message)
            status_door = self.is_goin_goout(self.message)
            print("\n\n list_card_insert true:",list_card_insert)
            print("\n\n status door1:",status_door)
            id = self.id_doorcard(self.message)
            count_time = self.sum_time_info(self.message)
            print("\n\n count_time process:", count_time)

            if(id != None):
                smart_door_info = self.json_parser.parse_smart_door_history(self.message)
                print("smart_door_info:", smart_door_info)
                smart_door_info[constants.ATTR_HISTORY][constants.ATTR_CHECK_CARD] = check_card 
                smart_door_info[constants.ATTR_HISTORY][constants.ATTR_STATUS_DOOR] = status_door
                print("\n\n status door:",status_door)
                smart_door_info[constants.ATTR_HISTORY][constants.ATTR_COUNT_TIME] = bytes(count_time , "ascii")
                smart_door_info[constants.ATTR_HISTORY][constants.ATTR_ID] = id
                self.lib_db_manager.insert_history_card(smart_door_info)
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
            host = json_message[constants.ATTR_SENDER][constants.ATTR_NAME_IP]
            is_open_valid = self.is_card_id_valid(self.message)
            if is_open_valid == True:
                self.lib_db_manager.message_sender(host, "YES")
            else: 
                self.lib_db_manager.message_sender(host, "NO")
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
            self.is_card_id_valid(self.message)
            print("\nis card id valid:",self.is_card_id_valid(self.message))
            self.is_goin_goout(self.message)
            print("\n\n is_goin_goout door:",self.is_goin_goout(self.message))
            self.process_smart_door_history()
            print('Send message Message Sender')
            self.process_send_message_to_arduino()

    # def get_message_topic(self, message):
    #     message_topic = None
    #     try:
    #         json_message = json.loads(message)
    #         message_topic = json_message[constants.ATTR_MESSAGE_TYPE]
    #     except json.decoder.JSONDecodeError:
    #         print("Error message: ",\
    #                         error_messages.ERROR_UPDATE_PROCESS)
    #     return message_topic
 
    def run(self):
        self.lib_db_manager = lib_db_manager.LibDBManager()
        self.process_message()