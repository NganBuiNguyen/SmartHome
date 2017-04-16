ifneq ($(APP), unittest)
    override APP = jsonParserForC
    TARGET = #none
    ARCHIVES = jsonParserForC
endif

#-----------------------------------------------------------------------------
#source
SRCS = JsonParserForC.cpp
OBJS = $(SRCS:.cpp=.o)

#-----------------------------------------------------------------------------
SUBOBJS = JsonCommon.o \
		JsonParser.o

#-----------------------------------------------------------------------------
LIBDIRS_jsonCommon  += $(LIDT_ROOT)/src/app/utils/jsonHelper/common/
LIBRARY             += jsonCommon
LIBDIRS_jsonParser  += $(LIDT_ROOT)/src/app/utils/jsonHelper/jsonParser/
LIBRARY             += jsonParser

#-----------------------------------------------------------------------------
#include source code
INCS_DIRS += src/app/utils/jsonHelper/common \
			 src/app/utils/jsonHelper/jsonParser \
			 src/app/dataConverter

#-----------------------------------------------------------------------------
CLEAN_DIRS += $(LIDT_ROOT)/src/app/utils/jsonHelper/common \
				$(LIDT_ROOT)/src/app/utils/jsonHelper/jsonParser

#-----------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app
