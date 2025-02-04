/*
 * File: readInput.cpp
 * Name: Johee Chung
 * Due: April 21, 2016
 * Assignment: Homework 6 / Degree of Separation
 * Class: Comp 15
 *
 * Reads inputs from files and uses them to populate
 * tables and a graph.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "readInput.h"

using namespace std;

/*
 * Populates student hash table with inputs from a file
 *
 * @parameter	string file - Name of file with input values
 * 		HashTable &studentTable - Reference to table with students
 * @return	void
 */
void popStu(string file, HashTable &studentTable, HashTable &courseTable)
{
	//file of inputs
	ifstream fileInput;
	fileInput.open(file.c_str());

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
	//Segmentation fault: 11 will randomly appear with large data set.
	//cerr of empty string seems to reduce the likelihood of fault
	cerr << "";

}

/*
 * Populates graph hash table with inputs from a file
 *
 * @parameter	string file - Name of file with input values
 * 		Graph &graph - Reference to table that represents a graph
 * @return	void
 */
void popGraph(string file, Graph &graph)
{
	//file of inputs
	ifstream fileInput;
	fileInput.open(file.c_str());

	string line;
	if(fileInput.is_open()) {
		//populates tables
		while(getline(fileInput, line)) {
			string student;
			string course;
			breakupString(line, student, course);
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
	fileInput.open(file.c_str());

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
