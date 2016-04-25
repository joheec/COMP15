## ReadMe for COMP 15 HW6
## Sorting Assignment

PURPOSE:
	Takes data from a file of TAs with the courses they taed
	and a file of students with the courses they took. Depending on the
	input, will display requested parts of the data and derive paths/the
	shortest path between two students from the data.

FILES:
	- main.cpp: Takes file names and runs functions based on commands
	- test.cpp/test.h: Test functions
	- readInput.cpp/readInput.h: Takes data from files and populates tables
	- hashTable.cpp/hashTable.h: Hash table using a key value pair
	- hashfunc.cpp/hashfunc.h: Makes hashed keys from strings
	- graph.cpp/graph.h: Adjacency list with stored information about
	students. Has logic to find and print out the paths.

HOW TO COMPILE:
	- Use included Makefile.
	
DATA STRUCTURE:
	- Hash tables that handle collisions with chaining.

ALGORITHM:
	- Print Shortest Path
		- Uses BFS: Reset all the TA nodes to "not visited". Store
		the original TA in a vector of strings (hence referred to as
		"path"), and push path onto a queue. While (loop) the queue 
		is not empty, pop a path from the front, and determine the next
		TA to search for from the last entry in path. Look up the TA
		in the hash table. If that TA does not exist, repeat the while
		loop. If the TA exists, mark the TA node as visited, then
		go through the students they directly TAed. If the student
		is the target student, print out path. If the student is not
		the target student, put the course and the student name in
		path and push path into the queue. Once all of the TA's
		students have been looked at, repeat the while loop until
		the target student is found or the queue is empty.
		- Best Case Complexity is O(1). All TAs and students have a
		one-to-one relationship, and none of the TAs share the same
		index.
		- Worst Case Complexity is O(E^2). All the TAs are stored at
		the same index and all of the TAs have taught all of the 
		students.
	- Print All Paths
		- Uses DFS: Insert the original TA at the back of a vector
		of strings (path). Find the TA in the hashed table. If the TA 
		doesn't exist, return. If TA is found, go through all of the 
		students the TA directly taught using a while loop. If 
		the student is the target student, print the path, the course, 
		and the student, and go to the TA's next student. If the
		student was already visited, go to the TA's next student. If 
		they are neither the target nor was visited, insert the course
		and student to the end of the copied path, which is then passed
		recursively, looking up the new ta in the hashed table. Once
		the base cases are reached, returns back to the while loop
		and continues with the rest of the TA's students.
		- - Best Case Complexity is O(E). All TAs and students have a
		one-to-one relationship, and none of the TAs share the same
		index.
		- Worst Case Complexity is O(2^E). Every TA and student have
		and edge..

ACKNOWLEDGEMENTS:
	- Credit for the functions to create hashed keys from strings 
	goes to Tufts University.