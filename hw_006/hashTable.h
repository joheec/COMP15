/*
 * File hashTable.h
 * Name: Johee Chung
 * Due: April 21, 2016
 * Assignment: Homework 6 / Degrees of Separation
 * Class: Comp 15
 *
 * A hash table. Collision is handled with chaining.
 * Can insert key-value pairs, look up values with a key,
 * and print the table. When the size is greater than
 * or equal to 4 * capacity + 1, the capacity increases
 * (capacity * 2 + 1).
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
