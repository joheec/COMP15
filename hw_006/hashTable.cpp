/*
 * hashTable.cpp
 *
 *  Created on: Apr 12, 2016
 *      Author: johee
 */

#include <iostream>
#include <assert.h>

#include "hashTable.h"
#include "hashfunc.h"

using namespace std;

//Constructor
HashTable::HashTable()
{
	createHashTable(INITIAL_CAPACITY);
}

//Constructor
HashTable::HashTable(int cap)
{
	createHashTable(cap);
}

void HashTable::createHashTable(int cap)
{
	size = 0;
	capacity = cap;

	hashTable = new Node*[cap];
	for(int i = 0; i < cap; i++) {
		hashTable[i] = NULL;
	}
}

//Destructor
HashTable::~HashTable()
{
	deleteHashTable();
}

void HashTable::deleteHashTable()
{
	Node * prev = NULL;
	Node * curr;
	for(int i = 0; i < capacity; i++) {
		curr = hashTable[i];
		while(curr != NULL) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
	}

	delete [] hashTable;
}

void HashTable::insert(string value)
{
	checkLoadFactor();

	uint32_t key = hash_string(value) % capacity;
	Node * temp = hashTable[key];
	while(temp != NULL) {
		if(temp->value == value) {
			return;
		}
		temp = temp->next;
	}

	Node * newNode = new Node;
	newNode->value = value;
	newNode->next = hashTable[key];
	hashTable[key] = newNode;

	++size;

}

void HashTable::checkLoadFactor()
{
	if(size < 4 * capacity) {
		return;
	}
	int newCap = capacity * 2;
	Node ** newHashTable = new Node*[newCap];
	Node * currNode;
	for(int i = 0; i < capacity; i++) {
		currNode = hashTable[i];
		while (currNode != NULL) {
			uint32_t key = hash_string(currNode->value) % newCap;
			Node * newNode = new Node;
			newNode->value = currNode->value;

			newNode->next = newHashTable[key];
			newHashTable[key] = newNode;
			currNode = currNode->next;
		}
	}
	deleteHashTable();
	hashTable = newHashTable;
	capacity = newCap;
}

void HashTable::print()
{
	Node * curr;
	for(int i = 0; i < capacity; i++) {
		curr = hashTable[i];
//		bool nullTest = curr==NULL ? true : false;

//		cerr << "Print hashTable value: " << nullTest << "\n";

		while (curr != NULL) {
			cout << curr->value << "\n";
			curr = curr->next;
		}

	}
}

bool HashTable::search(string searchValue)
{
	(void) searchValue;
	return true;
}
