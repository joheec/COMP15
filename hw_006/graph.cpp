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

	graph = new Node*[cap];
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
	Node * prev = NULL;
	Node * curr;
	for(int i = 0; i < capacity; i++) {
		curr = graph[i];
		while(curr != NULL) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
	}

	delete [] graph;
}

void Graph::insertTaCourse(string ta, string course)
{
	checkLoadFactor();

	uint32_t hashedKey = hash_string(ta) % capacity;
	Node * temp = graph[hashedKey];
	while(temp != NULL) {
		if(temp->ta == ta && temp->course == course) {
			return;
		}
		temp = temp->next;
	}

	Node * newNode = new Node;
	newNode->ta = ta;
	newNode->course = course;
	newNode->student = "";
	newNode->visited = false;
	newNode->next = graph[hashedKey];
	graph[hashedKey] = newNode;

	++size;

}

void Graph::insertStudentCourse(string student, string course)
{
	Node * temp;
	for(int i = 0; i < capacity; i++) {
		temp = graph[i];
		while(temp != NULL) {
			if(temp->course == course) {
				if(temp->student == "") {
					temp->student = student;
				} else {
					insert(temp->ta, student, course);
				}
			}
			temp = temp->next;
		}
	}
}

void Graph::insert(string ta, string student, string course)
{
	if(!entryExists(ta, student, course)) {
		checkLoadFactor();

		uint32_t hashedKey = hash_string(ta) % capacity;
		Node * newNode = new Node;
		newNode->ta = ta;
		newNode->student = student;
		newNode->course = course;
		newNode->visited = false;
		newNode->next = graph[hashedKey];
		graph[hashedKey] = newNode;

		++size;
	}
}

void Graph::removeStudentlessTas()
{
	Node * curr;
	Node * prev = graph[0];
	for(int i = 0; i < capacity; i++) {
		curr = graph[i];
		while(curr != NULL) {
			if(curr->student == "") {
				if(i == 0) {
					graph[i] = curr->next;
					delete curr;
					curr = graph[i];
				} else {
					prev->next = curr->next;
					delete curr;
					curr = prev->next;
				}
			} else {
				prev = curr;
				curr = curr->next;
			}
		}
	}
}

bool Graph::entryExists(string ta, string student, string course)
{
	uint32_t hashedKey = hash_string(ta) % capacity;
	Node * temp = graph[hashedKey];
	while(temp != NULL) {
		if(temp->ta == ta && temp->student == student
				&& temp->course == course) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void Graph::checkLoadFactor()
{
	if(size < 4 * capacity) {
		return;
	}
	int newCap = capacity * 2 + 1;
	Node ** newGraph = new Node*[newCap];
	Node * currNode;
	for(int i = 0; i < capacity; i++) {
		currNode = graph[i];
		while (currNode != NULL) {
			uint32_t key = hash_string(currNode->ta) % newCap;
			Node * newNode = new Node;
			newNode->ta = currNode->ta;
			newNode->student = currNode->student;
			newNode->course = currNode->course;
			newNode->visited = currNode->visited;
			newNode->next = newGraph[key];

			newGraph[key] = newNode;
			currNode = currNode->next;
		}
	}
	deleteGraph();
	graph = newGraph;
	capacity = newCap;
}

void Graph::printGraph()
{
	Node * curr;
	for(int i = 0; i < capacity; i++) {
		curr = graph[i];
		while(curr != NULL) {
			cout << curr->ta <<  " +- " << curr->course << " -> " << curr->student << "\n";
			curr = curr->next;
		}
	}
}

void Graph::printPath(string ta, string student)
{
	resetVisited();
	queue<string> q;
	q.push(ta);
	string path = printPathHelper(student, q);
	size_t check = path.find_last_of("> ");
	if(path.size() - 1 != check) {
		cout << path;
	}
}

string Graph::printPathHelper(string student, queue<string> &q)
{
	if(q.empty()) {
		return "";
	}
	string ta = q.front();
	q.pop();

	uint32_t hashedKey = hash_string(ta) % capacity;
	Node * temp = graph[hashedKey];
	while(temp != NULL) {
		if(!temp->visited && temp->ta == ta) {
			temp->visited = true;
			if(temp->student == student) {
				return ta + " +- " + temp->course + " -> " + student + "\n";
			}
			q.push(temp->student);
			return temp->ta + " +- " + temp->course + " -> " + printPathHelper(student, q);
		}
		temp = temp->next;
	}
	return "";
}

void Graph::resetVisited()
{
	Node * temp;
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
