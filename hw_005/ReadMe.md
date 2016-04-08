## ReadMe for COMP 15 HW5
## Sorting Assignment

PURPOSE:
	Takes an input of integers and sorts them using an algorithm also
	specified in the input.

FILES:
	- main.cpp: Runs the program
	- test.h/test.cpp: Test functions
	- IntVector.h/IntVector.cpp: Creates, manipulates, and gets 
	information from a dynamic array.
	- sortnums.h/sortnums.cpp: Gets which algorithm to run and
	data from input. Prints and sorts data.

HOW TO COMPILE:
	- Use included Makefile.
	
DATA STRUCTURE:
	- Uses dynamic arrays to hold data.

ALGORITHM:
	- Bubble Sort
		- Goes through the vector and checks that each element is 
		less than the previous element. If the previous element is
		greater than the current element, move the element to a lower
		index until the previous element is less than the current
		element.
		- Best Case Complexity is O(n). The first while loop will
		iterate through all the elements regardless, but the while 
		loop inside of it will not iterate if all the elements are 
		already sorted.
		- Worst Case Complexity is O(n^2). The first while loop will
		iterate through all the elements regardless, but the while
		loop inside of it will iterate through all of the elements
		before it if all the elements are in reverse order.
	- Merge Sort
		- Recursively divides the vector until there it has a size of
		one. Merge the divided vectors one at a time, putting the 
		elements in ascending order .
		- Best and Worst Case Complexity is O(nlogn). The input is 
		recurively halved and then the elements are iterated through
		as they are merged together, causing log n iterations of n.
	- Insertion Sort
		- Insert an element from the input one at a time into another
		vector. Each time an element is inserted, check that it is
		greater than the previous element. If it is less than the
		previous element, move up the vector until it is greater
		than its previous element. This is where the
		element is inserted. Shift the elements behind it down one.
		- Best Case Complexity is O(n). The first while loop will
		iterate through all the elements regardless, but the while 
		loop inside of it will not iterate if all the elements are 
		already sorted.
		- Worst Case Complexity is O(n^2). The first while loop will
		iterate through all the elements regardless, but the while
		loop inside of it will iterate through all of the elements
		before it and shift the elements behind it by one if all the 
		elements are in reverse order.

ACKNOWLEDGEMENTS:
	- Original credit goes to Tufts University.