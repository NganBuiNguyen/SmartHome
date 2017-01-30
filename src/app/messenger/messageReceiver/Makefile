ifneq ($(APP), unittest)
    override APP = messageReceiver
    TARGET = 
    ARCHIVES = messageReceiver
endif

#-----------------------------------------------------------------------------
#Source
SRCS = MessageReceiver.cpp
OBJS = $(SRCS:.cpp=.o)
SUBOBJS += jsonBuilder.o
SUBOBJS += common.o

#------------------------------------------------------------------------------
#include source code
INCS_DIRS = src/app/utils/jsonHelper/common \
			src/app/utils/jsonHelper/jsonBuilder \
			src/app/utils/jsonHelper/jsonParser

#-----------------------------------------------------------------------------
LIBDIRS_jsonCommon  = $(LIDT_ROOT)/src/app/utils/jsonHelper/common/
LIBRARY             += jsonCommon
LIBDIRS_jsonBuilder = $(LIDT_ROOT)/src/app/utils/jsonHelper/jsonBuilder/
LIBRARY             += jsonBuilder

#-----------------------------------------------------------------------------
include $(LIDT_MAKEDIR)/Makefile.app 
