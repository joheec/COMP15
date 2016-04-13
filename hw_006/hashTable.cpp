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

//	cerr << "Insert value: " << value << "\n";
	uint32_t key = hash_string(value) % capacity;
//	cerr << "Insert key: " << key << "\n";
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

//	cerr << "Insert hashTable value: " << hashTable[key]->value << "\n";

	++size;

}

void HashTable::checkLoadFactor()
{
	if(size < 4 * capacity) {
		return;
	}
	int newCap = capacity * 2;
	HashTable temp = new HashTable(newCap);
	Node * curr;
	for(int i = 0; i < capacity; i++) {
		curr = hashTable[i];
		while (curr != NULL) {
			temp.insert(curr->value);
			curr = curr->next;
		}
	}
	deleteHashTable();
	hashTable = temp;
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
	return true;
}
