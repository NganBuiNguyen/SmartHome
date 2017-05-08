ifneq ($(APP), unittest)
	override APP = dbData
	TARGET = #none
	ARCHIVES = dbData
endif

#------------------------------------------------------------------------------
#source
SRCS = DbCard.cpp DbHistory.cpp
OBJS=$(SRCS:.cpp=.o)


#------------------------------------------------------------------------------
#include source code
INCS_DIRS += src/app/dataConverter/ \
             

#------------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app
