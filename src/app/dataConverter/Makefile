ifneq ($(APP), unittest)
	override APP = dataConverter
	TARGET = #none
	ARCHIVES = dataConverter
endif

#------------------------------------------------------------------------------
#source
SRCS =Card.cpp  
OBJS = $(SRCS:.cpp=.o)

#------------------------------------------------------------------------------
#include source code
INCS = 

#------------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app
