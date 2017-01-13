#-----------------------------------------------------------------------------
# Makefile - src/app/processor/cffi_interfaces
#
# Copyright (c) Tien Nguyen Anh
#
# Modified History
# ----------------
# 2017-Jan-05 Created tien.nguyenanh94@gmail.com 
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
#cffi targets
CFFI_SRCS = __cffi_jsonCommon.py \
			__cffi_jsonBuilder.py \
			__cffi_jsonParser.py \
			__cffi_messageSender.py

CFFI_OBJS = $(CFFI_SRCS:.py=.pyc)

#-----------------------------------------------------------------------------
LIBDIRS_jsonCommonForC  += $(LIDT_ROOT)/src/app/utils/jsonHelper/cWrapper/jsonCommonWrapper
LIBRARY                 += jsonCommonForC
LIBDIRS_jsonParserForC  += $(LIDT_ROOT)/src/app/utils/jsonHelper/cWrapper/jsonParserWrapper
LIBRARY                 += jsonParserForC
LIBDIRS_jsonBuilderForC += $(LIDT_ROOT)/src/app/utils/jsonHelper/cWrapper/jsonBuilderWrapper
LIBRARY                 += jsonBuilderForC
LIBDIRS_messageSenderForC   += $(LIDT_ROOT)/src/app/messenger/messageSender/cWrapper
LIBRARY                 += messageSenderForC

#-----------------------------------------------------------------------------
CLEAN_DIRS += $(LIDT_ROOT)/src/app/messenger/messageSender/cWrapper
CLEAN_DIRS += $(LIDT_ROOT)/src/app/utils/jsonHelper/cWrapper/jsonCommonWrapper
CLEAN_DIRS += $(LIDT_ROOT)//src/app/utils/jsonHelper/cWrapper/jsonParserWrapper
CLEAN_DIRS += $(LIDT_ROOT)/src/app/utils/jsonHelper/cWrapper/jsonBuilderWrapper

#-----------------------------------------------------------------------------
include $(LIDT_MAKEDIR)/Makefile.app 