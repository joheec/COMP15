/*
 * readInput.cpp
 *
 *  Created on: Apr 12, 2016
 *      Author: johee
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "readInput.h"

using namespace std;

/*
 * Populates student and course hash tables with inputs from a file
 *
 * @parameter	string file - Name of file with input values
 * 		HashTable &studentTable - Reference to table with students
 * 		HashTable & courseTable - Reference to table with courses
 * @return	void
 */
void popStuCour(string file, HashTable &studentTable, HashTable &courseTable)
{
	//file of inputs
	ifstream fileInput;
	fileInput.open(file);

	string line;
	if(fileInput.is_open()) {
		//populate tables
		while(getline(fileInput, line)) {
			string student;
			string course;
			breakupString(line, student, course);
			studentTable.insert(student, student);
			courseTable.insert(course, course);
		}
		fileInput.close();
	} else {
		cerr << "Unable to open file.";
	}

}

/*
 * Populates TA and graph hash tables with inputs from a file
 *
 * @parameter	string file - Name of file with input values
 * 		HashTable &taTable - Reference to table with TAs
 * 		Graph &graph - Reference to table that represents a graph
 * @return	void
 */
void popTaGraph(string file, HashTable &taTable, Graph &graph)
{
	//file of inputs
	ifstream fileInput;
	fileInput.open(file);

	string line;
	if(fileInput.is_open()) {
		//populates tables
		while(getline(fileInput, line)) {
			string student;
			string course;
			breakupString(line, student, course);
			taTable.insert(student, course);
			graph.insertTaCourse(student, course);
		}
		fileInput.close();
	} else {
		cerr << "Unable to open file.";
	}
}

/*
 * Populates roster and graph hash tables with inputs from a file
 *
 * @parameter	string file - Name of file with input values
 * 		HashTable &rosterTable - Reference to table with rosters
 * 		Graph &graph - Reference to table that represents a graph
 * @return	void
 */
void popRosterGraph(string file, HashTable &rosterTable, Graph &graph)
{
	//file of inputs
	ifstream fileInput;
	fileInput.open(file);

	string line;
	if(fileInput.is_open()) {
		//populates tables
		while(getline(fileInput, line)) {
			string student;
			string course;
			breakupString(line, student, course);
			rosterTable.insert(course, student);
			graph.insertStudentCourse(student, course);
		}
		fileInput.close();
	} else {
		cerr << "Unable to open file.";
	}
}

/*
 * Takes a string and breaks it up by student and course
 *
 * @parameter	string line - The string to break up
 * 		string &student - Reference. Student portion of line
 * 		string &course - Reference. Course portion of line
 */
void breakupString(string line, string &student, string &course)
{
	//format of line: studentName:course:semester
	size_t pos = line.find(":");
	student = line.substr(0, pos);

	//consolidate course and semester
	string tempCourse = line.substr(pos + 1);
	pos = tempCourse.find(":");
	course = tempCourse.substr(0, pos);
	course += tempCourse.substr(pos + 1);
}
