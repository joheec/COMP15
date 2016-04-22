/*
 * hashTable.h
 *
 *  Created on: Apr 12, 2016
 *      Author: johee
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashTable {
public:
	HashTable();
	HashTable(int cap);
	~HashTable();

	void insert(string key, string value);
	bool keyExist(string key);
	void printTable();
	void printSearchResults(string key);



private:
	struct Node {
		string key;
		vector<string> values;
		Node * next;
	};

	static const int INITIAL_CAPACITY = 10;
	int capacity;
	int size;

	Node ** hashTable;

	void createHashTable(int cap);
	void deleteHashTable();
	void checkLoadFactor();
};



#endif /* HASHTABLE_H_ */
