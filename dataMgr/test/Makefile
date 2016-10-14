E = echo

SRC = Employee.cpp EmployeeTest.cpp

OBJFILES := $(patsubst %.cpp, $(SH_ROOT)/obj/%.o, $(SRC))

TARGET =

COMMONFLAGS = -g -I $(SH_ROOT)=~/Development/gtest-all.o
LDFLAGS =

CXXFLAGS = $(COMMONFLAGS) --std=c++0x

all: $(OBJFILES)

$(SH_ROOT)/obj/%.o: %.cpp
	echo C++-compiling $<
	$(CC) -o $@ -c $< $(CXXFLAGS)

cleanall:
	 $(E) Removing files
	-rm -rf $(SH_ROOT)/obj/*
