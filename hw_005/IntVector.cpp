/*
 * File IntVector.cpp
 * Name: Johee Chung
 * Due: April 7, 2016
 * Assignment: Homework 5 / Sorting
 * Class: Comp 15
 *
 * A dynamic array with private variables for the size and
 * capacity of the dynamic array. A user can get a information
 * about the array as well as add elements and set the values
 * of existing elements. The user cannot remove individual
 * elements, but they can destroy the dynamic array, setting
 * the size and capacity to zero.
 */

#include <iostream>
#include <cstdlib>
#include <assert.h>

#include "IntVector.h"

using namespace std;

//Constructor
IntVector::IntVector()
{
	sortingBins = new int[INITIAL_CAPACITY];
	binSize = 0;
	binCapacity = INITIAL_CAPACITY;
}

//Constructor with a passed in initial capacity
IntVector::IntVector(int initialCapacity)
{
	sortingBins = new int[initialCapacity];
	binSize = 0;
	binCapacity = initialCapacity;
}

//Copy Constructor
IntVector::IntVector(const IntVector &source)
{
	sortingBins = new int[source.binCapacity];
	binSize = source.binSize;
	binCapacity = source.binCapacity;

	for(int i = 0; i < binSize; ++i) {
		sortingBins[i] = source.sortingBins[i];
	}
}

//Assignment Operator
IntVector &IntVector::operator=(const IntVector &rhs)
{
	//if rhs is pointing to the same location as this, nothing to be done
	if(this == &rhs) {
		return * this;
	}

	delete[] sortingBins;

	//copying rhs
	sortingBins = new int[rhs.binCapacity];
	binSize = rhs.binSize;
	binCapacity = rhs.binCapacity;

	for(int i = 0; i < binSize; ++i) {
		sortingBins[i] = rhs.sortingBins[i];
	}

	return *this;

}

//Destructor
IntVector::~IntVector()
{
	delete [] sortingBins;
}

/*
 * Deletes the dynamic array and creates a new one with a size and capacity
 * of zero.
 *
 * @parameter	void
 * @return	void
 */
void IntVector::destroy()
{
	delete[] sortingBins;

	//set capacity and size to zero
	sortingBins = new int[0];
	binCapacity = 0;
	binSize = 0;
}

/*
 * Returns integer value at given index.
 *
 * @parameter	int index - An index in the dynamic array
 * @return	int - The element at the index
 */
int IntVector::get(int index) const
{
	//assert there is an element at index
	assert(index >= 0 && index < binSize);
	return sortingBins[index];
}

/*
 * Changes the element at given index to newVal.
 *
 * @parameter	int index - An index in the dynamic array
 * 		int newVal - The integer to set the element to
 * @return	void
 */
void IntVector::set(int index, int newVal)
{
	//assert there is an element at index
	assert(index >= 0 && index < binSize);
	sortingBins[index] = newVal;
}

/*
 * Return reference to array slot at given index.
 * This permits subscripted access to vector as
 * L-value and/or R-value.
 *
 * @parameter	int index - An index in the array
 * @return	reference to array slot at given index
 */
int &IntVector::operator[](int index) const
{
	//assert there is an element at index
	assert(index >= 0 && index < binSize);
	return sortingBins[index];
}

/*
 * Add newVal to end of vector, increasing current size by one.
 *
 * @parameter	int newVal - Value to add to the end of the array
 * @return	void
 */
void  IntVector::add(int newVal)
{
	//does not need to increase array capacity
	if(binSize < binCapacity) {
		sortingBins[binSize] = newVal;
		++binSize;
		return;
	}

	//increase capacity of array to add new value
	binCapacity = (2 * binCapacity) + 1;
	int * temp = new int[binCapacity];

	for(int i = 0; i < binSize; ++i) {
		temp[i] = sortingBins[i];
	}
	delete[] sortingBins;
	sortingBins = temp;

	add(newVal);
}

/*
 * Return current size of vector.
 *
 * @parameter	void
 * @return	int binSize - The size of the array
 */
int IntVector::size() const
{
	return binSize;
}

/*
 * Return current capacity of vector
 *
 * @parameter	void
 * @return	int binCapacity - The capacity of the array
 */
int IntVector::capacity() const
{
	return binCapacity;
}
