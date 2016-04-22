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

	void insertTaCourse(string ta, string course);
	void insertStudentCourse(string student, string course);
	void removeStudentlessTas();
	void printShortestPath(string ta, string student);
	void printAllPaths(string ta, string student);



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
	void deleteTaStudents(TA * taNode);
	void checkLoadFactor();
	void resetVisited();
	string printPathHelper(string student, queue<string> &q);
	vector<string> printAllPathsHelper(string ta, string student,
			vector<string> &path);

};


#endif /* GRAPH_H_ */
