
ifneq ($(APP), unittest)
    override APP = messenger
    TARGET = #none
    PROGRAM = messenger
endif

#-----------------------------------------------------------------------------
SRCS = messenger.cpp
OBJS = $(SRCS:.cpp=.o)
SUBOBJS += Timer.o
#-----------------------------------------------------------------------------
USING_LANGUAGE = CPP

#-----------------------------------------------------------------------------
INCS_DIRS += src/app/messenger/messageReceiver \
			 src/app/utils/jsonHelper/common \
			 src/app/utils/jsonHelper/jsonBuilder \
			 src/app/utils/jsonHelper/jsonParser \
			 src/app/dataConverter \
			 src/app/timer

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
