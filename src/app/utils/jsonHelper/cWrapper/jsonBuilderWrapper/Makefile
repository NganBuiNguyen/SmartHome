#-----------------------------------------------------------------------------
#Makefile - src/app/utils/jsonHelper/cWrapper/jsonBuilderWrapper
# Copyright (c) Tien Nguyen Anh
# Modification history
# --------------------
#    Created: 2016-Dec-21 tien.nguyenanh94@gmail.com
#-----------------------------------------------------------------------------

ifneq ($(APP), unittest)
    override APP = jsonBuilderForC
    TARGET = #none
    ARCHIVES = jsonBuilderForC
endif

#-----------------------------------------------------------------------------
#source
SRCS = JsonBuilderForC.cpp
OBJS = $(SRCS:.cpp=.o)

#-----------------------------------------------------------------------------
SUBOBJS = 	common.o \
			jsonBuilder.o

#-----------------------------------------------------------------------------
LIBDIRS_jsonCommon  += $(LIDT_ROOT)/src/app/utils/jsonHelper/common/
LIBRARY             += jsonCommon
LIBDIRS_jsonBuilder += $(LIDT_ROOT)/src/app/utils/jsonHelper/jsonBuilder/
LIBRARY             += jsonBuilder

#-----------------------------------------------------------------------------
#include source code
INCS_DIRS += src/app/utils/jsonHelper/common \
			 src/app/utils/jsonHelper/jsonBuilder \
			 src/app/dataManager

#-----------------------------------------------------------------------------
CLEAN_DIRS += 	$(LIDT_ROOT)/src/app/utils/jsonHelper/common \
				$(LIDT_ROOT)/src/app/utils/jsonHelper/jsonBuilder

#-----------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app