CC = g++
E = echo

SRC =  Person.cpp Status.cpp Card.cpp Room.cpp Door.cpp

OBJFILES := $(patsubst %.cpp, $(SH_ROOT)/obj/%.o, $(SRC))

TARGET = 

COMMONFLAGS = -g 
LDFLAGS =

CXXFLAGS = $(COMMONFLAGS) --std=c++0x

all: $(OBJFILES)

$(SH_ROOT)/obj/%.o: %.cpp
	echo C++-compiling $<
	$(CC) -o $@ -c $< $(CXXFLAGS)
        
cleanall:
	$(E) Removing files
	-rm -rf $(SH_ROOT)/obj/*
	
