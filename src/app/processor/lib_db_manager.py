"""
[description]
"""

from cffi_interfaces.__cffi_dbCard import dbCard_cffi
from cffi_interfaces.__cffi_dbCard import dbCard_c
from ctypes import *

import error_messages
import exceptions

DBA_RESULT_OK = 1

class LibDBManager(object):
    def __init__(self):
        pass

    def insert_history_card(self, smart_door_info):
        data_ptr = dbCard_cffi.new("CardInfo* ",\
                                          smart_door_info)
        result = dbCard_c.insertToDbHistoryForC(data_ptr)
        if not result:
            raise exceptions.InsertingTableDBCardForCFailure(\
                                 error_messages.ERROR_INSERT_INTO_STATUS_TABLE) 
    def select_card_info(self):
        list_cards = []

        list_card_infos_ptr = dbCard_cffi.new("CardInfo**")
        number_elements = dbCard_cffi.new("int*")

        result = dbCard_c.selectToDbCardForC(list_card_infos_ptr,
                                                            number_elements)

        if result != DBA_RESULT_OK:
            raise DbCardInfoSelectOperationFailure(ERROR_SELECT_CARD_INFO)

        for index in range(0, number_elements[0]):
            card_item = {}
            card_item['idCard'] = dbCard_cffi.string(\
                        list_card_infos_ptr[0].card.idCard).decode('utf-8')
            card_item['idPerson'] =  dbCard_cffi.string(\
                        list_card_infos_ptr[0].card.idPerson).decode('utf-8')
            list_cards.append(card_item)
        return list_cards

    def select_door_info(self):
        list_doors = []

        list_door_infos_ptr = dbCard_cffi.new("CardInfo**")
        number_elements = dbCard_cffi.new("int*")

        result = dbCard_c.selectToDbDoorForC(list_door_infos_ptr,
                                                            number_elements)

        if result != DBA_RESULT_OK:
            raise DbCardInfoSelectOperationFailure(ERROR_SELECT_CARD_INFO)

        for index in range(0, number_elements[0]):
            door_item = {}
            door_item['idDoor'] = dbCard_cffi.string(\
                        list_door_infos_ptr[0].door.idDoor).decode('utf-8')
            door_item['nameDoor'] =  dbCard_cffi.string(\
                        list_door_infos_ptr[0].door.nameDoor).decode('utf-8')
            door_item['ip'] =  dbCard_cffi.string(\
                        list_door_infos_ptr[0].door.ip).decode('utf-8')
            door_item['port'] = int(dbCard_cffi.cast(\
                                "long",list_door_infos_ptr[0].door.port))
            door_item['idRoom'] =  dbCard_cffi.string(\
                        list_door_infos_ptr[0].door.idRoom).decode('utf-8')
            list_doors.append(door_item)
        return list_doors

    def select_room_info(self):
        list_rooms = []

        list_room_infos_ptr = dbCard_cffi.new("CardInfo**")
        number_elements = dbCard_cffi.new("int*")

        result = dbCard_c.selectToDbRoomForC(list_room_infos_ptr,
                                                            number_elements)

        if result != DBA_RESULT_OK:
            raise DbCardInfoSelectOperationFailure(ERROR_SELECT_CARD_INFO)

        for index in range(0, number_elements[0]):
            room_item = {}
            room_item['idRoom'] = dbCard_cffi.string(\
                        list_room_infos_ptr[0].room.idRoom).decode('utf-8')
            room_item['nameRoom'] =  dbCard_cffi.string(\
                        list_room_infos_ptr[0].room.nameRoom).decode('utf-8')
            list_rooms.append(room_item)
        return list_rooms

    def select_doorcard_info(self):
        list_doorcards = []

        list_doorcard_infos_ptr = dbCard_cffi.new("CardInfo**")
        number_elements = dbCard_cffi.new("int*")

        result = dbCard_c.selectToDbRoomForC(list_doorcard_infos_ptr,
                                                            number_elements)

        if result != DBA_RESULT_OK:
            raise DbCardInfoSelectOperationFailure(ERROR_SELECT_CARD_INFO)

        for index in range(0, number_elements[0]):
            doorcard_item = {}
            doorcard_item['idCard'] = dbCard_cffi.string(\
                        list_doorcard_infos_ptr[0].card.idCard).decode('utf-8')
            doorcard_item['idDoor'] =  dbCard_cffi.string(\
                        list_doorcard_infos_ptr[0].door.idDoor).decode('utf-8')
            list_doorcards.append(doorcard_item)
        return list_doorcards
        
    def select_person_info(self):
        list_persons = []

        list_person_infos_ptr = dbCard_cffi.new("CardInfo**")
        number_elements = dbCard_cffi.new("int*")

        result = dbCard_c.selectToDbPersonForC(list_person_infos_ptr,
                                                            number_elements)

        if result != DBA_RESULT_OK:
            raise DbCardInfoSelectOperationFailure(ERROR_SELECT_CARD_INFO)

        for index in range(0, number_elements[0]):
            person_item = {}
            person_item['idPerson'] = dbCard_cffi.string(\
                        list_person_infos_ptr[0].person.idPerson).decode('utf-8')
            person_item['namePerson'] =  dbCard_cffi.string(\
                        list_person_infos_ptr[0].person.namePerson).decode('utf-8')
            person_item['age'] = int(dbCard_cffi.cast(\
                                "int",list_person_infos_ptr[0].person.age))

            list_persons.append(person_item)
        return list_persons

    def select_infoUser_info(self):
        list_infoUsers = []

        list_infoUser_infos_ptr = dbCard_cffi.new("CardInfo**")
        number_elements = dbCard_cffi.new("int*")

        result = dbCard_c.selectToDbAccountUserForC(list_infoUser_infos_ptr,
                                                            number_elements)

        if result != DBA_RESULT_OK:
            raise DbCardInfoSelectOperationFailure(ERROR_SELECT_CARD_INFO)

        for index in range(0, number_elements[0]):
            infoUser_item = {}
            infoUser_item['idPerson'] = dbCard_cffi.string(\
                        list_infoUser_infos_ptr[0].person.idPerson).decode('utf-8')
            infoUser_item['grantPerson'] = bool(dbCard_cffi.cast(\
                                "bool",list_infoUser_infos_ptr[0].person.grantPerson))
            infoUser_item['userName'] =  dbCard_cffi.string(\
                        list_infoUser_infos_ptr[0].person.userName).decode('utf-8')
            infoUser_item['password'] =  dbCard_cffi.string(\
                        list_infoUser_infos_ptr[0].person.password).decode('utf-8')
            
            list_infoUsers.append(infoUser_item)
        return list_infoUsers

    def select_history_info(self):
        list_historys = []

        list_history_infos_ptr = dbCard_cffi.new("CardInfo**")
        number_elements = dbCard_cffi.new("int*")

        result = dbCard_c.selectToDbHistoryForC(list_history_infos_ptr,
                                                            number_elements)

        if result != DBA_RESULT_OK:
            raise DbCardInfoSelectOperationFailure(ERROR_SELECT_CARD_INFO)

        for index in range(0, number_elements[0]):
            history_item = {}
            history_item['day'] = int(dbCard_cffi.cast(\
                                "int",list_history_infos_ptr[0].dateTime.day))
            history_item['month'] = int(dbCard_cffi.cast(\
                                "int",list_history_infos_ptr[0].dateTime.month))
            history_item['year'] = int(dbCard_cffi.cast(\
                                "int",list_history_infos_ptr[0].dateTime.year))
            history_item['hour'] = int(dbCard_cffi.cast(\
                                "int",list_history_infos_ptr[0].dateTime.hour))
            history_item['min'] = int(dbCard_cffi.cast(\
                                "int",list_history_infos_ptr[0].dateTime.min))
            history_item['sec'] = int(dbCard_cffi.cast(\
                                "int",list_history_infos_ptr[0].dateTime.sec))
            history_item['statusDoor'] = bool(dbCard_cffi.cast(\
                                "bool",list_history_infos_ptr[0].history.statusDoor))
            history_item['checkCard'] = bool(dbCard_cffi.cast(\
                                "bool",list_history_infos_ptr[0].history.checkCard))
        
            list_historys.append(history_item)
        return list_historys

    def check_card (self):
        list_doorcards_check = self.select_doorcard_info()
        list_cards_check = self.select_card_info()
        list_door_check = self.select_door_info()

        for item in list_doorcards_check:
            print(item)
            # if item.


    def function():
        pass

