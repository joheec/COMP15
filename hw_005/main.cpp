/*
 * File: main.cpp
 * Name: Johee Chung
 * Due: April 7, 2016
 * Assignment: Homework 5 / Sorting
 * Class: Comp 15
 *
 * A main function that takes inputs from the
 * command line and calls a function to sort them.
 * How the input is sorted is included in the input.
 */

#include <iostream>
#include <cstdlib>

#include "test.h"
#include "sortnums.h"

using namespace std;

//calling test functions

//int main(int argc, char *argv[])
//{
//	(void) argc;
//	(void) argv;
//	string algorithm = algorithmFromCommandLine(argc, argv);
//
//	IntVector data;
//	readNumbers(cin, data);
//
//	sortNumbers(algorithm, data);
//
//	test_construction();
//	test_copiers();
//	test_destroy();
//	test_get();
//	test_set();
//	test_operator();
//	test_add();
//
//	test_swap();
//	test_printNumbers();
//
//	test_bubble();
//
//	test_mergeSort();
//	test_insertionSort();
//	return 0;
//}


int main(int argc, char *argv[])
{
        IntVector data;
        string    sortAlgorithm;

        sortAlgorithm = algorithmFromCommandLine(argc, argv);
        readNumbers(cin, data);
        sortNumbers(sortAlgorithm, data);
        printNumbers(data);

        return 0;
}
