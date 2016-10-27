CC = g++
E = echo

<<<<<<< HEAD
SRC =  Person.cpp Status.cpp Card.cpp Room.cpp Door.cpp
=======
SRC =  Person.cpp Status.cpp
>>>>>>> 86e6bb73480f4e189c968f34b2f1f716486e68f0

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
	
