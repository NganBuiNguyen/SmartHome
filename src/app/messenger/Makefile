#-----------------------------------------------------------------------------
# Makefile - src/app/messenger
#
# Copyright (c) Tien Nguyen Anh
#
# Modified History
# ----------------
# 2016-Dec-08 Created tien.nguyenanh94@gmail.com 
#-----------------------------------------------------------------------------

ifneq ($(APP), unittest)
    override APP = messenger
    TARGET = #none
    PROGRAM = messenger
endif

#-----------------------------------------------------------------------------
SRCS = messenger.cpp
OBJS = $(SRCS:.cpp=.o)

#-----------------------------------------------------------------------------
USING_LANGUAGE = CPP

#-----------------------------------------------------------------------------
INCS_DIRS += src/app/messenger/messageReceiver \
			 src/app/utils/jsonHelper/common \
			 src/app/utils/jsonHelper/jsonBuilder

#-----------------------------------------------------------------------------
LIBDIRS_jsonCommon  += $(LIDT_ROOT)/src/app/utils/jsonHelper/common/
LIBRARY             += jsonCommon
LIBDIRS_jsonBuilder += $(LIDT_ROOT)/src/app/utils/jsonHelper/jsonBuilder/
LIBRARY             += jsonBuilder
LIBDIRS_messageReceiver  += $(LIDT_ROOT)/src/app/messenger/messageReceiver
LIBRARY                  += messageReceiver			
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
CLEAN_DIRS += $(LIDT_ROOT)/src/app/messenger/messageReceiver \
              $(LIDT_ROOT)/src/app/messenger/messageSender

#-----------------------------------------------------------------------------
include $(LIDT_MAKEDIR)/Makefile.app 
