#
# Makefile for Graph Traversal Lab
#
CXX      = clang++
CXXFLAGS = -g3 -Wall

graphTraversal: main.cpp graph.cpp graph.h
	${CXX} ${CXXFLAGS} -o graphTraversal graph.cpp main.cpp

clean:
	rm -rf graphTraversal *.dSYM *.o

provide:
	provide comp15 lab11 main.cpp graph.cpp graph.h Makefile
