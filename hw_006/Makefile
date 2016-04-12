#
# Makefile for HW6
#
CXX      = clang++
CXXFLAGS = -g -Wall -Wextra
LDFLAGS  = -g

hw6degrees: main.o readInput.o
	${CXX} ${CXXFLAGS} -o hw6degrees $^

main.o:	main.cpp readInput.h
readInput.o: readInput.cpp

clean:
	rm -f hw6degrees *.o *.dSYM

provide:
	provide comp15 hw6 main.cpp Makefile ReadMe.md \
	readInput.cpp readInput.h