/*
 * IntVector.cpp
 *
 *  Created on: Mar 31, 2016
 *      Author: johee
 */

#include <iostream>
#include <cstdlib>
#include <assert.h>

#include "IntVector.h"

using namespace std;


IntVector::IntVector()
{
	sortingBins = new int[INITIAL_CAPACITY];
	binSize = 0;
	binCapacity = INITIAL_CAPACITY;
}

/*
 * A constructor with an initial size is optional.
 */
IntVector::IntVector(int initialSize)
{
	sortingBins = new int[initialSize];
	binSize = 0;
	binCapacity = initialSize;
}

/*
 * You have two choices with the copy constructor and
 * assignment operator:
 *      - implement them correctly, or
 *      - make them private
 *
 * Making them private means that clients can't use them,
 * i. e., they won't be able to pass or return them by value
 * or assign them.
 *
 * Copying 100,000 element arrays is not something you want
 * to do lightly!
 */
IntVector::IntVector(const IntVector &source)
{
	sortingBins = new int[source.binCapacity];
	binSize = source.binSize;
	binCapacity = source.binCapacity;

	for(int i = 0; i < binSize; ++i) {
		sortingBins[i] = source.sortingBins[i];
	}
}
IntVector &IntVector::operator=(const IntVector &rhs)
{
	if(this == &rhs) {
		return * this;
	}

	delete[] sortingBins;
	sortingBins = new int[rhs.binCapacity];
	binSize = rhs.binSize;
	binCapacity = rhs.binCapacity;

	for(int i = 0; i < binSize; ++i) {
		sortingBins[i] = rhs.sortingBins[i];
	}

	return *this;

}

IntVector::~IntVector()
{
	delete [] sortingBins;
}

/*
 * Makes the vector have a size and capacity of 0 and
 * recycles heap-allocated storage.
 * The client may continue to use the IntVector after
 * calling destroy, e. g., they could add elements to it.
 */
void IntVector::destroy()
{
	delete[] sortingBins;
	sortingBins = new int[0];
	binCapacity = 0;
	binSize = 0;
}

/*
 * Return integer value at given index.
 *
 * Throw exception or abort with error message if index
 * out of range.
 */
int IntVector::get(int index) const
{
	assert(index >= 0 && index < binSize);
	return sortingBins[index];
}

/*
 * Set array element at given index to newVal.
 * Throw exception or abort with error message if index
 * out of range.
 */
void IntVector::set(int index, int newVal)
{
	assert(index >= 0 && index < binSize);
	sortingBins[index] = newVal;
}

/*
 * Return reference to array slot at given index.
 * This permits subscripted access to vector as
 * L-value and/or R-value.
 *
 * Throw exception or abort with error message if index
 * out of range.
 */
int &IntVector::operator[](int index) const
{
	assert(index >= 0 && index < binSize);
	return sortingBins[index];
}

/* Add newVal to end of vector, increasing current size by one. */
void  IntVector::add(int newVal)
{
	if(binSize < binCapacity) {
		sortingBins[binSize] = newVal;
		++binSize;
		return;
	}
	binCapacity = 2 * binCapacity;
	int * temp = new int[binCapacity];

	for(int i = 0; i < binSize; ++i) {
		temp[i] = sortingBins[i];
	}
	delete[] sortingBins;
	sortingBins = temp;

	add(newVal);
}

/* Return current size of vector. */
int IntVector::size() const
{
	return binSize;
}

/* Return current capacity of vector */
int IntVector::capacity() const
{
	return binCapacity;
}
