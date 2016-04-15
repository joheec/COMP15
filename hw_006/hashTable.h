/*
 * hashTable.h
 *
 *  Created on: Apr 12, 2016
 *      Author: johee
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>

using namespace std;

class HashTable {
public:
	HashTable();
	HashTable(int cap);
	~HashTable();

	//in insert check ratio of size and capacity
	void insert(string key, string value);
	void printTable();
	void printSearchResults(string key);
//	void checkLoadFactor();
private:
	struct Node {
		string key;
		string value;
		Node * next;
	};

	static const int INITIAL_CAPACITY = 10;
	int capacity;
	int size;

	Node ** hashTable;

	void createHashTable(int cap);
	void deleteHashTable();
	void checkLoadFactor();
	void resizeHashTable();
};



#endif /* HASHTABLE_H_ */
