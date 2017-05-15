import json
import constants
import exceptions
import error_messages

class JsonParser(object):
    def __init__(self):
        pass
            
    def parse_smart_door_history(self, message):
        json_card = json.loads(message)
        print('json message: ', message)
        print('json_card: ', json_card)

    
        try:
            date_time_info = {
                constants.ATTR_SEC : int(json_card[\
                                                constants.ATTR_TIMER][\
                                                constants.ATTR_SEC]),
                constants.ATTR_MIN : int(json_card[\
                                                constants.ATTR_TIMER][\
                                                constants.ATTR_MIN]),
                constants.ATTR_HOUR : int(json_card[\
                                                constants.ATTR_TIMER][\
                                                constants.ATTR_HOUR]),
                constants.ATTR_DAY : int(json_card[\
                                                constants.ATTR_TIMER][\
                                                constants.ATTR_DAY]),
                constants.ATTR_MONTH : int(json_card[\
                                                constants.ATTR_TIMER][\
                                                constants.ATTR_MONTH]),
                constants.ATTR_YEAR : int(json_card[\
                                                constants.ATTR_TIMER][\
                                                constants.ATTR_YEAR]),
            }

            card_info = { 
                constants.ATTR_ID_CARD_INFO : bytes(json_card[\
                                                constants.ATTR_DATA][\
                                                constants.ATTR_ID_CARD], 'utf-8'),

                constants.ATTR_ID_PERSON : b''

            }

            person_info = {

                constants.ATTR_ID_PERSON : b'',

                constants.ATTR_NAME_PERSON : b'',

                constants.ATTR_AGE_PERSON : -1,

                constants.ATTR_GRANT_PERSON : 0,

                constants.ATTR_USER_NAME : b'',

                constants.ATTR_PASS : b''

            }

           
            door_info = {
                constants.ATTR_ID_DOOR : b'',

                constants.ATTR_NAME_DOOR : b'',

                constants.ATTR_NAME_IP : bytes(json_card[\
                                                constants.ATTR_SENDER][\
                                                constants.ATTR_NAME_IP], 'utf-8'),

                constants.ATTR_PORT : int(json_card[\
                                                constants.ATTR_SENDER][\
                                                constants.ATTR_PORT]),
                constants.ATTR_ID_ROOM : b''
            }

            room_info = {
                constants.ATTR_ID_ROOM : b'',

                constants.ATTR_NAME_ROOM : b'',

            }

            # ip_info = {
            #     constants.ATTR_ID_IP : -1,

            #     constants.ATTR_NAME_IP : bytes(json_card[\
            #                                     constants.ATTR_SENDER][\
            #                                     constants.ATTR_NAME_IP], 'utf-8'),

            #     constants.ATTR_PORT : int(json_card[\
            #                                     constants.ATTR_SENDER][\
            #                                     constants.ATTR_PORT]),

            #     constants.ATTR_ID_DOOR : -1,
            # }

            history_info = {
                constants.ATTR_STATUS_DOOR : 0,

                constants.ATTR_CHECK_CARD : 0,

            }

            smart_door_status_info = {
                constants.ATTR_DATE_TIME : date_time_info,
                constants.ATTR_CARD : card_info,
                constants.ATTR_PERSON : person_info,
                constants.ATTR_DOOR : door_info,
                constants.ATTR_ROOM : room_info,
                constants.ATTR_HISTORY : history_info,
                # constants.ATTR_IP : ip_info
            }

            return smart_door_status_info

        except ValueError as ex:
            print("ex: ", ex)
            import traceback
            traceback.print_exc()
            raise exceptions.CardInfoJsonDictionayKeyWordNotFound(\
                error_messages.ERROR_Card_Info_Dictionary_Key_Word_Not_Found)