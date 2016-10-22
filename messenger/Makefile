CC  = g++

SRC = 	main.cpp\
		MsgIn.cpp\
		MsgInConnection.cpp\
		MsgInConnectionFactory.cpp\
		
OBJFILES := $(patsubst %.cpp, %.o, $(SRC))

TARGET      =
LIB_INC     = 	-I /development/poco-1.7.5-all/include/
LIB_DIRS    = 	-L /development/poco-1.7.5-all/lib
LIBRARY     = 	-lPocoNet \
				-lPocoNetd \
				-lPocoData \
				-lPocoDatad \
				-lPocoFoundation \
				-lPocoFoundationd \
				-lPocoUtil \
				-lPocoUtild \
				-lPocoXML\
				-lPocoXMLd\
				-lPocoJSON\
				-lPocoJSONd

COMMONFLAGS = -g --std=c++11
LDFLAGS     =

all: MsgIn 

MsgIn: $(OBJFILES)
	$(CC) $(OBJFILES) $(LIB_INC) $(LIB_DIRS) $(LIBRARY) $(COMMONFLAGS) -o $@
	
%.o: %.cpp
	@echo C++ compiling $<
	$(CC) -c $(LIB_INC) $(LIB_DIRS) $(LIBRARY) $(COMMONFLAGS) $< -o $@
        
cleanall:
	$(E) Removing files
	@rm -rf *.o