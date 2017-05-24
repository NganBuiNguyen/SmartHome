import sys
import os
import json
import unittest


LIDT_ROOT = os.environ['LIDT_ROOT']
sys.path.append(LIDT_ROOT + '/src/app/processor')

import message_handler
import constants

class TestMessageHandlerGoinGooutMethods(unittest.TestCase):

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
        message_handler_obj = message_handler.MessageHandler(topic=message_topic.encode(), 
                                                            message=json_message.encode())
        try:
            result = message_handler_obj.is_goin_goout(json_message)
            print("\n\nresult go in or go out:", result )
            self.assertTrue(True)
        except:
            self.assertTrue(False)

if __name__ == '__main__':
    unittest.main()