/*
 * main.cpp
 *
 *  Created on: Apr 5, 2016
 *      Author: johee
 */

/*
 *  Comp 15
 *  Sorting Assignment
 *
 *  sortnums.cpp
 *  Author:  Mark A. Sheldon, Tufts University, Spring 2016
 *
 *  This file is taken from my solution, but with the function
 *  definitions, except for main(), omitted.
 *
 *  You may use this code as-is, you can modify it, or you can throw
 *  it away and do your own thing.  But there are things you should
 *  note:
 *
 *       - main() is really sweet.  Aspire to this level of directness
 *         and clarity.
 *       - The integer vector is always passed by reference.  This
 *         avoids lots of copying, and allows you to not implement a
 *         copy constructor.
 *       - The input stream (cin) is also passed by reference.  Always
 *         pass input/output streams by reference or pointer.
 *       - It is common Unix practice to print a "usage" string on the
 *         standard error output (cerr) when a program is not used
 *         correctly.  The usageAbort() function is give to you, and
 *         you can use it to exit the program with an appropriate
 *         message if no algorithm is given on the command line or if
 *         the algorithm given isn't one of "bubble", "sort2",
 *         "sort3".
 *       - Detailed specifications for the functions declared at the
 *         top of the file are given below main(), but the
 *         implementations have been omitted.
 */
#include <iostream>
#include <cstdlib>

#include "test.h"
#include "sortnums.h"

using namespace std;

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
//	string algorithm = algorithmFromCommandLine(argc, argv);
//
//	IntVector data;
//	readNumbers(cin, data);
//
//	sortNumbers(algorithm, data);
////
//	test_construction();
//	test_copiers();
//	test_destroy();
//	test_get();
//	test_set();
//	test_operator();
//	test_add();

//	test_swap();
//	test_printNumbers();
//
//	test_bubble();

	test_mergeSort();
	return 0;
}


//int main(int argc, char *argv[])
//{
//        IntVector data;
//        string    sortAlgorithm;
//
//        sortAlgorithm = algorithmFromCommandLine(argc, argv);
//        readNumbers(cin, data);
//        sortNumbers(sortAlgorithm, data);
//        printNumbers(data);
//
//        return 0;
//}
