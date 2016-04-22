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
	HashTable studentTable;
	HashTable courseTable;
	HashTable taTable;
	HashTable rosterTable;
	Graph graph;

	//populate tables and graph
	popStuCour(argv[1], studentTable, courseTable);
	popStuCour(argv[2], studentTable, courseTable);
	popTaGraph(argv[1], taTable, graph);
	popRosterGraph(argv[2], rosterTable, graph);
	//clean up graph
	graph.removeStudentlessTas();

	//reading commands
	string startStudent;
	string endStudent;
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
			if(taTable.keyExist(command)) {
				taTable.printSearchResults(command);
			} else {
				cout << "Student not found\n";
			}
		} else if (command == "roster") {
			cin >> command;
			if(rosterTable.keyExist(command)) {
				rosterTable.printSearchResults(command);
			} else {
				cout << "Course not found\n";
			}
		} else if (command == "paths") {
			cin >> startStudent;
			cin >> endStudent;
			if(studentTable.keyExist(startStudent) &&
					studentTable.keyExist(endStudent)) {
				graph.printAllPaths(startStudent, endStudent);
			} else {
				cout << "Student not found\n";
			}
		} else if (command == "shortestpath") {
			cin >> startStudent;
			cin >> endStudent;
			if(studentTable.keyExist(startStudent) &&
					studentTable.keyExist(endStudent)) {
				graph.printShortestPath(startStudent,
						endStudent);
			} else {
				cout << "Student not found\n";
			}
		}

		cin >> command;
	}

//	test_hashTable_create_delete();
//	test_hashTable_insert_print();
//	test_hashTable_loadFactor();
//	test_graph_insertTa();

	return 0;
}
