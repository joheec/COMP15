/*
 * readInput.h
 *
 *  Created on: Apr 12, 2016
 *      Author: johee
 */

#ifndef READINPUT_H_
#define READINPUT_H_

#include "hashTable.h"
#include "graph.h"

using namespace std;

void popStuCour(string file, HashTable &studentTable, HashTable &courseTable);
void popTaGraph(string file, HashTable &taTable, Graph &graph);
void popRosterGraph(string file, HashTable &rosterTable, Graph &graph);

void breakupString(string line, string &student, string &course);


#endif /* READINPUT_H_ */
