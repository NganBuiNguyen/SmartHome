import cffi
import os

#LIDT declare
LIDT_ROOT = os.getenv('LIDT_ROOT')
LIDT_LIBS = os.path.sep.join((LIDT_ROOT, 'obj', 'libs'))

JSON_PARSER_FOR_C_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 
                            'app', 'utils', 'jsonHelper', 'cWrapper',
                            'jsonParserWrapper'))
DATA_TYPE_DEF_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 'app', 'dataConverter'))
JSON_PARSER_FOR_C_LIBS = ["jsonParserForC"]

#define common libraries
BOOST_ROOT = os.getenv('BOOST_ROOT')
BOOST_INCLUDES = os.path.sep.join((BOOST_ROOT, 'include'))
BOOST_LIB_DIR = os.path.sep.join((BOOST_ROOT, 'lib'))
BOOST_LIBS = ["boost_serialization", 'boost_thread', 'stdc++']

jsonParser_cffi = cffi.FFI()
jsonParser_cffi.cdef("""
    #define NAME_CARD_PERSON_LENGTH 20
    #define NAME_DOOR_ROOM 10

    typedef struct
    {
        int year ;
        int mon ;
        int day ;
        int sec ;   
        int min ;   
        int hour ;
    }Date_Time;

    typedef struct
    {
        int idPerson;
        char namePerson[NAME_CARD_PERSON_LENGTH];
        int age;
        bool grantPerson;
        int idRoom;
    }Person;

    typedef struct
    {
        char idCard[NAME_CARD_PERSON_LENGTH];
        char typeCard[NAME_CARD_PERSON_LENGTH];
        int idPerson;
    }Card;

    typedef struct
    {
        int idDoor;
        char nameDoor[NAME_DOOR_ROOM]; 
    }Door;

    typedef struct
    {
        int idIP;
        char ip[20];
        long port;
        int idDoor;
    }IP;

    typedef struct
    {
        int idRoom;
        char nameRoom[NAME_DOOR_ROOM];
        int idDoor;
    }Room;

    typedef struct
      {
        Date_Time dateTime;
        Card card;
        Person person;
        Door door;
        Room room;
        IP ip_port;
      }CardInfo;

    bool parseOpenDoorJsonForC(const char* jsonString, CardInfo* info);
""")

jsonParser_c = jsonParser_cffi.verify("""
                #include <stdbool.h>
                #include "JsonParserForC.h"
                """,
                include_dirs = [JSON_PARSER_FOR_C_INCLUDES,
                                DATA_TYPE_DEF_INCLUDES, BOOST_INCLUDES],
                libraries = JSON_PARSER_FOR_C_LIBS + BOOST_LIBS,
                library_dirs = [LIDT_LIBS, BOOST_LIB_DIR],
                modulename = "__cffi_jsonParser")