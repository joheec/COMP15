/*
 * File: test.cpp
 * Name: Johee Chung
 * Due: April 21, 2016
 * Assignment: Homework 6 / Degree of Separation
 * Class: Comp 15
 *
 * Used to test the functions in this project
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
	test.insert("Johee", "Johee");
	cerr << "Print Johee\n";
	test.printTable();
	cerr << "Insert Johee again\n";
	test.insert("Johee", "Johee");
	cerr << "Print Johee again\n";
	test.printTable();
	cerr << "Insert 15S16\n";
	test.insert("15S16", "15S16");
	cerr << "Print 15S16\n";
	test.printTable();

}

void test_hashTable_loadFactor()
{
	HashTable test;
	test.insert("Johee Chung", "Johee Chung");
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
