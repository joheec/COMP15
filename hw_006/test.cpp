/*
 * test.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: johee
 */

#include <iostream>

#include "test.h"
#include "hashTable.h"

using namespace std;


void test_hashTable_create_delete()
{
	HashTable* test = new HashTable();
	(void) test;
}

void test_hashTable_insert_print()
{
	HashTable test;
	cerr << "Insert Johee\n";
	test.insert("Johee");
	cerr << "Print Johee\n";
	test.print();
	cerr << "Insert Johee again\n";
	test.insert("Johee");
	cerr << "Print Johee again\n";
	test.print();
	cerr << "Insert 15S16\n";
	test.insert("15S16");
	cerr << "Print 15S16\n";
	test.print();

}

void test_hashTable_loadFactor()
{
	HashTable test;
	test.insert("Johee Chung");
	test.print();
	cerr << "\n";
//	test.checkLoadFactor();
	test.print();
}
