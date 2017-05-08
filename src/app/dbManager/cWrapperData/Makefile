ifneq ($(APP), unittest)
    override APP = DbDataForC
    TARGET = #none
    ARCHIVES = DbDataForC
endif

#-----------------------------------------------------------------------------
#source
SRCS = DbCardForC.cpp
OBJS = $(SRCS:.cpp=.o)

#-----------------------------------------------------------------------------
SUBOBJS = DbCard.o DbHistory.o

#-----------------------------------------------------------------------------
LIBDIRS_dbData  += $(LIDT_ROOT)/src/app/dbManager/DbData/
LIBRARY         += dbData

#-----------------------------------------------------------------------------
#include source code
INCS_DIRS += src/app/dbManager/DbData \
			 src/app/dataConverter

#-----------------------------------------------------------------------------
CLEAN_DIRS += $(LIDT_ROOT)/src/app/dbManager/DbData
			

#-----------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app