#include <iostream>
#include <cstdlib>
#include <assert.h>

#include "readInput.h"
#include "test.h"

using namespace std;

int main(int argc, char *argv[])
{
	assert(argc == 3);
	readFile(argv[1], "student");
	readFile(argv[2], "ta");

//	readCommands(cin);

//	test_hashTable_create_delete();
	test_hashTable_insert_print();
	return 0;
}
