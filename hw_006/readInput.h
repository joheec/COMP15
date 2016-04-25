/*
 * File: readInput.h
 * Name: Johee Chung
 * Due: April 21, 2016
 * Assignment: Homework 6 / Degree of Separation
 * Class: Comp 15
 *
 * Reads inputs from files and uses them to populate
 * tables and a graph.
 */

#ifndef READINPUT_H_
#define READINPUT_H_

#include "hashTable.h"
#include "graph.h"

using namespace std;

void popStu(string file, HashTable &studentTable, HashTable &courseTable);
void popGraph(string file, Graph &graph);
void popRosterGraph(string file, HashTable &rosterTable, Graph &graph);

void breakupString(string line, string &student, string &course);


#endif /* READINPUT_H_ */
