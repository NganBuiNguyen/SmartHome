import cffi
import os

#LIDT declare
LIDT_ROOT = os.getenv('LIDT_ROOT')
LIDT_LIBS = os.path.sep.join((LIDT_ROOT, 'obj', 'libs'))

#include JsonCommon and DataDef
DATA_DEF_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 'app', 'dataManager'))
JSONCOMMON_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 'app', 'utils',
                                'jsonHelper', 'common'))
JSON_COMMON_FOR_C_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 'app',
                                'utils', 'jsonHelper', 'cWrapper',
                                'jsonCommonWrapper'))

JSON_COMMON_LIBS = ["jsonCommonForC"]

#define common libraries
BOOST_ROOT = os.getenv('BOOST_ROOT')
BOOST_INCLUDES = os.path.sep.join((BOOST_ROOT, 'include'))
BOOST_LIB_DIR = os.path.sep.join((BOOST_ROOT, 'lib'))
BOOST_LIBS = ["boost_serialization", 'boost_thread', 'stdc++']

jsonCommon_cffi = cffi.FFI()
jsonCommon_cffi.cdef("""


    #define SENSOR_MESSAGE_SPLITTER ...
    #define IP_MESSAGE_SPLITTER ...
    #define JSON_PATH_SPLITTER ...

    #define MAX_SENSOR_MESSAGE_LENGTH 50
    #define IP_PORT_TOKEN_SIZE 2
    #define CARD_MESSAGE ...
    #define ATTR_JSON_DATA ...
    #define ATTR_JSON_MESSAGE_TYPE ....
    #define ATTR_JSON_CARD_OPEN ...
    #define CARD_TOPIC ...
    #define ATTR_JSON_CARD_ID ...
    #define ATTR_JSON_CARD_IP ...
    #define ATTR_JSON_CARD_PORT ...
    #define ATTR_JSON_SENDER ...

    typedef enum
    {
        MESSAGE_TYPE_DEFAULT = -1,
        MESSAGE_TYPE_CARD,
    }MESSAGE_TYPE;

    void getJSONMessageTypeForC(const char* message, MESSAGE_TYPE* messageType);
    bool convertMessageTypeToStrForC(const MESSAGE_TYPE* messageType, char** messageTypeStr);
    bool isSensorMessageForC(const char* message);
""")

jsonCommon_c = jsonCommon_cffi.verify("""
                #include "DataDef.h"
                #include "jsonCommonForC.h"
                """,
                include_dirs = [JSON_COMMON_FOR_C_INCLUDES,
                                DATA_DEF_INCLUDES, BOOST_INCLUDES],
                libraries = JSON_COMMON_LIBS + BOOST_LIBS,
                library_dirs = [LIDT_LIBS, BOOST_LIB_DIR],
                modulename = "__cffi_jsonCommon")
import cffi
import os

#LIDT declare
LIDT_ROOT = os.getenv('LIDT_ROOT')
LIDT_LIBS = os.path.sep.join((LIDT_ROOT, 'obj', 'libs'))

#include JsonCommon and DataDef
DATA_DEF_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 'app', 'dataManager'))
JSONCOMMON_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 'app', 'utils',
                                'jsonHelper', 'common'))
JSON_COMMON_FOR_C_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 'app',
                                'utils', 'jsonHelper', 'cWrapper',
                                'jsonCommonWrapper'))

JSON_COMMON_LIBS = ["jsonCommonForC"]

#define common libraries
BOOST_ROOT = os.getenv('BOOST_ROOT')
BOOST_INCLUDES = os.path.sep.join((BOOST_ROOT, 'include'))
BOOST_LIB_DIR = os.path.sep.join((BOOST_ROOT, 'lib'))
BOOST_LIBS = ["boost_serialization", 'boost_thread', 'stdc++']

jsonCommon_cffi = cffi.FFI()
jsonCommon_cffi.cdef("""


    #define SENSOR_MESSAGE_SPLITTER ...
    #define IP_MESSAGE_SPLITTER ...
    #define JSON_PATH_SPLITTER ...

    #define MAX_SENSOR_MESSAGE_LENGTH 50
    #define IP_PORT_TOKEN_SIZE 2
    #define CARD_MESSAGE ...
    #define ATTR_JSON_DATA ...
    #define ATTR_JSON_MESSAGE_TYPE ....
    #define ATTR_JSON_CARD_OPEN ...
    #define CARD_TOPIC ...
    #define ATTR_JSON_CARD_ID ...
    #define ATTR_JSON_CARD_IP ...
    #define ATTR_JSON_CARD_PORT ...
    #define ATTR_JSON_SENDER ...

    typedef enum
    {
        MESSAGE_TYPE_DEFAULT = -1,
        MESSAGE_TYPE_CARD,
    }MESSAGE_TYPE;

    void getJSONMessageTypeForC(const char* message, MESSAGE_TYPE* messageType);
    bool convertMessageTypeToStrForC(const MESSAGE_TYPE* messageType, char** messageTypeStr);
    bool isSensorMessageForC(const char* message);
""")

jsonCommon_c = jsonCommon_cffi.verify("""
                #include "DataDef.h"
                #include "jsonCommonForC.h"
                """,
                include_dirs = [JSON_COMMON_FOR_C_INCLUDES,
                                DATA_DEF_INCLUDES, BOOST_INCLUDES],
                libraries = JSON_COMMON_LIBS + BOOST_LIBS,
                library_dirs = [LIDT_LIBS, BOOST_LIB_DIR],
                modulename = "__cffi_jsonCommon")
