/*
 * File graph.h
 * Name: Johee Chung
 * Due: April 21, 2016
 * Assignment: Homework 6 / Degrees of Separation
 * Class: Comp 15
 *
 * A graph adjacency list with functions to populate the graph,
 * increase the capacity of the graph, and display information
 * about the graph. Such information includes the shortest
 * path between two students and all the paths between
 * two students.
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
	void printAllPathsHelper(string ta, string student,
			vector<string> path);

};


#endif /* GRAPH_H_ */
