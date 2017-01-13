"""
File: __cffi_jsonCommon.py
=========================

Copyright (c) Tien Nguyen Anh

Modified History
----------------
2017-Jan-05 Created tien.nguyenanh94@gmail.com
"""

import cffi
import os

#LIDT declare
LIDT_ROOT = os.getenv('LIDT_ROOT')
LIDT_LIBS = os.path.sep.join((LIDT_ROOT, 'obj', 'libs'))

JSON_PARSER_FOR_C_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 
                            'app', 'utils', 'jsonHelper', 'cWrapper',
                            'jsonParserWrapper'))
DATA_TYPE_DEF_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 
                            'app', 'dataManager'))
JSON_PARSER_FOR_C_LIBS = ["jsonParserForC"]

#define common libraries
BOOST_ROOT = os.getenv('BOOST_ROOT')
BOOST_INCLUDES = os.path.sep.join((BOOST_ROOT, 'include'))
BOOST_LIB_DIR = os.path.sep.join((BOOST_ROOT, 'lib'))
BOOST_LIBS = ["boost_serialization", 'boost_thread', 'stdc++']

jsonParser_cffi = cffi.FFI()
jsonParser_cffi.cdef("""
    typedef struct
    {
        char ip[20];
        long port;
    }Sender;

    typedef struct
    {
        long lightIntensity;
    }LightIntensity;

    typedef struct
    {
        LightIntensity data;
        Sender sender;

    }LightIntensityInfo;

    bool parseLightInteJsonForC(const char* jsonString, LightIntensityInfo* info);
""")

jsonParser_c = jsonParser_cffi.verify("""

                #include "JsonParserForC.h"

                """,
                include_dirs = [JSON_PARSER_FOR_C_INCLUDES,
                                DATA_TYPE_DEF_INCLUDES, BOOST_INCLUDES],
                libraries = JSON_PARSER_FOR_C_LIBS + BOOST_LIBS,
                library_dirs = [LIDT_LIBS, BOOST_LIB_DIR],
                modulename = "__cffi_jsonParser")
