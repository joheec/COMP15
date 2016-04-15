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

void popStuCour(string file, HashTable &studentTable, HashTable &courseTable)
{
	//file of inputs
	ifstream fileInput;
	fileInput.open(file);
	string line;
	if(fileInput.is_open()) {
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

void popTa(string file, HashTable &taTable)
{
	//file of inputs
	ifstream fileInput;
	fileInput.open(file);
	string line;
	if(fileInput.is_open()) {
		while(getline(fileInput, line)) {
			string student;
			string course;
			breakupString(line, student, course);
			taTable.insert(student, course);
		}
		fileInput.close();
	} else {
		cerr << "Unable to open file.";
	}
}

void popRoster(string file, HashTable &rosterTable)
{
	//file of inputs
	ifstream fileInput;
	fileInput.open(file);
	string line;
	if(fileInput.is_open()) {
		while(getline(fileInput, line)) {
			string student;
			string course;
			breakupString(line, student, course);
			rosterTable.insert(course, student);
		}
		fileInput.close();
	} else {
		cerr << "Unable to open file.";
	}
}

void breakupString(string line, string &student, string &course)
{
	size_t pos = line.find(":");
	student = line.substr(0, pos);

	//remove colon from course
	string tempCourse = line.substr(pos + 1);
	pos = tempCourse.find(":");
	course = tempCourse.substr(0, pos);
	course += tempCourse.substr(pos + 1);
}
