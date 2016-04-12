#include <iostream>
#include <cstdlib>

#include "readInput.h"

using namespace std;

int main(int argc, char *argv[])
{
	readFile(argv[1], "student");
	readFile(argv[2], "ta");

	readCommands(cin);

	return 0;
}
