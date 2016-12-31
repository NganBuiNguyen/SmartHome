ifneq ($(APP), unittest)
    override APP = jsonBuilder
    TARGET = #none                                                                                                                             
    ARCHIVES = jsonBuilder
endif

#------------------------------------------------------------------------------                                                                
#source                                                                                                                                        
SRCS = jsonBuilder.cpp
OBJS = $(SRCS:.cpp=.o)
SUBOBJS = common.o
#-----------------------------------------------------------------------------                                                                 
LIBDIRS_jsonCommon  += $(LIDT_ROOT)/src/app/utils/jsonHelper/common/
LIBRARY             += jsonCommon

#------------------------------------------------------------------------------                                                                
#include source code                                                                                                                           
INCS_DIRS = src/app/utils/jsonHelper/common

#------------------------------------------------------------------------------                                                                
#include makefile                                                                                                                              
include $(LIDT_MAKEDIR)/Makefile.app
