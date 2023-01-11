CXX = g++
CXXFLAGS = -g -Wall -Wextra

.PHONY :all
all : program
program : main.cpp main.o
	$(CXX) $(CXXFLAGS) -o program main.cpp main.o
main.o :main.cpp header.h
	$(CXX) $(CXXFLAGS) -c main.cpp
.PHONY: clean
clean:
	rm *.o
	rm program

