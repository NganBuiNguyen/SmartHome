import json
import constants

class JsonParser(object):
    def __init__(self):
        pass

    def parse_smart_door_status(self, message):
        json_card = json.loads(message)
        smart_door_info = {
            constants.ATTR_ID_CARD : json_card[\
                                            constants.ATTR_DATA][\
                                            constants.ATTR_ID_CARD],
        }


        timer_info = {
            constants.ATTR_SEC : json_card[\
                                            constants.ATTR_TIMER][\
                                            constants.ATTR_SEC],
            constants.ATTR_MIN : json_card[\
                                            constants.ATTR_TIMER][\
                                            constants.ATTR_MIN],
            constants.ATTR_HOUR : json_card[\
                                            constants.ATTR_TIMER][\
                                            constants.ATTR_HOUR],
            constants.ATTR_DAY : json_card[\
                                            constants.ATTR_TIMER][\
                                            constants.ATTR_DAY],
            constants.ATTR_MONTH : json_card[\
                                            constants.ATTR_TIMER][\
                                            constants.ATTR_MONTH],
            constants.ATTR_YEAR : json_card[\
                                            constants.ATTR_TIMER][\
                                            constants.ATTR_YEAR],
        }

        sender_info = {
            constants.ATTR_IP : json_card[\
                                        constants.ATTR_SENDER][\
                                        constants.ATTR_IP],
            constants.ATTR_PORT : json_card[\
                                        constants.ATTR_SENDER][\
                                        constants.ATTR_PORT]
        }


        smart_door_status_info = {
            constants.ATTR_SENDER : sender_info,
            constants.ATTR_TIMER : timer_info,
            constants.ATTR_DATA : smart_door_info
        }