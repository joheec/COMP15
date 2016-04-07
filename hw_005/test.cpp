/*
 * test.cpp
 *
 *  Created on: Mar 31, 2016
 *      Author: johee
 */

#include <iostream>
#include <cstdlib>

#include "sortnums.h"
#include "test.h"

using namespace std;

void test_construction()
{
	IntVector test1;
	cerr << "Construction test1 size (0): " << test1.size() << "\n";
	cerr << "Construction test1 capacity (10): " << test1.capacity() << "\n";

	IntVector test2(9);
	cerr << "Construction test2 size (0): " << test2.size() << "\n";
	cerr << "Construction test2 capacity (9): " << test2.capacity() << "\n";

}

void test_copiers()
{
	IntVector test1(7);
	IntVector test2(3);

	//copy constructor
	IntVector test3 = test1;
	cerr << "Copiers test3 size (0): " << test3.size() << "\n";
	cerr << "Copiers test3 capacity (7): " << test3.capacity() << "\n";

	//assignment
	IntVector test4(5);
	test4 = test2;
	cerr << "Copiers test4 size (0): " << test4.size() << "\n";
	cerr << "Copiers test4 capacity (3): " << test4.capacity() << "\n";
}

void test_destroy()
{
	IntVector test1(10);
	test1.add(4);
	test1.destroy();
	cerr << "Destroy test1 size (0): " << test1.size() << "\n";
	cerr << "Destroy test1 capacity (0): " << test1.capacity() << "\n";
//	test1.add(0);
//	cerr << "Destroy test1 should error.\n";
}

void test_get()
{
	IntVector test(10);
//	test.get(8);
//	test.get(-1);
//	test.get(11);
	test.add(3);
	cerr << "Get test (3): " << test.get(0) << "\n";

}

void test_set()
{
	IntVector test;
//	test.set(0, 2);
//	cerr << "Set test should error.\n";
	test.add(5);
	test.add(7);
	test.set(1,10);
	cerr << "Set test (10): " << test.get(1) << "\n";
}

void test_operator()
{
	IntVector test;
	test.add(3);
	test.add(7);
	test[0] = test[1];
	test.get(0);
	cerr << "Operator test (7): " << test.get(0) << "\n";
}

void test_add()
{
	IntVector test(2);
	test.add(1);
	cerr << "Add test (1): " << test.get(0) << "\n";
	test.add(2);
	cerr << "Add test (2): " << test.get(1) << "\n";
	cerr << "Add test size (2): " << test.size() << "\n";
	cerr << "Add test capacity (2): " << test.capacity() << "\n";
	test.add(3);
	cerr << "Add test (3): " << test.get(2) << "\n";
	cerr << "Add test size (3): " << test.size() << "\n";
	cerr << "Add test capacity (4): " << test.capacity() << "\n";
}

void test_printNumbers()
{
	IntVector test(2);
	cout << "PrintNumbers test (nothing): \n";
	printNumbers(test);
	test.add(4);
	cout << "PrintNumbers test (4): \n";
	printNumbers(test);
	test.add(5);
	test.add(111);
	cout << "PrintNumbers test (4, 5, 11): \n";
	printNumbers(test);
}

void test_swap()
{
	IntVector test;
	test.add(5);
	test.add(96);
	swap(test, 0, 1);
	cout << "Swap test (96, 5): \n";
	printNumbers(test);
}

void test_bubble()
{
	IntVector test;
	test.add(5);
	test.add(891);
	test.add(2);
	test.add(1);
	test.add(-4);

	cout << "Before bubble sort: \n";
	printNumbers(test);
	bubbleSort(test);
	cout << "After bubble sort: \n";
	printNumbers(test);
}

void test_mergeSort()
{
	IntVector test1(0);
	IntVector test2(1);
	test2.add(0);
	IntVector test3(5);
	test3.add(900);
	test3.add(34);
	test3.add(3);
	test3.add(478);
	test3.add(1);
	IntVector test4(6);
	test4.add(60);
	test4.add(19);
	test4.add(3);
	test4.add(7);
	test4.add(387);
	test4.add(58);

	cerr << "test1a\n";
	printNumbers(test1);
	mergeSort(test1);
	cerr << "\ntest1b\n";
	printNumbers(test1);

	cerr << "\ntest2a\n";
	printNumbers(test2);
	mergeSort(test2);
	cerr << "\ntest2b\n";
	printNumbers(test2);

	cerr << "\ntest3a\n";
	printNumbers(test3);
	mergeSort(test3);
	cerr << "\ntest3b\n";
	printNumbers(test3);

	cerr << "\ntest4a\n";
	printNumbers(test4);
	mergeSort(test4);
	cerr << "\ntest4b\n";
	printNumbers(test4);
}

void test_insertionSort()
{
	IntVector test1(0);
		IntVector test2(1);
		test2.add(0);
		IntVector test3(5);
		test3.add(900);
		test3.add(34);
		test3.add(3);
		test3.add(478);
		test3.add(1);
		IntVector test4(6);
		test4.add(60);
		test4.add(19);
		test4.add(3);
		test4.add(7);
		test4.add(387);
		test4.add(58);

		cerr << "test1a\n";
		printNumbers(test1);
		mergeSort(test1);
		cerr << "\ntest1b\n";
		printNumbers(test1);

		cerr << "\ntest2a\n";
		printNumbers(test2);
		mergeSort(test2);
		cerr << "\ntest2b\n";
		printNumbers(test2);

		cerr << "\ntest3a\n";
		printNumbers(test3);
		mergeSort(test3);
		cerr << "\ntest3b\n";
		printNumbers(test3);

		cerr << "\ntest4a\n";
		printNumbers(test4);
		mergeSort(test4);
		cerr << "\ntest4b\n";
		printNumbers(test4);
}
