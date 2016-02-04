#
# Makefile for peanuts5k
#
# At some point, I needed -std=c++11 to get nullptr to be available,
# but now that actually seems to break the compilation.
# If you run into trouble, you can try adding it back or switching
# to g++.
#
CXX      = clang++
CXXFLAGS = -O0 -g3 -Wall -Wextra
# CXXFLAGS = -O0 -g3 -Wall -Wextra -std=c++11

peanuts5k: main.cpp runList.cpp runList.h runner.cpp runner.h
	${CXX} ${CXXFLAGS} -o peanuts5k main.cpp runner.cpp runList.cpp

clean:
	rm -rf peanuts5k *.dSYM *.o

provide:
	provide comp15 lab2 main.cpp runner.cpp runner.h runList.cpp  \
        runList.h Makefile

