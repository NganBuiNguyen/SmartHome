CC = g++
E = echo

SRC = DbPerson.cpp TestDbPerson.cpp  Person.cpp DbCard.cpp TestDbCard.cpp Card.cpp DbStatus.cpp TestDbStatus.cpp Status.cpp


OBJFILES := $(patsubst %.cpp, %.o, $(SRC))

TARGET = gtest.bin
 
INCS = -I $(SH_ROOT)/dataDatabaseTest\
	 -I $(SH_ROOT)/dataMgr

LIBRARY_INC = 	 -I /development/googletest-1.7.0/include\
		 -I /development/mysql-connector-c++/include\
		 -I /development/boost_1_62_0/include\
		 -I /development/poco-1.7.5-all/include

LIBRARY_DIRS = 	-L /development/googletest-1.7.0/lib\
		-L /development/mysql-connector-c++/lib\
		-L /development/boost_1_62_0/lib\
		-L /development/poco-1.7.5-all/lib\
		-L /data/SmartHome/dataMgr 

LDFLAGS = -lgtest -lgtest_main -lpthread -lmysqlcppconn -lPocoData 

COMMONFLAGS = -g -std=c++11 

ut: $(TARGET)
	./gtest

$(TARGET): $(OBJFILES) 
	$(CC) $^ -o gtest $(LDFLAGS) $(LIBRARY_DIRS) 

%.o: ../%.cpp %.h 
	$(CC) -c $< $(INCS) -o $@

%.o: $(SH_ROOT)/dataMgr/%.cpp 
	$(CC) -c $< $(INCS) $(LIBRARY_INC) -o $@

%.o: %.cpp 
	echo C++-compiling $<
	$(CC) -c $< $(INCS) $(LIBRARY_INC) -o $@
        
cleanall:
	$(E) Removing files
	-rm -rf $(SH_ROOT)/*
