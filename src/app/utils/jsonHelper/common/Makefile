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
SRCS = JsonCommon.cpp
OBJS = $(SRCS:.cpp=.o)

#------------------------------------------------------------------------------
#include source code
INCS_DIRS += src/app/dataManager \
 			src/app/dataManager \
 			src/app/utils/jsonHelper/jsonParser

#------------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app
