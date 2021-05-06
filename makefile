CXX_FLAG = --std=c++11 -g -Wall

all: intbst.o testbst.o test_intbst.o
	g++ $(CXX_FLAG) -o all intbst.o testbst.o
testbst: intbst.o testbst.o
	g++ $(CXX_FLAG) -o testbst intbst.o testbst.o
int_testbst: intbst.o testbst.o
	g++ $(CXX_FLAG) -o test_intbst intbst.o test_intbst.o	
intbst.o: intbst.cpp intbst.h
	g++ $(CXX_FLAG) -c intbst.cpp
testbst.o: testbst.cpp intbst.h
	g++ $(CXX_FLAG) -c testbst.cpp
test_intbst.o: test_intbst.cpp intbst.h
	g++ $(CXX_FLAG) -c test_intbst.cpp
clean: 
	rm -f all intbst.o tesbst.o *.o