#
# Makefile for maze solver
#
# Using C++11 for nullptr
#
CXX      = clang++
CXXFLAGS = -g -Wall -Wextra -std=c++11
LDFLAGS  = -g

mazeSolver: main.o maze.o stack.o
	${CXX} ${CXXFLAGS} -o mazeSolver main.o maze.o stack.o

# Because of our general "how to make a .o file" rule below, 
# we can just list the dependencies here.
# Notice what depends on what.
main.o:   main.cpp maze.h
maze.o:   maze.cpp maze.h stack.h
stack.o:  stack.cpp stack.h

# The following rule is very general:
# it means "if you need a .o file (%.o) and you have a .cpp file 
# with the same base name (%.cpp), then you make the .o file by
# compiling with that .cpp file with the flags defined above."  
# $@ means "the target you're trying to make"
# $< means "the first prerequisite"
%.o:  %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

clean:
	rm -f mazeSolver *.o

provide:
	provide comp15 lab3 main.cpp maze.cpp maze.h stack.cpp stack.h Makefile
