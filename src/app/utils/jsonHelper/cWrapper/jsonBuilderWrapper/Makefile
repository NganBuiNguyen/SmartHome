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
SUBOBJS = 	JsonCommon.o \
			JsonBuilder.o

#-----------------------------------------------------------------------------
LIBDIRS_jsonCommon  += $(LIDT_ROOT)/src/app/utils/jsonHelper/common/
LIBRARY             += jsonCommon
LIBDIRS_jsonBuilder += $(LIDT_ROOT)/src/app/utils/jsonHelper/jsonBuilder/
LIBRARY             += jsonBuilder

#-----------------------------------------------------------------------------
#include source code
INCS_DIRS += src/app/utils/jsonHelper/common \
			 src/app/utils/jsonHelper/jsonBuilder \
			 src/app/dataManager \
			 src/app/dataConverter

#-----------------------------------------------------------------------------
CLEAN_DIRS += 	$(LIDT_ROOT)/src/app/utils/jsonHelper/common \
				$(LIDT_ROOT)/src/app/utils/jsonHelper/jsonBuilder

#-----------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app