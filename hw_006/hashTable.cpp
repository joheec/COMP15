/*
 * File hashTable.cpp
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

//Constructor with initial capacity
HashTable::HashTable(int cap)
{
	createHashTable(cap);
}

/*
 * Creates a hash table
 *
 * @parameter	int cap - Initial capacity of hash table
 * @return	void
 */
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

/*
 * Deletes hash table
 *
 * @parameter	void
 * @return	void
 */
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

/*
 * Insert key and value in hash table
 *
 * @parameter	string key - Key
 * 		string value - Value
 * @return	void
 */
void HashTable::insert(string key, string value)
{
	//check if needs to increase capacity
	checkLoadFactor();

	uint32_t hashedKey = hash_string(key) % capacity;
	Node * temp = hashTable[hashedKey];

	while(temp != NULL) {
		if(temp->key == key) {
			//does not insert if key and value already exist
			for(size_t i = 0; i < temp->values.size(); i++) {
				if(temp->values[i] == value) {
					return;
				}
			}
			//inserts value if only key exists
			temp->values.push_back(value);
			return;
		}
		temp = temp->next;
	}

	//creates new node if key and value do not exist
	Node * newNode = new Node;
	newNode->key = key;
	newNode->values.push_back(value);
	newNode->next = hashTable[hashedKey];
	hashTable[hashedKey] = newNode;

	++size;
}

/*
 * Checks load factor. If size is not less than 4*capacity+1, increases
 * capacity and rehashes keys and values.
 *
 * @parameter	void
 * @return	void
 */
void HashTable::checkLoadFactor()
{
	if(size < 4 * capacity + 1) {
		return;
	}
	int newCap = capacity * 2 + 1;
	//inserts keys and values into new hash table
	HashTable newHashTable(newCap);
	Node * currNode;
	for(int i = 0; i < capacity; i++) {
		currNode = hashTable[i];
		while (currNode != NULL) {
			for(size_t i = 0; i < currNode->values.size(); i++) {
				newHashTable.insert(currNode->key, currNode->values[i]);
			}
			currNode = currNode->next;
		}
	}
	//replaces this hash table with new hash table
	deleteHashTable();
	*this = newHashTable;
}

/*
 * Returns true if key is in the table; false if key does not exist
 *
 * @parameter	string key - Key to check
 * @return	bool
 */
bool HashTable::keyExist(string key)
{
	uint32_t hashedKey = hash_string(key) % capacity;
	Node * curr = hashTable[hashedKey];

	while(curr != NULL) {
		if(curr->key == key) {
			return true;
		}
		curr = curr->next;
	}

	return false;
}

/*
 * Prints values of the table
 *
 * @parameter	void
 * @return	void
 */
void HashTable::printTable()
{
	Node * curr;
	for(int i = 0; i < capacity; i++) {
		curr = hashTable[i];
		while (curr != NULL) {
			for(size_t i = 0; i < curr->values.size(); i++) {
				cout << curr->values[i] + "\n";
			}
			curr = curr->next;
		}
	}
}

/*
 * Prints the values of a key
 *
 * @parameter	string key - Key to search for
 * @return	void
 */
void HashTable::printSearchResults(string key)
{
	uint32_t hashedKey = hash_string(key) % capacity;
	Node * curr = hashTable[hashedKey];
	while(curr != NULL) {
		if(curr->key == key) {
			for(size_t i = 0; i < curr->values.size(); i++) {
				cout << curr->values[i] + "\n";
			}
			return;
		}
		curr = curr->next;
	}
}

