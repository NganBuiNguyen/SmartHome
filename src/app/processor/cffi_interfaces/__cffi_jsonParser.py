import cffi
import os



#LIDT declare
LIDT_ROOT = os.getenv('LIDT_ROOT')
LIDT_LIBS = os.path.sep.join((LIDT_ROOT, 'obj', 'libs'))

JSON_PARSER_FOR_C_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 
                            'app', 'utils', 'jsonHelper', 'cWrapper',
                            'jsonParserWrapper'))
DATA_TYPE_DEF_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 'app', 'utils',
                                        'jsonHelper','jsonParser'))
JSON_PARSER_FOR_C_LIBS = ["jsonParserForC"]

#define common libraries
BOOST_ROOT = os.getenv('BOOST_ROOT')
BOOST_INCLUDES = os.path.sep.join((BOOST_ROOT, 'include'))
BOOST_LIB_DIR = os.path.sep.join((BOOST_ROOT, 'lib'))
BOOST_LIBS = ["boost_serialization", 'boost_thread', 'stdc++']

jsonParser_cffi = cffi.FFI()
jsonParser_cffi.cdef("""
    #define IP_PORT_DATE_TIME_SIZE 20
    #define ID_CARD_SIZE 25

    typedef struct
    {
        char ip[IP_PORT_DATE_TIME_SIZE];
        long port;
    }Sender;

    typedef struct
    {
        char cardID[ID_CARD_SIZE];
    }OpenDoor;

    typedef struct
    {
        char date[IP_PORT_DATE_TIME_SIZE];
        char time[IP_PORT_DATE_TIME_SIZE];
    }Timer;

    typedef struct
    {
        OpenDoor data;
        Sender sender;
        Timer timer;
    }CardInfo;

    
    bool parseOpenDoorJsonForC(const char* jsonString, CardInfo* info);
""")

jsonParser_c = jsonParser_cffi.verify("""
                #include "JsonParserForC.h"
                """,
                include_dirs = [JSON_PARSER_FOR_C_INCLUDES,
                                DATA_TYPE_DEF_INCLUDES, BOOST_INCLUDES],
                libraries = JSON_PARSER_FOR_C_LIBS + BOOST_LIBS,
                library_dirs = [LIDT_LIBS, BOOST_LIB_DIR],
                modulename = "__cffi_jsonParser")