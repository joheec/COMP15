#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <string>

#include "readInput.h"
#include "hashTable.h"
#include "graph.h"
#include "test.h"

using namespace std;

int main(int argc, char *argv[])
{
	assert(argc == 3);

//	HashTable studentTable;
//	HashTable courseTable;
	HashTable taTable;
	HashTable rosterTable;
	Graph graph;

//	popStuCour(argv[1], studentTable, courseTable);
//	popStuCour(argv[2], studentTable, courseTable);
	popTa(argv[1], taTable, graph);
	popRoster(argv[2], rosterTable, graph);
	graph.removeStudentlessTas();
	graph.printGraph();
	graph.printPath("Johee.Chung", "Johee.Chung");
	graph.printPath("Meryl.Streep", "Kevin.Bacon");
	graph.printPath("Brad.Pitt", "Meryl.Streep");
	graph.printPath("Jennifer.Lawrence", "Jennifer.Lawrence");
	graph.printPath("George.Clooney", "Tom.Cruise");

	//reading commands
//	string command;
//	cin >> command;
//	while(!cin.fail()) {
//		if(command == "quit") {
//			return 0;
//		} else if(command == "ls") {
//			studentTable.printTable();
//		} else if (command == "lc") {
//			courseTable.printTable();
//		} else if (command == "taed") {
//			cin >> command;
//			taTable.printSearchResults(command);
//		} else if (command == "roster") {
//			cin >> command;
//			rosterTable.printSearchResults(command);
//		}else {
//			cerr << "Unrecognized command.\n";
//		}
//		cin >> command;
//	}

//	test_hashTable_create_delete();
//	test_hashTable_insert_print();
//	test_hashTable_loadFactor();
//	test_graph_insertTa();

	return 0;
}
