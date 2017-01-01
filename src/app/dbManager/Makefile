#-----------------------------------------------------------------------------
#Makefile - src/app/dataConverter
# Copyright (c) Tien Anh Nguyen
# Modification history
# --------------------
#    Created: 2016-Dec-03 
#-----------------------------------------------------------------------------

ifneq ($(APP), unittest)
	override APP = dbManager
	TARGET = #none
	ARCHIVES = dbManager
endif

#------------------------------------------------------------------------------
#source
<<<<<<< HEAD
SRCS =DbCard.cpp DbRoom.cpp 
OBJS=$(SRCS:.cpp=.o)
=======
SRCS =DbCard.cpp DbRoom.cpp DbStatus.cpp 
OBJS=$(SRCS:.cpp=.o)

>>>>>>> 0e8f4d9bd61e723e6a6f015fd81189d7f731bd2f

#------------------------------------------------------------------------------
#include source code
INCS_DIRS +=/data/SmartHome/src/app/dataConverter/ 

#------------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app
