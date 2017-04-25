"""
[description]
"""

from cffi_interfaces.__cffi_dbCard import dbCard_cffi
from cffi_interfaces.__cffi_dbCard import dbCard_c

import error_messages
import exceptions

class LibDBManager(object):
    def __init__(self):
        pass

    def insert_status_card(self, smart_door_info):
        data_ptr = dbCard_cffi.new("CardInfo* ",\
                                          smart_door_info)
        result = dbCard_c.insert_to_db_TmpStatus_ForC(data_ptr)
        if not result:
            raise exceptions.InsertingTableDBCardForCFailure(\
                                 error_messages.ERROR_INSERT_INTO_TIME_TABLE) 
