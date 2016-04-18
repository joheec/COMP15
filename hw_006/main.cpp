#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <string>

#include "readInput.h"
#include "hashTable.h"
#include "test.h"

using namespace std;

int main(int argc, char *argv[])
{
	assert(argc == 3);

	HashTable studentTable;
	HashTable courseTable;
	HashTable taTable;
	HashTable rosterTable;

	popStuCour(argv[1], studentTable, courseTable);
	popStuCour(argv[2], studentTable, courseTable);
	popTa(argv[1], taTable);
	popRoster(argv[2], rosterTable);

	//reading commands
	string command;
	cin >> command;
	while(!cin.fail()) {
		if(command == "quit") {
			return 0;
		} else if(command == "ls") {
			studentTable.printTable();
		} else if (command == "lc") {
			courseTable.printTable();
		} else if (command == "taed") {
			cin >> command;
			taTable.printSearchResults(command);
		} else if (command == "roster") {
			cin >> command;
			rosterTable.printSearchResults(command);
		}else {
			cerr << "Unrecognized command.\n";
		}
		cin >> command;
	}

//	test_hashTable_create_delete();
//	test_hashTable_insert_print();
//	test_hashTable_loadFactor();

	return 0;
}
