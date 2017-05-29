import sys
import os
import json
import unittest


LIDT_ROOT = os.environ['LIDT_ROOT']
sys.path.append(LIDT_ROOT + '/src/app/processor')

import message_handler
import constants

class TestMessageHandlerMethods(unittest.TestCase):

    def test_is_card_id_valid(self):
        json_dict = {
            "MESSAGE_TYPE" : "CARD_VALUE",
            "data" :
            {
                constants.ATTR_ID_CARD : "5D2A821C",
            },
            "Sender" : 
            {
                constants.ATTR_NAME_IP : "192.168.3.177",

                constants.ATTR_PORT : 6203,
            },
            "dateTime" : 
            {
                constants.ATTR_SEC : 1,
                
                constants.ATTR_MIN : 13,

                constants.ATTR_HOUR : 2,
                constants.ATTR_DAY : 21,
                constants.ATTR_MONTH : 3,
                constants.ATTR_YEAR : 2017,
           }
        }
        json_message = json.dumps(json_dict)
        print("\n\n\n json message test:", json_message)
        message_topic = constants.ATTR_SMART_DOOR_STATUS_VALUE
        list_doors = [
            {
                'idDoor': 'C0001',
                'nameDoor': 'Cua1',
                'ip': '192.168.3.177',
                'port' : 6203,
                'idRoom': 'P0001'
            },
            {
                'idDoor': 'C0002',
                'nameDoor': 'Cua2',
                'ip': '192.168.3.103',
                'port' : 5563,
                'idRoom': 'P0002'
            }
        ]

        list_card_doors = [
            {
                'id'    : 1,
                'idCard': '5D2A821C',
                'idDoor': 'C0001'
            },
            {
                'id'    : 2,
                'idCard': '6628E6EC',
                'idDoor': 'C0002'
            }
        ]
        message_handler_obj = message_handler.MessageHandler(topic=message_topic.encode(), 
                                                            message=json_message.encode(),
                                                            list_doors = list_doors,
                                                            list_card_doors = list_card_doors)
        
        try:
            result = message_handler_obj.is_card_id_valid(json_message)
            print("\n\nresult is valid:", result )
            self.assertTrue(True)
        except:
            self.assertTrue(False)
            

    def test_is_goin_goout(self):
        json_dict = {
            "MESSAGE_TYPE" : "CARD_VALUE",
            "data" :
            {
                constants.ATTR_ID_CARD : "5D2A821C",
            },
            "Sender" : 
            {
                constants.ATTR_NAME_IP : "192.168.3.100",

                constants.ATTR_PORT : 5563,
            },
            "dateTime" : 
            {
                constants.ATTR_SEC : 1,
                
                constants.ATTR_MIN : 13,

                constants.ATTR_HOUR : 2,
                constants.ATTR_DAY : 21,
                constants.ATTR_MONTH : 3,
                constants.ATTR_YEAR : 2017,
           }
        }

        json_message = json.dumps(json_dict)
        print("\n\n\n json message test:", json_message)
        message_topic = constants.ATTR_SMART_DOOR_STATUS_VALUE
        list_doors = [
            {
                'idDoor': 'C0001',
                'nameDoor': 'Cua1',
                'ip': '192.168.3.177',
                'port' : 6203,
                'idRoom': 'P0001'
            },
            {
                'idDoor': 'C0002',
                'nameDoor': 'Cua2',
                'ip': '192.168.3.103',
                'port' : 5563,
                'idRoom': 'P0002'
            }
        ]

        list_card_doors = [
            {
                'id'    : 1,
                'idCard': '5D2A821C',
                'idDoor': 'C0001'
            },
            {
                'id'    : 2,
                'idCard': '6628E6EC',
                'idDoor': 'C0002'
            }
        ]
        message_handler_obj = message_handler.MessageHandler(topic=message_topic.encode(), 
                                                            message=json_message.encode(), 
                                                            list_doors = list_doors,
                                                            list_card_doors = list_card_doors)
       
        try:
            result = message_handler_obj.is_goin_goout(json_message)
            print("\n\nresult go in or go out:", result )
            self.assertTrue(True)
        except:
            self.assertTrue(False)
            
    def test_id_doorcard(self):
        json_dict = {
            "MESSAGE_TYPE" : "CARD_VALUE",
            "data" :
            {
                constants.ATTR_ID_CARD : "5D2A821C",
            },
            "Sender" : 
            {
                constants.ATTR_NAME_IP : "192.168.3.177",

                constants.ATTR_PORT : 6203,
            },
            "dateTime" : 
            {
                constants.ATTR_SEC : 1,
                
                constants.ATTR_MIN : 13,

                constants.ATTR_HOUR : 2,
                constants.ATTR_DAY : 21,
                constants.ATTR_MONTH : 3,
                constants.ATTR_YEAR : 2017,
           }
        }

        json_message = json.dumps(json_dict)
        print("\n\n\n json message test:", json_message)
        message_topic = constants.ATTR_SMART_DOOR_STATUS_VALUE
        list_doors = [
            {
                'idDoor': 'C0001',
                'nameDoor': 'Cua1',
                'ip': '192.168.3.177',
                'port' : 6203,
                'idRoom': 'P0001'
            },
            {
                'idDoor': 'C0002',
                'nameDoor': 'Cua2',
                'ip': '192.168.3.103',
                'port' : 5563,
                'idRoom': 'P0002'
            }
        ]

        list_card_doors = [
            {
                'id'    : 1,
                'idCard': '5D2A821C',
                'idDoor': 'C0001'
            },
            {
                'id'    : 2,
                'idCard': '6628E6EC',
                'idDoor': 'C0002'
            }
        ]
        message_handler_obj = message_handler.MessageHandler(topic=message_topic.encode(), 
                                                            message=json_message.encode(), 
                                                            list_doors = list_doors,
                                                            list_card_doors = list_card_doors)
       
        try:
            result = message_handler_obj.id_doorcard(json_message)
            print("\n\nresult go in or go out:", result )
            self.assertTrue(True)
        except:
            self.assertTrue(False)

if __name__ == '__main__':
    unittest.main()