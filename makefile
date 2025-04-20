# orel8155@gmail.com
# Makefile for SquareMat matrix operations library

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

# Declare phony targets (targets that don't represent files)
.PHONY: all clean Main test valgrind

# Default target: build Main and run tests
all: Main test

# Main program: compile and run the demonstration program
Main: main.o squaremat.o
	$(CXX) $(CXXFLAGS) -o Main main.o squaremat.o
	./Main

# Compile main.cpp
main.o: main.cpp squaremat.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Unit tests: compile and run the test suite
test: Test
	./Test

# Compile the test executable
Test: Test.o squaremat.o
	$(CXX) $(CXXFLAGS) -o Test Test.o squaremat.o

# Compile the test source file
Test.o: Test.cpp squaremat.hpp doctest.h
	$(CXX) $(CXXFLAGS) -c Test.cpp

# Compile the SquareMat implementation
squaremat.o: squaremat.cpp squaremat.hpp
	$(CXX) $(CXXFLAGS) -c squaremat.cpp

# Memory leak check: run Main with Valgrind
valgrind: main.o squaremat.o
	$(CXX) $(CXXFLAGS) -o Main main.o squaremat.o
	$(VALGRIND) ./Main

# Clean up compiled files
clean:
	rm -f *.o Main Test