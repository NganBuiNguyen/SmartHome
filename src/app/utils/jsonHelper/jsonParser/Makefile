ifneq ($(APP), unittest)
    override APP = jsonParser
    TARGET = #none
    ARCHIVES = jsonParser
endif

#------------------------------------------------------------------------------
#source
SRCS = JsonParser.cpp
OBJS = $(SRCS:.cpp=.o)
SUBOBJS = JsonCommon.o

#-----------------------------------------------------------------------------
LIBDIRS_jsonCommon  += $(LIDT_ROOT)/src/app/utils/jsonHelper/common/
LIBRARY             += jsonCommon

#------------------------------------------------------------------------------
#include source code
INCS_DIRS += src/app/utils/jsonHelper/common \
			src/app/dataConverter \
 			src/app/utils/jsonHelper/jsonParser

#------------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app