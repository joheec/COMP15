#
# Makefile for hookbook lab (dynamic arrays)
#
CXX      = clang++
CXXFLAGS = -O0 -g3 -Wall -Wextra

hookbook: main.o hookbook.o
	${CXX} ${CXXFLAGS} -o hookbook main.cpp hookbook.cpp

main.o:      main.cpp     hookbook.h
hookbook.o:  hookbook.cpp hookbook.h

clean:
	rm -rf hookbook *.o *.dSYM

provide:
	provide comp15 lab1 main.cpp hookbook.cpp hookbook.h

