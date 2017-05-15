"""
[description]
"""

from cffi_interfaces.__cffi_dbCard import dbCard_cffi
from cffi_interfaces.__cffi_dbCard import dbCard_c

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
    
    def function():
        pass

