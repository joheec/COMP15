#
# Makefile for HW6
#
CXX      = clang++
CXXFLAGS = -g -Wall -Wextra
LDFLAGS  = -g

hw6degrees: main.o readInput.o test.o hashTable.o hashfunc.o graph.o
	${CXX} ${CXXFLAGS} -o hw6degrees $^

main.o:	main.cpp readInput.h test.h hashTable.h graph.h
hashfunc.o: hashfunc.cpp hashfunc.h
readInput.o: readInput.cpp readInput.h hashTable.h graph.h
test.o: test.cpp test.h hashTable.h graph.h
hashTable.o: hashTable.cpp hashTable.h hashfunc.h
graph.o: graph.cpp graph.h hashTable.h

clean:
	rm -f hw6degrees *.o *.dSYM

provide:
	provide comp15 hw6 main.cpp Makefile ReadMe.md \
	readInput.cpp readInput.h test.cpp test.h \
	hashfunc.cpp hashfunc.h hashTable.cpp hashTable.h graph.cpp graph.h \
	