/*
 * test.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: johee
 */

#include <iostream>

#include "test.h"
#include "hashTable.h"
#include "graph.h"

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
	test.insertFirstValue("Johee", "Johee");
	cerr << "Print Johee\n";
	test.printTable();
	cerr << "Insert Johee again\n";
	test.insertFirstValue("Johee", "Johee");
	cerr << "Print Johee again\n";
	test.printTable();
	cerr << "Insert 15S16\n";
	test.insertFirstValue("15S16", "15S16");
	cerr << "Print 15S16\n";
	test.printTable();

}

void test_hashTable_loadFactor()
{
	HashTable test;
	test.insertFirstValue("Johee Chung", "Johee Chung");
	test.printTable();
	cerr << "\n";
//	test.checkLoadFactor();
	test.printTable();
}

//void test_graph_insertTa()
//{
//	Graph graph;
//	graph.insertTa("15S15", "Johee.Chung");
//}
