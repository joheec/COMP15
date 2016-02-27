/*
 * Set.cpp
 *
 * Add your code below.  Do not change the print function.
 *
 */

#include <iostream>
#include "Set.h"
#include <cassert>

using namespace std;

/*
 * @parameter	none
 * @return	none
 *
 * Traverses the linked list that represents a set,
 * printing from each student node the student's name
 * and whether the student is of the major.
 */
void Set::print_class()
{
	Student_Node * temp = front;
	while (temp != NULL) {
		cout << temp->student.name << ", "
			<< (temp->student.major ? "Major" : "Non-Major")
			<< "\n";
		temp = temp->next;
	}
}

/*
 * Set constructor.
 */
Set::Set()
{
	front = NULL;
	class_size = 0;
}

/*
 * Set destructor.
 */
Set::~Set()
{
	Student_Node * temp = NULL;
	while (front != NULL) {
		temp = front;
		front = front->next;
		delete temp;
	}

}

/*
 * @parameter	Student	s	A student that contains their name and whether
 * 				they are a major or non-major.
 * @return	bool		Returns true after a student is added to the
 * 				set. Returns false if the student is already
 * 				in the set.
 *
 * Creates a student node with the student information and adds the student
 * node to the back of the linked list if the student does not already exist.
 */
bool Set::add(Student s)
{
	assert(class_size >= 0);

	Student_Node * new_node = new Student_Node;
	new_node->student = s;

	//Student_Nodes are added to the back of the linked list.
	if(front == NULL) {
		front = new_node;
	} else {
		Student_Node * temp = front;
		while(temp->next != NULL) {
			if(temp->student.name == s.name) {
				delete new_node;
				return false;
			}
			temp = temp->next;
		}
		temp->next = new_node;
	}
	new_node->next = NULL;
	class_size++;

	return true;
}

/*
 * @parameter	Student	s	The student removed from the set.
 * @return	bool		Returns true if removes the student.
 * 				Returns false if the student is not in set.
 *
 * Searches a student's name in the linked list. If the student is found,
 * removes the student node and returns true. If the student is not in
 * the linked list, returns false.
 */
bool Set::drop(Student s)
{
	assert(front != NULL);

	Student_Node * prev_node = NULL;
	Student_Node * curr_node = front;

	while(curr_node != NULL) {
		if (curr_node->student.name == s.name) {
			break;
		}
		prev_node = curr_node;
		curr_node = curr_node->next;
	}

	//Student is not in the set.
	if(curr_node == NULL) return false;

	//Student is the first node.
	if(prev_node == NULL) {
		front = curr_node->next;
	} else {
		prev_node->next = curr_node->next;
	}

	delete curr_node;
	class_size--;

	return true;
}

/*
 * @parameter	Student	s	The student you are checking the set for.
 * @return	bool		Returns true if the student is in the set.
 * 				Returns false if the student is not in the set.
 *
 * Tests to see if a student is enrolled in the class and is therefore in
 * the set.
 */
bool Set::is_enrolled(Student s)
{
	Student_Node * temp = front;

	while(temp != NULL) {
		if(temp->student.name == s.name) {
			break;
		}
		temp = temp->next;
	}
	if(temp == NULL) {
		return false;
	} else {
		return true;
	}
}

/*
 * @parameter	none
 * @return	class_size	The number of students in the set.
 *
 * Returns the class_size which represents the number of nodes in the linked
 * list and therefore the number of students in the set.
 */
int Set::size()
{
	return class_size;
}
