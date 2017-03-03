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
INCS_DIRS += src/app/dataConverter

#------------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app
