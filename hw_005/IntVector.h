/*
 * File IntVector.h
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

class IntVector
{
public:
	IntVector();
	IntVector(int initialCapacity);
	~IntVector();

	IntVector(const IntVector &source);
	IntVector &operator=(const IntVector &rhs);

	void destroy();
	int get(int index) const;
	void set(int index, int newVal);
	int  &operator[](int index) const;
	void  add(int newVal);
	int size() const;
	int capacity() const;
private:
	static const int INITIAL_CAPACITY = 10;
	int * sortingBins;
	int binSize;
	int binCapacity;
};
