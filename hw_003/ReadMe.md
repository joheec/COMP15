# ReadMe for COMP 15 HW3
## ISIS Course Roster and Waitlists

PURPOSE:
	To create a class roster with 2 associated waitlists. One waitlist
	holds students of the same major as the class, and the other waitlist
	holds student who are not of the class major. This program can increase
	the capacity of a class and populate the roster with students from
	the waitlists.

FILES:
	* main.cpp - Runs the program. Includes tests.
	* Student.h - Defines a student struct with a name and (bool)major.
	* Set.h/Set.cpp - A set that holds students. Used to create the roster.
	* Queue.h/Queue.cpp - A queue that hold students. Used to create the
	major and other waitlist.
	* IsisCourse.h/IsisCourse.cpp - Creates the roster and waitlists. 
	Places students on and off the roster and waitlists.

HOW TO COMPILE:
	* Use included Makefile.

DATA STRUCTURE:
	* Used a singly linked list to create the following abstract data types
		* Set (class roster)
		* Queue (waitlists)
	* The singly linked lists had a front pointer and a student node. The
	student node had a student (name and major) and a pointer to the 
	next student node in the list.

ALGORITHM:
	* Destruct a singly linked list - While the front pointer is not equal
	to NULL, set a temp pointer to the front pointer, and set the
	front pointer to the front's next pointer. Delete temp and repeat 
	until front is equal to NULL.
	* Add a student to a singly linked list - Create a new node using the
	given student. Traverse down the list using a temp pointer until 
	temp's next pointer equals NULL. Make temp's next point to the new 
	node. Set the new node's next pointer to NULL.
	* Drop a student from a singly linked list - Create a previous pointer
	and a current pointer. Traverse the list until the student node
	contains the given student. Use previous and current to have the
	node before the current student node point to the next student node. 
	Then delete the current student node. 
	* Update the enrollments - If the roster size is less than capacity,
	attempt to fill the roster with students from the major waitlist until
	the roster reaches capacity. If there are no more students on the
	major waitlist, fill the roster with students from the other waitlist.
	* Find a student's position on a waitlist - Dequeue student nodes from
	a given waitlist and enqueue those nodes to a temp queue. Keep
	count of how many nodes have been dequeued, and when the given student
	is found in a node, use the count at that time as the position. 
	Continue dequeuing and enqueuing until the waitlist is empty. Then 
	dequeue all the nodes from the temp queue to the waitlist. 

ACKNOWLEDGEMENTS:
	* Original credit goes to Tufts University.
