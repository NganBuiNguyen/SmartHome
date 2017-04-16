ifneq ($(APP), unittest)
	override APP = timer
	TARGET = #none
	ARCHIVES = timer
endif

#------------------------------------------------------------------------------
#source
SRCS =Timer.cpp 
OBJS=$(SRCS:.cpp=.o)


#------------------------------------------------------------------------------
#include source code
# INCS_DIRS = .

#------------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app 