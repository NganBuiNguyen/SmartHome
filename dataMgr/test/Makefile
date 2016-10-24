CC = g++
E = echo

SRC = EmployeeTest.cpp Employee.cpp Card.cpp CardTest.cpp Door.cpp DoorTest.cpp Room.cpp RoomTest.cpp Status.cpp StatusTest.cpp

OBJFILES := $(patsubst %.cpp, $(SH_ROOT)/obj/%.o, $(SRC))

TARGET =

COMMONFLAGS = -g -I $(SH_ROOT)/dataMgr -I ~/Development/googletest-1.7.0/include

LDFLAGS = -L ~/Development/googletest-1.7.0/lib -lgtest -lgtest_main -lpthread

CXXFLAGS = $(COMMONFLAGS) --std=c++0x

all: $(OBJFILES)
	 $(CC) $^ -o gtest $(LDFLAGS)

$(SH_ROOT)/obj/%.o: ../%.cpp
	 $(CC) -o $@ -c $< $(CXXFLAGS)

$(SH_ROOT)/obj/%.o: %.cpp

$(SH_ROOT)/obj/%.o: %.cpp
	echo C++-compiling $<
	$(CC) -o $@ -c $< $(CXXFLAGS)

cleanall:
	 $(E) Removing files
	-rm -rf $(SH_ROOT)/obj/*
