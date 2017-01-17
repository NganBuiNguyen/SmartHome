#-----------------------------------------------------------------------------
#Makefile - src/app/utils/jsonHelper/cWrapper/jsonCommonForC
# Copyright (c) Tien Nguyen Anh
# Modification history
# --------------------
#    Created: 2016-Dec-21 tien.nguyenanh94@gmail.com
#-----------------------------------------------------------------------------

ifneq ($(APP), unittest)
    override APP = jsonCommonForC
    TARGET = #none
    ARCHIVES = jsonCommonForC
endif

#------------------------------------------------------------------------------
#source
SRCS = JsonCommonForC.cpp
OBJS = $(SRCS:.cpp=.o)

#------------------------------------------------------------------------------
SUBOBJS = JsonCommon.o

#------------------------------------------------------------------------------
LIBDIRS_jsonCommon  += $(LIDT_ROOT)/src/app/utils/jsonHelper/common/
LIBRARY             += jsonCommon

#-------------------------------------------------------------------------------
#include source code
INCS_DIRS += src/app/utils/jsonHelper/common \
			 src/app/dataManager \
			 src/app/utils/jsonHelper/jsonParser

#-----------------------------------------------------------------------------
CLEAN_DIRS += $(LIDT_ROOT)/src/app/utils/jsonHelper/common \

#------------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app