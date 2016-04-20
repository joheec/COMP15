/*
 * graph.h
 *
 *  Created on: Apr 18, 2016
 *      Author: johee
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <string>
#include <queue>

#include "hashfunc.h"

using namespace std;

class Graph {
public:
	Graph();
	Graph(int cap);
	~Graph();

	//in insert check ratio of size and capacity
	void insertTaCourse(string ta, string course);
	void insertStudentCourse(string student, string course);
	void insert(string ta, string student, string course);
	bool entryExists(string ta, string student, string course);
	void removeStudentlessTas();
	void printGraph();
	void printPath(string ta, string student);
//	void printSearchResults(string key);



private:
	struct STUDENT {
		string student;
		string course;
		STUDENT * next;
	};
	struct TA {
		string ta;
		STUDENT * students;
		vector<string> courses;
		bool visited;
		TA * next;
	};

	static const int INITIAL_CAPACITY = 10;
	int capacity;
	int size;

	TA ** graph;

	void createGraph(int cap);
	void deleteGraph();
	void checkLoadFactor();
	void resetVisited();
	string printPathHelper(string student, queue<string> &q);
};


#endif /* GRAPH_H_ */
