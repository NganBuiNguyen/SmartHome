ifneq ($(APP), unittest)
    override APP = messageReceiver
    TARGET = 
    ARCHIVES = messageReceiver
endif

#-----------------------------------------------------------------------------
#Source
SRCS = MessageReceiver.cpp
OBJS = $(SRCS:.cpp=.o)
SUBOBJS += JsonBuilder.o
SUBOBJS += JsonCommon.o
SUBOBJS += Timer.o
#------------------------------------------------------------------------------
#include source code
INCS_DIRS = src/app/utils/jsonHelper/common \
			src/app/utils/jsonHelper/jsonBuilder \
			src/app/utils/jsonHelper/jsonParser \
			src/app/dataConverter \
			src/app/timer

#-----------------------------------------------------------------------------
LIBDIRS_jsonCommon  = $(LIDT_ROOT)/src/app/utils/jsonHelper/common/
LIBRARY             += jsonCommon
LIBDIRS_jsonBuilder = $(LIDT_ROOT)/src/app/utils/jsonHelper/jsonBuilder/
LIBRARY             += jsonBuilder

#-----------------------------------------------------------------------------
include $(LIDT_MAKEDIR)/Makefile.app 
