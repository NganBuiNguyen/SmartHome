#-----------------------------------------------------------------------------
# Makefile - src/app/messenger/messageReceiver
#
# Copyright (c) Tien Nguyen Anh
#
# Modified History
# ----------------
# 2016-Dec-08 Created Tien Nguyen Anh 
#-----------------------------------------------------------------------------

ifneq ($(APP), unittest)
    override APP = messageSender
    TARGET = 
    ARCHIVES = messageSender
endif

#-----------------------------------------------------------------------------
#Source
SRCS = MessageSender.cpp
OBJS = $(SRCS:.cpp=.o)

#-----------------------------------------------------------------------------
INCS_DIRS += . 

#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
include $(LIDT_MAKEDIR)/Makefile.app 
