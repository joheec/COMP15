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

#include "sortnums.h"

using namespace std;


/*
 * string algorithmFromCommandLine(int argc, char *argv[]);
 *
 * Return sorting algorithm specified on command line.
 *
 * Abort program if no algorithm is specified or if specified
 * algorithm is not supported.
 *
 */
string algorithmFromCommandLine(int argc, char *argv[])
{
	string argString;

	if(argc <= 1) {
		usageAbort("sortnums", "Pick an algorithm.");
	}
	argString = argv[1];
//	if(argString != "bubble" && argString != "sort2" && argString != "sort3") {
//		usageAbort("sortnums","Incorrect algorithm.");
//	}
	return argString;
}

/*
 * Abort the program with a message on standard error
 * explaining how to run the program correctly from the
 * command line.
 */
void usageAbort(string progname, string message)
{
        cerr << message << endl
             << "Usage:  " << progname << " algorithm" << endl
             << "     where algorithm is one of "
             << "bubble, sort2, or sort3"
             << endl;
        exit(1);
}

/*
 * void readNumbers(istream &input, IntVector &data);
 *
 * Read in a collection of integers from the given input stream
 * and add them to the end of the data vector.  Input numbers are
 * separated by whitespace (they don't have to be one per line).
 *
 * My implementation does not distinguish between failure due to end
 * of file or any other failure of the input device.  Yours may do
 * likewise. 
 *
 */
void readNumbers(istream &input, IntVector &data)
{
	int number;
	input >> number;
	int index = 0;
	while(!input.fail()) {
		data.add(number);
//		cerr << "ReadNumbers: " << data.get(index) << "\n";
		input >> number;
		index++;
	}
}


/*
 * void   printNumbers(const IntVector &data);
 *
 * Print contents of data one item per line.
 */
void printNumbers(const IntVector &data)
{
	for(int i = 0; i < data.size(); ++i){
		cout << data[i] << "\n";
	}
}

/*
 * void swap(IntVector &vector, int i, int j);
 *
 * Updates the given vector so that the items at position i and j
 * are swapped.
 */
void swap(IntVector &vector, int i, int j)
{
	int temp = vector[i];
	vector[i] = vector[j];
	vector[j] = temp;
}

/*
 * void sortNumbers(string algorithm, IntVector &data);
 *
 * Updates contents of data so items are sorted using the chosen
 * algorithm.
 */
void sortNumbers(string algorithm, IntVector &data)
{
	if(algorithm == "bubble") {
		bubbleSort(data);
	} else if (algorithm == "sort2") {
		mergeSort(data);
	} else if (algorithm == "sort3") {

	} else {
		throw invalid_argument( "Not a valid algorithm." );
	}
}


/*
 * void bubbleSort(IntVector &data);
 *
 * In-place sort of contents of data using the bubble sort algorithm.
 */
void bubbleSort(IntVector &data)
{
	int index = 1;
	while(index < data.size()) {
		if(data[index] < data[index-1]) {
			int backIndex = index;
			while(backIndex > 0) {
				int temp = data[backIndex-1];
				data[backIndex-1] = data[backIndex];
				data[backIndex] = temp;
				--backIndex;
			}
		}
		++index;
	}
}

/*
 * mergesort
 */
IntVector mergeSort(IntVector &data)
{
	if(data.size() <= 1) {
		return data;
	}

	int size0 = data.size();
	int size1 = size0/2;

	IntVector temp1;
	IntVector temp2;

	for(int i = 0; i < size1; ++i) {
		temp1.add(data[i]);
		temp2.add(data[size1 + i]);
	}

	if(size0 % 2 == 1) {
		temp2.add(data[size0 - 1]);
	}

	temp1 = mergeSort(temp1);
	temp2 = mergeSort(temp2);

	IntVector mergedVector = merge(temp1, temp2);

	if(data.size() == mergedVector.size()) {
		data = mergedVector;
		return data;
	} else {
		return mergedVector;
	}
}

/*
 * merge
 */
IntVector merge(IntVector data1, IntVector data2)
{	IntVector temp;

	int size1 = data1.size();
	int size2 = data2.size();

	int index1 = 0;
	int index2 = 0;

	while(size1 != 0 && size2 != 0) {
		if(data1[index1] < data2[index2]) {
			temp.add(data1[index1]);
			++index1;
			--size1;
		} else {
			temp.add(data2[index2]);
			++index2;
			--size2;
		}
	}

	while(size1 != 0) {
		temp.add(data1[index1]);
		++index1;
		--size1;
	}

	while(size2 != 0) {
		temp.add(data2[index2]);
		++index2;
		--size2;
	}

	return temp;
}

/*
 * Insertion
 */
void insertionSort(IntVector &data)
{
	IntVector temp;
	int index = 0;

	while(temp.size() != data.size()) {
//		if(index == 0) {
//			temp.add(data[0]);
//			++index;
//			continue;
//		}

		int insertIndex = index;
		while(insertIndex > 0 && temp[insertIndex-1] > data[index]) {
			--insertIndex;
		}
		//to increase the size of the IntVector
		temp.add(0);

		//if index is less than the size, will have to shift elements
		if(temp.size() >= insertIndex ) {
			for(int i = temp.size() - 1; i > insertIndex; --i) {
				temp[i] = temp[i-1];
			}
		}

		temp[insertIndex] = data[index];

		++index;
	}
	data = temp;
}
