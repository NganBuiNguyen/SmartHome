#----------------------------------------------------------------------------
#Makefile - src/app/dataConverter
# Copyright (c) Tien Anh Nguyen
# Modification history
# --------------------
#    Created: 2016-Dec-03 
#-----------------------------------------------------------------------------

ifneq ($(APP), unittest)
	override APP = dataConverter
	TARGET = #none
	ARCHIVES = dataConverter
endif

#------------------------------------------------------------------------------
#source
SRCS =Card.cpp Person.cpp  Room.cpp  Status.cpp Door.cpp 
OBJS = $(SRCS:.cpp=.o)

#------------------------------------------------------------------------------
#include source code
INCS = 

#------------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app
