
ifneq ($(APP), unittest)
	override APP = dbManager
	TARGET = #none
	ARCHIVES = dbManager
endif

#------------------------------------------------------------------------------
#source
SRCS =DbCard.cpp 
OBJS=$(SRCS:.cpp=.o)


#------------------------------------------------------------------------------
#include source code
INCS_DIRS +=src/app/dataConverter/ 

#------------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app
