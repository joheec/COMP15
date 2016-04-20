/*
 * graph.cpp
 *
 *  Created on: Apr 18, 2016
 *      Author: johee
 */

#include <iostream>
#include <string>
#include <assert.h>

#include "graph.h"

using namespace std;

//Constructor
Graph::Graph()
{
	createGraph(INITIAL_CAPACITY);
}

//Constructor
Graph::Graph(int cap)
{
	createGraph(cap);
}

void Graph::createGraph(int cap)
{
	size = 0;
	capacity = cap;

	graph = new TA*[cap];
	for(int i = 0; i < cap; i++) {
		graph[i] = NULL;
	}
}

//Destructor
Graph::~Graph()
{
	deleteGraph();
}

void Graph::deleteGraph()
{
	TA * taPrev = NULL;
	TA * taCurr;
	STUDENT * studentPrev = NULL;
	STUDENT * studentCurr;
	for(int i = 0; i < capacity; i++) {
		taCurr = graph[i];
		while(taCurr != NULL) {
			taPrev = taCurr;
			taCurr = taCurr->next;
			studentCurr = taPrev->students;
			while(studentCurr != NULL) {
				studentPrev = studentCurr;
				studentCurr = studentCurr->next;
				delete studentPrev;
			}
			delete taPrev;
		}
	}

	delete [] graph;
}

void Graph::insertTaCourse(string ta, string course)
{
	checkLoadFactor();

	uint32_t hashedKey = hash_string(ta) % capacity;
	TA * temp = graph[hashedKey];
	while(temp != NULL) {
		if(temp->ta == ta) {
			for(size_t i = 0; i < temp->courses.size(); i++) {
				if(temp->courses[i] == course) {
					return;
				}
			}
			temp->courses.push_back(course);
			return;
		}
		temp = temp->next;
	}

	TA * newTa = new TA;
	newTa->ta = ta;
	newTa->students = NULL;
	newTa->courses.push_back(course);
	newTa->visited = false;
	newTa->next = graph[hashedKey];
	graph[hashedKey] = newTa;

	++size;

}

void Graph::insertStudentCourse(string student, string course)
{
	TA * currTa;
	for(int i = 0; i < capacity; i++) {
		currTa = graph[i];
		while(currTa != NULL) {
			for(size_t j = 0; j < currTa->courses.size(); j++) {
				if(currTa->courses[j] == course) {
					STUDENT * newStudent = new STUDENT;
					newStudent->student = student;
					newStudent->course = course;
					newStudent->next = currTa->students;
					currTa->students = newStudent;
				}
			}
			currTa = currTa->next;
		}
	}
}

//void Graph::insert(string ta, string student, string course)
//{
//	if(!entryExists(ta, student, course)) {
//		checkLoadFactor();
//
//		uint32_t hashedKey = hash_string(ta) % capacity;
//		Node * newNode = new Node;
//		newNode->ta = ta;
//		newNode->student = student;
//		newNode->course = course;
//		newNode->visited = false;
//		newNode->next = graph[hashedKey];
//		graph[hashedKey] = newNode;
//
//		++size;
//	}
//}

void Graph::removeStudentlessTas()
{
	TA * currTa;
	TA * prevTa;
	for(int i = 0; i < capacity; i++) {
		while(graph[i] != NULL && graph[i]->students == NULL) {
			currTa = graph[i];
			graph[i] = currTa->next;
			delete currTa;
		}
		currTa = graph[i];
		while(currTa != NULL && currTa->next != NULL) {
			prevTa = currTa;
			currTa = currTa->next;
			if(currTa->students == NULL) {
				prevTa->next = currTa->next;
				delete currTa;
			}
		}
	}
}

//bool Graph::entryExists(string ta, string student, string course)
//{
//	uint32_t hashedKey = hash_string(ta) % capacity;
//	Node * temp = graph[hashedKey];
//	while(temp != NULL) {
//		if(temp->ta == ta && temp->student == student
//				&& temp->course == course) {
//			return true;
//		}
//		temp = temp->next;
//	}
//	return false;
//}

void Graph::checkLoadFactor()
{
	if(size < 4 * capacity) {
		return;
	}
	int newCap = capacity * 2 + 1;
	TA ** newGraph = new TA*[newCap];
	TA * currTa;
	for(int i = 0; i < capacity; i++) {
		currTa = graph[i];
		while (currTa != NULL) {
			TA * newTa = new TA;
			newTa->ta = currTa->ta;
			STUDENT * currStudent = currTa->students;
			while(currStudent != NULL) {
				STUDENT * newStudent = new STUDENT;
				newStudent->student = currStudent->student;
				newStudent->course = currStudent->course;
				newStudent->next = newTa->students;
				newTa->students = newStudent;
				currStudent = currStudent->next;
			}

			newTa->courses = currTa->courses;
			newTa->visited = currTa->visited;
			uint32_t hashedKey = hash_string(currTa->ta) % newCap;
			newTa->next = newGraph[hashedKey];
			newGraph[hashedKey] = newTa;
			currTa = currTa->next;
		}
	}
	deleteGraph();
	graph = newGraph;
	capacity = newCap;
}

void Graph::printPath(string ta, string student)
{
	resetVisited();
	queue<vector<string> > q;
	vector<string> path;
	path.push_back(ta);
	q.push(path);
	while(!q.empty()) {
		path.clear();
		path = q.front();
		string currTa = path[path.size() - 1];
		q.pop();
		uint32_t hashedKey = hash_string(currTa) % capacity;
		TA * graphTa = graph[hashedKey];

		while(graphTa != NULL) {
			if(graphTa->ta == currTa) {
				graphTa->visited = true;
				STUDENT * currStudent = graphTa->students;
				while(currStudent != NULL) {
					if(currStudent->student == student) {
						for(size_t i = 0; i < path.size(); i++) {

							cout << path[i];

						}
						cout << " +- " + currStudent->course + " -> " + student + "\n";
						return;

					}

					vector<string> newPath = path;
					newPath.push_back(" +- " + currStudent->course + " -> ");
					newPath.push_back(currStudent->student);
					q.push(newPath);
					currStudent = currStudent->next;
				}


			}
			graphTa = graphTa->next;
		}
	}

}

//void Graph::printPath(string ta, string student)
//{
//	resetVisited();
//	queue<string> q;
//	q.push(ta);
//	string path = printPathHelper(student, q);
//	size_t check = path.find_last_of("> ");
//	if(path.size() - 1 != check) {
//		cout << path;
//	}
//}
//
//string Graph::printPathHelper(string student, queue<string> &q)
//{
//	if(q.empty()) {
//		return "";
//	}
//	string ta = q.front();
//	q.pop();
//
//	uint32_t hashedKey = hash_string(ta) % capacity;
//	Node * temp = graph[hashedKey];
//	while(temp != NULL) {
//		if(!temp->visited && temp->ta == ta) {
//			temp->visited = true;
//			if(temp->student == student) {
//				return ta + " +- " + temp->course + " -> " + student + "\n";
//			}
//			q.push(temp->student);
//			return temp->ta + " +- " + temp->course + " -> " + printPathHelper(student, q);
//		}
//		temp = temp->next;
//	}
//	return "";
//}

//string Graph::printPathHelper(string student, queue<string> &q)
//{
//	vector<string> paths;
//	if(q.empty()) {
//		return "";
//	}
//	string ta = q.front();
//	q.pop();
//
//	uint32_t hashedKey = hash_string(ta) % capacity;
//	Node * temp = graph[hashedKey];
//	int i = 0;
//	while(temp != NULL) {
//		if(!temp->visited && temp->ta == ta) {
//			temp->visited = true;
//			if(temp->student == student) {
//				paths[i] = paths[i] + ta + " +- " + temp->course + " -> " + student + "\n";
//			}
//			q.push(temp->student);
//			paths[i] = paths[i] + temp->ta + " +- " + temp->course + " -> " + printPathHelper(student, q);
//		}
//		temp = temp->next;
//		i += 1;
//	}
//	return "";
//}

void Graph::resetVisited()
{
	TA * temp;
	for(int i = 0; i < capacity; i++) {
		temp = graph[i];
		while (temp != NULL) {
			temp->visited = false;
			temp = temp->next;
		}
	}
}

//void Graph::printSearchResults(string key)
//{
//	uint32_t hashedKey = hash_string(key) % capacity;
//	Node * curr = graph[hashedKey];
//	while(curr != NULL) {
//		if(curr->key == key) {
//			cout << curr->value1 << "\n";
//		}
//		curr = curr->next;
//	}
//}
//
//void Graph::resetVisited()
//{
//	Node * temp;
//	for(int i = 0; i < capacity; i++) {
//		temp = graph[i];
//		while(temp != NULL) {
//			temp->visited = false;
//			temp = temp->next;
//		}
//	}
//}
