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

void breakupString(string line, string &student, string &course);

void popStuCour(string file, HashTable &studentTable, HashTable &courseTable);
void popTa(string file, HashTable &taTable, Graph &graph);
void popRoster(string file, HashTable &rosterTable, Graph &graph);

//break up input to return array of each piece


#endif /* READINPUT_H_ */
