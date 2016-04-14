/*
 * readInput.h
 *
 *  Created on: Apr 12, 2016
 *      Author: johee
 */

#ifndef READINPUT_H_
#define READINPUT_H_

#include "hashTable.h"

using namespace std;

void popStuCour(string file, HashTable &studentTable, HashTable &courseTable);
void popTa(string file, HashTable &taTable);
void popRoster(string file, HashTable &rosterTable);


#endif /* READINPUT_H_ */
