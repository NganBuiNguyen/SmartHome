#-----------------------------------------------------------------------------
#Makefile - src/app/utils/jsonHelper/common/Makefile
# Copyright (c) Tien Nguyen Anh
# Modification history
# --------------------
#    Created: 2016-Dec-21 tien.nguyenanh94@gmail.com
#-----------------------------------------------------------------------------

ifneq ($(APP), unittest)
    override APP = jsonCommon
    TARGET = #none
    ARCHIVES = jsonCommon
endif

#------------------------------------------------------------------------------
#source
SRCS = common.cpp
OBJS = $(SRCS:.cpp=.o)

#------------------------------------------------------------------------------
#include source code
INCS = .

#------------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app
