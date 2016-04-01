/*
 * test.cpp
 *
 *  Created on: Mar 31, 2016
 *      Author: johee
 */

#include <iostream>
#include <cstdlib>

#include "IntVector.h"

using namespace std;

void test_construction()
{
	new IntVector();
	new IntVector(9);

}

void test_copiers()
{
	IntVector test1(7);
	IntVector test2(3);

	//copy constructor
	IntVector test3 = test1;

	//assignment
	IntVector test4(5);
	test4 = test2;

	test3 = test3;
}
