#-----------------------------------------------------------------------------
#Makefile - src/app/utils/jsonHelper/cWrapper/jsonBuilderWrapper
# Copyright (c) Tien Nguyen Anh
# Modification history
# --------------------
#    Created: 2016-Dec-21 tien.nguyenanh94@gmail.com
#-----------------------------------------------------------------------------

ifneq ($(APP), unittest)
    override APP = messageSenderForC
    TARGET = #none
    ARCHIVES = messageSenderForC
endif

#-----------------------------------------------------------------------------
#source
SRCS = MessageSenderForC.cpp
OBJS = $(SRCS:.cpp=.o)

#-----------------------------------------------------------------------------
SUBOBJS =   MessageSender.o

#-----------------------------------------------------------------------------
LIBDIRS_messageSender  += $(LIDT_ROOT)/src/app/messenger/messageSender
LIBRARY                += messageSender

#-----------------------------------------------------------------------------
#include source code
INCS_DIRS += src/app/messenger/messageSender

#-----------------------------------------------------------------------------
CLEAN_DIRS += $(LIDT_ROOT)/src/app/messenger/messageSender

#-----------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app
