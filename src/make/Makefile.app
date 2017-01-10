#-----------------------------------------------------------------------------
# Makefile - make/Makefile.app
# Copyright (c) Tien Nguyen Anh
# Modification history
#    Created: 2016-Dec-03 
#-----------------------------------------------------------------------------

ifndef make_app
make_app = once_only

#-----------------------------------------------------------------------------
include $(LIDT_MAKEDIR)/Makefile.lidt

ifeq ($(APP),unittest)
	ifeq ($(UNITTEST), gtest)
		include $(LIDT_MAKEDIR)/Makefile.gtest
	endif
endif

#-----------------------------------------------------------------------------
# Definition

ifndef OBJ_DIR
	OBJ_DIR = $(APP_OBJ)/
endif

ifndef RUN_TIME
	RUN_TIME = $(LIDT_ROOT)/runtime
endif

ifneq ($(APP),unittest)
EXPLICIT = APP=$(APP)
else
EXPLICIT = APP=$(APP) UNITTEST=$(UNITTEST)
endif

#-----------------------------------------------------------------------------
CFLAGS += -ansi

#-----------------------------------------------------------------------------

CC = gcc

COMMON_FLAGS = -ansi -g -fPIC

ifeq ($(APP),unittest)
	COMMON_FLAGS += -DUNITTEST
endif

INC_FLAGS = -I $(INCS_DIRS)

STRIP = strip
INCS := src/app $(INCS)

INCLUDE_LIBS = 

#-----------------------------------------------------------------------------
include $(LIDT_MAKEDIR)/Makefile.boost

#-----------------------------------------------------------------------------
include $(LIDT_MAKEDIR)/Makefile.poco

#-----------------------------------------------------------------------------
include $(LIDT_MAKEDIR)/Makefile.mysql

#-----------------------------------------------------------------------------
include $(LIDT_MAKEDIR)/Makefile.zmq

#-----------------------------------------------------------------------------
ifeq ($(APP),unittest)
	include $(LIDT_MAKEDIR)/Makefile.gtest
endif

#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------

include $(LIDT_MAKEDIR)/Makefile.rules

endif   # once_only