#
# Makefile for ImageEngine
#
CXX      = clang++
CXXFLAGS = -Wall -Wextra -Wreturn-type -g

imageengine: main.cpp ImageEngine.h ImageEngine.cpp
	${CXX} ${CXXFLAGS} -o ImageEngine main.cpp ImageEngine.cpp

clean:
	rm -rf ImageEngine *.dSYM

provide:
	provide comp15 lab8 main.cpp ImageEngine.cpp ImageEngine.h Makefile
