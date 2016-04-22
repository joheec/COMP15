/*
 * File graph.cpp
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

//Constructor with initial capacity
Graph::Graph(int cap)
{
	createGraph(cap);
}

/*
 * Creates a graph
 *
 * @parameter	int cap - Initial capacity of graph
 * @return	void
 */
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

/*
 * Deletes a graph
 *
 * @parameter	void
 * @return	void
 */
void Graph::deleteGraph()
{
	TA * taPrev = NULL;
	TA * taCurr;

	for(int i = 0; i < capacity; i++) {
		taCurr = graph[i];
		//deletes all TA nodes
		while(taCurr != NULL) {
			taPrev = taCurr;
			taCurr = taCurr->next;
			deleteTaStudents(taPrev);

			delete taPrev;
		}
	}

	delete [] graph;
}

/*
 * Deletes the STUDENTs of a TA
 *
 * @parameter	TA* taNode - Pointer to the TA
 * @return	void
 */
void Graph::deleteTaStudents(TA * taNode)
{
	STUDENT * studentPrev = NULL;
	STUDENT * studentCurr;

	studentCurr = taNode->students;
	//deletes all STUDENT nodes
	while(studentCurr != NULL) {
		studentPrev = studentCurr;
		studentCurr = studentCurr->next;
		delete studentPrev;
	}
}

/*
 * Inserts TA and the course they taught into the graph
 *
 * @parameter	string ta - TA
 * 		string course - Course the TA taught
 * @return	void
 */
void Graph::insertTaCourse(string ta, string course)
{
	//check whether to increase capacity
	checkLoadFactor();

	uint32_t hashedKey = hash_string(ta) % capacity;
	TA * temp = graph[hashedKey];
	while(temp != NULL) {
		if(temp->ta == ta) {
			//returns if ta and course already exist
			for(size_t i = 0; i < temp->courses.size(); i++) {
				if(temp->courses[i] == course) {
					return;
				}
			}
			//adds course to TA's courses vector if on TA exists
			temp->courses.push_back(course);
			return;
		}
		temp = temp->next;
	}

	//creates TA node if TA does not exist
	TA * newTa = new TA;
	newTa->ta = ta;
	newTa->students = NULL;
	newTa->courses.push_back(course);
	newTa->visited = false;
	newTa->next = graph[hashedKey];
	graph[hashedKey] = newTa;

	++size;

}

/*
 * Inserts student and course to graph
 *
 * @parameter	string student - student
 * 		string course - course student took
 * @return	void
 */
void Graph::insertStudentCourse(string student, string course)
{
	TA * currTa;
	for(int i = 0; i < capacity; i++) {
		currTa = graph[i];
		while(currTa != NULL) {
			//adds STUDENT to TA's students if TA taught the course
			for(size_t j = 0; j < currTa->courses.size(); j++) {
				if(currTa->courses[j] == course) {
					//does not add student if already exists
					bool repeated = false;
					STUDENT * currStudent = currTa->students;
					while(currStudent != NULL) {
						if(currStudent->student == student &&
							currStudent->course == course) {
							repeated = true;
							break;
						}
						currStudent = currStudent->next;
					}
					if(repeated) {
						break;
					}

					STUDENT * newStudent = new STUDENT;
					newStudent->student = student;
					newStudent->course = course;
					newStudent->next = currTa->students;
					currTa->students = newStudent;
					break;
				}
			}
			currTa = currTa->next;
		}
	}
}

/*
 * Removes a TA who does not have any STUDENTS
 *
 * @parameter	void
 * @return	void
 */
void Graph::removeStudentlessTas()
{
	TA * currTa;
	TA * prevTa;
	for(int i = 0; i < capacity; i++) {
		//deletes first TA in chain if doesn't have STUDENTs
		while(graph[i] != NULL && graph[i]->students == NULL) {
			currTa = graph[i];
			graph[i] = currTa->next;
			deleteTaStudents(currTa);
			delete currTa;
		}

		//deletes TAs from remaining chain that don't have STUDENTs
		prevTa = graph[i];
		currTa = NULL;
		if(graph[i] != NULL) {
			currTa = graph[i]->next;
		}
		while(currTa != NULL) {
			if(currTa->students == NULL) {
				prevTa->next = currTa->next;
				deleteTaStudents(currTa);
				delete currTa;
				currTa = prevTa->next;
			} else {
				prevTa = currTa;
				currTa = currTa->next;
			}
		}
	}
}

/*
 * Checks load factor. If size is not less than 4*capacity+1, increases
 * capacity and rehashes keys and values.
 *
 * @parameter	void
 * @return	void
 */
void Graph::checkLoadFactor()
{
	if(size < 4 * capacity + 1) {
		return;
	}
	int newCap = capacity * 2 + 1;
	//initialize newGraph
	TA ** newGraph = new TA*[newCap];
	for(int i = 0; i < newCap; i++) {
		newGraph[i] = NULL;
	}

	TA * currTa;
	for(int i = 0; i < capacity; i++) {
		currTa = graph[i];
		while (currTa != NULL) {
			TA * newTa = new TA;
			newTa->ta = currTa->ta;
			STUDENT * currStudent = currTa->students;

			//copies STUDENTs
			while(currStudent != NULL) {
				STUDENT * newStudent = new STUDENT;
				newStudent->student = currStudent->student;
				newStudent->course = currStudent->course;

				//insert newStudent into newTa
				newStudent->next = newTa->students;
				newTa->students = newStudent;

				currStudent = currStudent->next;
			}

			//copies TA
			newTa->courses = currTa->courses;
			newTa->visited = currTa->visited;

			//insert newTa into newGraph
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

/*
 * Prints the shortest path between 2 students using BFS
 *
 * @parameter	string ta - starting student
 * 		string student - target student
 * @return	void
 */
void Graph::printShortestPath(string ta, string student)
{
	resetVisited();
	queue<vector<string> > q;
	vector<string> path;

	path.push_back(ta);
	q.push(path);

	while(!q.empty()) {
		//sets current path to path at front of queue
		path = q.front();
		q.pop();
		//extracts current ta from path
		string currTa = path[path.size() - 1];

		uint32_t hashedKey = hash_string(currTa) % capacity;
		TA * graphTa = graph[hashedKey];
		if(graphTa != NULL) {
			graphTa->visited = true;
		}
		while(graphTa != NULL) {
			//finds ta in graph
			if(graphTa->ta == currTa) {
				STUDENT * currStudent = graphTa->students;
				while(currStudent != NULL) {
					//if finds target student, prints out entire path
					if(currStudent->student == student) {
						for(size_t i = 0; i < path.size(); i++) {
							cout << path[i];
						}
						cout << " +- " + currStudent->course + " -> " + student + "\n";
						return;

					}
					//if does not find target student,
					//adds course and student to path
					//and pushes onto queue
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

/*
 * Sets the visited property of all the TAs to false
 *
 * @parameter	void
 * @return	void
 */
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

/*
 * Prints all possible paths between ta and student
 *
 * @paramter	string ta - Starting student
 * 		string student - Target student
 * @return	void
 */
void Graph::printAllPaths(string ta, string student)
{
	vector<string> path;
	path.push_back(ta);
	printAllPathsHelper(ta, student, path);
}

/*
 * Recursively finds all the possible paths between two students
 *
 * @parameter	string ta - Latest student in the path
 * 		string student - Target student
 * 		vector<string> &path - Path
 */
vector<string> Graph::printAllPathsHelper(string ta, string student, vector<string> &path)
{
	uint32_t hashedKey = hash_string(ta) % capacity;
	TA * currTa = graph[hashedKey];
	while(currTa != NULL) {
		if(currTa->ta == ta) {
			break;
		}
		currTa = currTa->next;
	}

	//cannot find ta. removes ta (and course) from path
	if(currTa == NULL) {
		if(path.size() == 1) {
			path.pop_back();
		} else if(path.size() > 1) {
			path.pop_back();
			path.pop_back();
		}
		return path;
	}

	STUDENT * currStudent = currTa->students;
	//recursively sets currStudent as TA to continue path
	while(currStudent != NULL) {
		//prints path if target student is found
		if(currStudent->student == student) {
			for(size_t i = 0; i < path.size(); i++) {
				cout << path[i];
			}
			cout << " +- " + currStudent->course + " -> " + currStudent->student + "\n";
			currStudent = currStudent->next;
			continue;
		}

		//checks if student was already visited
		bool visited = false;
		for(size_t i = 0; i < path.size(); i=i+2) {
			if(path[i] == currStudent->student) {
				visited = true;
				break;
			}
		}
		if(visited) {
			currStudent = currStudent->next;
			continue;
		}

		path.push_back(" +- " + currStudent->course + " -> ");
		path.push_back(currStudent->student);
		printAllPathsHelper(currStudent->student, student, path);

		//removes student and course to check another student
		if (path.size() > 1) {
			path.pop_back();
			path.pop_back();
		}

		currStudent = currStudent->next;
	}

	return path;
}
