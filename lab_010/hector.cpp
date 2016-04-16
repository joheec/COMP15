//
// hector.cpp -- compare three different collision solutions
//
// your job: code the insert functions
//  our job: run the three insert functions and report results
//
#include <iostream>
#include <stdio.h>

#include "hector.h"

using namespace std;

// constructor
Hector::Hector()
{
	for (int i = 0; i < TSIZE; i++) {
		cheneyTable[i]  = NULL;
		linnyTable[i]   = -1;
		doublesTable[i] = -1;
	}
}

// destructor
Hector::~Hector()
{
	for(int i = 0; i < TSIZE; i++) {
		while(cheneyTable[i] != NULL) {
			Node * temp = cheneyTable[i]->next;
			delete cheneyTable[i];
			cheneyTable[i] = temp;
		}
	}

//	delete cheneyTable;
//	delete linnyTable;
//	delete doublesTable;
}

// linear probing
//
//  return number of collisions before finding a spot
//
int Hector::linny(int value)
{
	int attempt = 0;
	bool found  = false;
	int index;
	while (!found) {
		index = ((3 * value) + 7 + attempt) % 17;
		++attempt;
		if(linnyTable[index] == -1) {
			found = true;
		}
	}
	linnyTable[index] = value;
	return attempt;
}

// double hashing using a second function
//  
//  returns number of collisions before finding a spot
//
int Hector::doubles(int value)
{

	int attempt = 0;
	bool found  = false;
	int index;
	while (!found) {
		index = ((3*value) + 7 + (attempt*(13 - (value % 13)))) % 17;
		++attempt;
		if(doublesTable[index] == -1) {
			found = true;
		}
	}
	doublesTable[index] = value;
	return attempt;

	
}

// chained hashing -- each spot in table is a linked list 
//
//  returns number of items in that spot before insertion
//
int Hector::cheney(int value)
{
	int index = ((3 * value) + 7) % 17;

	Node * item = new Node;
	item->key = value;
	item->next = cheneyTable[index];

	cheneyTable[index] = item;

	int number = 0;
	Node * nextNode = item->next;
	while(nextNode != NULL) {
		++number;
		nextNode = nextNode->next;
	}

	return number;
}

// print the hash tables
void Hector::print()
{
	for (int i = 0; i < TSIZE; ++i) {
		cout << linnyTable[i] << " ";
	}
	
	cout << endl;
	
	for (int i = 0; i < TSIZE; ++i) {
		cout << doublesTable[i] << " ";
	}
	cout << endl;
	
	Node *iter = NULL;
	for (int i = 0; i < TSIZE; ++i) {
		iter = cheneyTable[i];
		cout << "[ ";
		while (iter != NULL) {
			cout << iter->key << " ";
			iter = iter->next;
		}
		cout << "]";
	}
	cout << endl;
}
