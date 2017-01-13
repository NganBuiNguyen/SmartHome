"""
File: __cffi_messageSender.py
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

JSON_MESSAGE_SENDER_FOR_C_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 
                            'app', 'messenger', 'messageSender', 'cWrapper'))
JSON_MESSAGE_SENDER_FOR_C_LIBS = ["messageSenderForC"]

#define common libraries
POCO_ROOT = os.getenv('POCO_ROOT')
POCO_INCLUDES = os.path.sep.join((POCO_ROOT, 'include'))
POCO_LIB_DIR = os.path.sep.join((POCO_ROOT, 'lib'))
POCO_LIBS = ["PocoNet", 'PocoNetd', 'stdc++']

messageSender_cffi = cffi.FFI()
messageSender_cffi.cdef("""
    bool sendMessageUDPForC(const char* data, const char* host, unsigned int port);
    bool sendMessageTCPForC(const char* data, const char* host, unsigned int port);
""")

messageSender_c = messageSender_cffi.verify("""

                #include "MessageSenderForC.h"

                """,
                include_dirs = [JSON_MESSAGE_SENDER_FOR_C_INCLUDES,
                                POCO_INCLUDES],
                libraries = JSON_MESSAGE_SENDER_FOR_C_LIBS + POCO_LIBS,
                library_dirs = [LIDT_LIBS, POCO_LIB_DIR],
                modulename = "__cffi_messageSenderForC")
