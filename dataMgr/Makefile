CC = g++
E = echo

<<<<<<< HEAD
SRC = Room.cpp Employee.cpp 
=======
SRC =  Person.cpp Status.cpp Card.cpp Room.cpp Door.cpp

>>>>>>> a056a8048d2a9d921065e10494bb092040d5e5d7

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
	
