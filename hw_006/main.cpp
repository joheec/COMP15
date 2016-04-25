/*
 * File: main.cpp
 * Name: Johee Chung
 * Due: April 21, 2016
 * Assignment: Homework 6 / Degree of Separation
 * Class: Comp 15
 *
 * A main function that takes inputs from two files
 * and the command line. Input from the command line
 * calls functions to produce information about the
 * file inputs.
 */

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
	HashTable rosterTable;
	HashTable courseTable;
	Graph graph;

	//populate tables and graph
	popStu(argv[1], studentTable, courseTable);
	popStu(argv[2], studentTable, courseTable);
	popGraph(argv[2], graph);
	popRosterGraph(argv[1], rosterTable, graph);

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
			if(studentTable.keyExist(command)) {
				graph.printTaedCourses(command);
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
