/*
 * File: sortnums.cpp
 * Name: Johee Chung
 * Due: April 7, 2016
 * Assignment: Homework 5 / Sorting
 * Class: Comp 15
 *
 * Determines which sorting algorithm to run. Takes the input, and sorts them.
 * The sorting algorithms available are bubble sort (bubble), merge sort
 * (sort2), and insertion sort (sort3).
 */

#include <iostream>
#include <cstdlib>

#include "sortnums.h"

using namespace std;


/*
 * Returns sorting algorithm specified on command line.
 *
 * @parameter	int argc - Number of arguments
 * 		argv - An array of strings
 * @return	string argString - The specified sorting algorithm to run
 */
string algorithmFromCommandLine(int argc, char *argv[])
{
	string argString;

	//aborts is no available algorithm is identified
	if(argc <= 1) {
		usageAbort("sortnums", "Pick an algorithm.");
	}
	//only one algorithm is specified at a time
	argString = argv[1];
	return argString;
}

/*
 * Aborts the program with a message on standard error
 * explaining how to run the program correctly from the
 * command line.
 *
 * @parameter	string progname - The name of the program
 * 		string message - Error message
 * @return	void
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
 * Read in a collection of integers from the given input stream
 * and add them to the end of the data vector.
 *
 * @parameter	istream &input - Input from the command line
 * 		IntVector &data - The IntVector to add the input to
 * @return	void
 */
void readNumbers(istream &input, IntVector &data)
{
	int number;
	input >> number;
	int index = 0;

	//checks that the input has not ended and there are no errors
	while(!input.fail()) {
		data.add(number);
		input >> number;
		index++;
	}
}


/*
 * Print contents of data one item per line.
 *
 * @parameter	IntVector &data - The data to print
 * @return	void
 */
void printNumbers(const IntVector &data)
{
	for(int i = 0; i < data.size(); ++i){
		cout << data[i] << "\n";
	}
}

/*
 * Updates contents of data so items are sorted using the chosen
 * algorithm.
 *
 * @parameter	string algorithm - The algorithm to use
 * 		IntVector &data - The IntVector to sort
 * @return	void
 */
void sortNumbers(string algorithm, IntVector &data)
{
	if(algorithm == "bubble") {
		bubbleSort(data);
	} else if (algorithm == "sort2") {
		mergeSort(data);
	} else if (algorithm == "sort3") {
		insertionSort(data);
	} else {
		throw invalid_argument( "Not a valid algorithm." );
	}
}


/*
 * Sorts the contents of data using the bubble sort algorithm.
 *
 * @parameter	IntVector &data - The IntVector to sort
 * @return	void
 */
void bubbleSort(IntVector &data)
{
	int index = 1;
	while(index < data.size()) {

		//moves element until less than previous element
		if(data[index] < data[index-1]) {
			int prevIndex = index;

			//moves element until less than previous element
			while(prevIndex > 0 &&
					data[prevIndex-1] > data[prevIndex]) {
				int temp = data[prevIndex-1];
				data[prevIndex-1] = data[prevIndex];
				data[prevIndex] = temp;
				--prevIndex;
			}
		}
		++index;
	}
}

/*
 * Sorts the contents of data using the merge sort algorithm.
 *
 * @parameter	IntVector &data - The IntVector to sort
 * @return	IntVector - Sorted IntVector
 */
IntVector mergeSort(IntVector &data)
{
	//no need to sort if there is one element or less
	if(data.size() <= 1) {
		return data;
	}

	int size0 = data.size();
	int size1 = size0/2;

	IntVector temp1;
	IntVector temp2;

	//copying elements of data into temp1 and temp2
	for(int i = 0; i < size1; ++i) {
		temp1.add(data[i]);
		temp2.add(data[size1 + i]);
	}
	if(size0 % 2 == 1) {
		temp2.add(data[size0 - 1]);
	}

	//further divides temp1 and temp2
	temp1 = mergeSort(temp1);
	temp2 = mergeSort(temp2);

	//sorts and merges temp1 and temp2
	IntVector mergedVector = merge(temp1, temp2);

	//all elements in data have been sorted
	if(data.size() == mergedVector.size()) {
		data = mergedVector;
		return data;
	} else {
		return mergedVector;
	}
}

/*
 * Sorts and merges the contents of data1 and data2.
 *
 * @parameter	IntVector &data1 - A vector to merge
 * 		IntVector &data2 - A vector to merge
 * @return	IntVector temp - A sorted vector
 */
IntVector merge(IntVector &data1, IntVector &data2)
{	IntVector temp;

	int size1 = data1.size();
	int size2 = data2.size();

	int index1 = 0;
	int index2 = 0;

	//merge vectors that have elements
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

	//copy data1's remaining elements to temp
	while(size1 != 0) {
		temp.add(data1[index1]);
		++index1;
		--size1;
	}

	//copy data2's remaining elements to temp
	while(size2 != 0) {
		temp.add(data2[index2]);
		++index2;
		--size2;
	}

	return temp;
}

/*
 * Sorts the contents of data using the insertion sort algorithm.
 *
 * @parameter	IntVector &data - The vector to sort
 * @return	void
 */
void insertionSort(IntVector &data)
{
	IntVector temp;
	int index = 0;

	while(temp.size() != data.size()) {
		int insertIndex = index;
		while(insertIndex > 0 && temp[insertIndex-1] > data[index]) {
			--insertIndex;
		}
		//make room for the inserted element
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
