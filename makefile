CXX_FLAG = --std=c++11 -g -Wall

all: intbst.o testbst.o
	g++ $(CXX_FLAG) -o all intbst.o testbst.o
intbst.o: intbst.cpp intbst.h
	g++ $(CXX_FLAG) -c intbst.cpp
testbst.o: testbst.cpp intbst.h
	g++ $(CXX_FLAG) -c testbst.cpp
clean: 
	rm -f all intbst.o tesbst.o *.o