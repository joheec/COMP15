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
	cerr << "1\n";
	assert(argc == 3);
	cerr << "2\n";
	HashTable studentTable;
	HashTable courseTable;
	HashTable taTable;
	HashTable rosterTable;
	cerr << "3\n";
	Graph graph;

	//populate tables and graph
	cerr << "4\n";
	popStuCour(argv[1], studentTable, courseTable);
	popStuCour(argv[2], studentTable, courseTable);
	cerr << "5\n";
	popTaGraph(argv[1], taTable, graph);
	cerr << "6\n";
	popRosterGraph(argv[2], rosterTable, graph);
	//clean up graph
	cerr << "7\n";
	graph.removeStudentlessTas();
	cerr << "8\n";

	//reading commands
	string startStudent;
	string endStudent;
	string command;
	cin >> command;
	cerr << "9\n";
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
