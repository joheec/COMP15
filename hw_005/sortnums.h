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

#ifndef SORTNUMS_H_
#define SORTNUMS_H_

#include "IntVector.h"

using namespace std;

string algorithmFromCommandLine(int argc, char *argv[]);
void usageAbort (string progname, string message);
void readNumbers(istream &input, IntVector &data);
void printNumbers(const IntVector &data);
void sortNumbers(string algorithm, IntVector &data);

void bubbleSort(IntVector &data);
IntVector mergeSort(IntVector &data);
IntVector merge(IntVector &data1, IntVector &data2);
void insertionSort(IntVector &data);

#endif /* SORTNUMS_H_ */
