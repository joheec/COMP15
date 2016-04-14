#include <iostream>
#include <cstdlib>
#include <assert.h>

#include "readInput.h"
#include "test.h"

using namespace std;

int main(int argc, char *argv[])
{
//	assert(argc == 3);
//	readFile(argv[1], "student");
//	readFile(argv[2], "ta");


	(void) argc;
	(void) argv[1];

//	readCommands(cin);

//	test_hashTable_create_delete();
//	test_hashTable_insert_print();
	test_hashTable_loadFactor();

	return 0;
}
