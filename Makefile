CXX = g++ --coverage -std=gnu++11 -Wall
CXXFLAGS = -g -L/usr/local/lib -lgtest_main -lgtest -lpthread
FLAGS = --capture --directory ./ --output-file coverage.info
REFLAGS = -r coverage.info '/usr/include/c++/*' '/usr/include/c++/5/*' \
'/usr/local/include/*' '/usr/local/include/gtest/*' -o coverage.info
OUTPUT = genhtml coverage.info --output-directory out
INCS = -I../
OBJS = testSort.o

all:	testAll lcov

testAll:	$(OBJS) 
	$(CXX) $(INCS) -o testAll testSort.cpp $(CXXFLAGS)
	./testAll 
lcov:
	lcov $(FLAGS)
	lcov $(REFLAGS)
	$(OUTPUT)

.cpp.o:	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:	
	rm testAll *.o *.gcda *.gcno *.info 
	rm -rf out