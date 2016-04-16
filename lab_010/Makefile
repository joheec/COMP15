#
# Makefile for Hashing Lab
#
CXX      = clang++
CXXFLAGS = -O0 -g3 -Wall -Wextra

## If you want to learn more about Makefiles:
##
## A makefile rule has a TARGET, a colon, and a list of PREREQUISITES
## on the first line.  That is followed by 0 or more TAB-indented
## lines that form the RECIPE for building the target from the
## prerequesites. 
##
## make has some built-in variables for very common items.  $@ means
## the name of the target (hectorHash in the rule below).  $^ means
## the whole prerequisite list, (main.o hector.o in the rule below).
##
hectorHash: main.o hector.o
	${CXX} ${CXXFLAGS} -o $@ $^

main.o:    main.cpp hector.h
hector.o:  hector.cpp hector.h

clean:
	rm -rf hectorHash *.o *.dSYM

provide:
	provide comp15 lab10 main.cpp hector.cpp hector.h Makefile
