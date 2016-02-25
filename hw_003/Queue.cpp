/*
 * Queue.cpp
 *
 */
#include <iostream>
#include "Queue.h"
#include <cassert>

using namespace std;

/*
 * Constructor
 */
Queue::Queue()
{
	front = NULL;
}

/*
 * Destructor
 */
Queue::~Queue()
{
	if(front == NULL) return;

	Student_Node * temp = NULL;
	while(front != NULL) {
		temp = front;
		front = front->next;
		delete temp;
	}
}

/*
 * @parameter	Student	s	The student to add to the queue.
 * @return	none
 *
 * Creates a student node with the given student and adds the node to the
 * back of a singly-linked list.
 */
void Queue::enqueue(Student s)
{
	Student_Node * new_node = new Student_Node;
	new_node->student = s;

	if(front == NULL) {
		front = new_node;
		new_node->next = NULL;
		return;
	}

	Student_Node * temp = front;
	while(temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = new_node;
	new_node->next = NULL;
}

/*
 * @parameter	none
 * @return	Student	temp->student	The student at the front of the
 * 					singly linked list.
 *
 * Returns the student from the student node at the front of the singly
 * linked list.
 */
Student Queue::dequeue()
{
	Student_Node * temp = front;
	front = front->next;
	return temp->student;
}

/*
 * @parameter	none
 * @return	bool	Returns true if there are no student nodes in the queue.
 * 			Returns false if there is a student node in the queue.
 *
 * Checks if the queue is empty by testing whether the front pointer is null.
 * If the queues is empty, returns true. If the queues is not empty, returns
 * false.
 */
bool Queue::is_empty()
{
	if(front == NULL) {
		return true;
	} else {
		return false;
	}
}
