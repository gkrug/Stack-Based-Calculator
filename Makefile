CXX=g++
CC=gcc
CXXFLAGS=-std=c++11

all: calc

calc: calc.cpp myStack.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf calc *.o *~

