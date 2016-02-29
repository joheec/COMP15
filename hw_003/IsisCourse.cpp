/*
 * File: IsisCourse.cpp
 * Name: Johee Chung
 * Due: February 29, 2016
 * Assignment: Homework 3 / ISIS Course
 * Class: COMP 15
 *
 * This class holds a roster (Set), and two waitlists (Queues)
 * for a Tufts course.
 *
 * When a student who is majoring in the subject attempts to enroll
 * in the course, he or she immediately goes into the course,
 * unless the course is at capacity.
 * If the class is at capacity, the student goes onto the major waitlist.
 *
 * When a student who is not a major attempts to enroll in the course,
 * he or she immediately goes onto the other (non-major) waitlist.
 *
 * If the capacity of the course is raised (it will never be lowered),
 * the students proceed off the waitlist immediately, until the
 * class is at capacity (full).  Students come off the major waitlist
 * first (in the order they were put on the list), and then if the
 * major waitlist is empty and the class is still not at capacity,
 * students come off the other waitlist and
 * into the course, until the course is at capacity.
 *
 * When a student is dropped from the course, students are added from
 * the waitlist(s) until the capacity is reached
 * (this is a simplification).
 */

#include <iostream>
#include <exception>
#include <stdexcept>
#include <cassert>

using std::runtime_error;

#include "IsisCourse.h"

/*
 * Constructor
 */
IsisCourse::IsisCourse()
{
        class_capacity = 0; // no students allowed in yet
}

/*
 * Constructor with an initial capacity.
 */
IsisCourse::IsisCourse(int init_capacity)
{
	class_capacity = init_capacity;
}

/*
 * Destructor
 */
IsisCourse::~IsisCourse()
{
        // nothing to do
}

/*
 * @parameter	int	cap	New value of the class capacity.
 * @return	none
 *
 * Sets a new value for the capacity of the class. The capacity can
 * only be increased. When the capacity is increased, students are moved
 * from the waitlists to the class roster. First students are moved to the
 * roster from the major waitlist. Then students from the other waitlist
 * go into the class roster. The class roster can never have more students
 * than the capacity.
 */
void IsisCourse::set_class_cap(int cap)
{
        if (cap < class_capacity)
                throw runtime_error("IsisCourse:  "
                                    "class capacity cannot be lowered");

        class_capacity = cap;
        if (roster.size() < class_capacity) {
                update_enrollments();
        }
}

/*
 * @parameter	none
 * @return	int	class_capacity	The maximum number of students allowed
 * 					on the class roster.
 *
 * Returns the maximum number of students allowed on the class roster.
 */
int IsisCourse::get_class_cap() {
	return class_capacity;
}

/*
 * @parameter	Student	s		A student.
 * @return	ENROLLMENT_STATUS	NONE, ENROLLED, MAJOR_WAITLIST,
 * 					OTHER_WAITLIST
 *
 * Attempts to enroll a student into the class. Majors go directly into
 * the class, and non-majors go directly onto the waitlist, even if there
 * is space in the class. Returns whether the student was enrolled, placed
 * on the major waitlist, or placed on the other waitlist.
 */
IsisCourse::ENROLLMENT_STATUS IsisCourse::enroll_student(Student s)
{
	if(s.major) {
		if(class_capacity <= get_roster_size()) {
			major_waitlist.enqueue(s);
			return MAJOR_WAITLIST;
		} else {
			roster.add(s);
			return ENROLLED;
		}
	} else {
		other_waitlist.enqueue(s);
		return OTHER_WAITLIST;
	}
}


// Attempts to drop a student from the class AND the waitlists
// Returns true if student was successfully dropped,
// false if the student was not on any list

/*
 * @parameter	Student	s	A student.
 * @return	bool	true	If a student is dropped from the class.
 * 			false	If a student was not in the class roster.
 *
 * Searches for a student in the class roster. If the student is found,
 * the student is removed from the class roster, replaced by another
 * student from a waitlist, and returns true. If a student is not in the
 * class roster, returns false.
 */
bool IsisCourse::drop_student(Student s)
{
	// if we find the student to drop
        bool found_student = roster.drop(s);

        // if we dropped a student, there should be room on
        // the roster
        if(found_student) {
		update_enrollments();
        }

        return found_student;
}

/*
 * @parameter	none
 * @return	none
 *
 * Put students from the waitlists into the class in priority (majors
 * first, then others), up to the class capacity. This is always executed
 * when the capacity is increased, but can also be executed to fill up the
 * class to its current capacity.
 */
void IsisCourse::update_enrollments()
{
        while(!major_waitlist.is_empty()) {
        	if(roster.size() >= class_capacity) {
        		break;
        	}
        	roster.add(major_waitlist.dequeue());
        }

        while(!other_waitlist.is_empty()) {
		if(roster.size() >= class_capacity) {
			break;
		}
		roster.add(other_waitlist.dequeue());
	}
}

/*
 * @parameter	none
 * @return	int	roster.size()	The size of the class roster.
 *
 * Returns the number of students enrolled in the course.
 */
int IsisCourse::get_roster_size()
{
	return roster.size();
}

/*
 * @parameter	ENROLLMENT_STATUS status	The waitlist to search.
 * 						MAJOR_WAITLIST, OTHER_WAITLIST.
 * 		Student	s		The student to search for.
 * @return	int	position	Where the student is in the waitlist.
 * 					The first position is 1. If a student
 * 					is not on the waitlist, the position
 * 					is -1.
 *
 * Returns the waitlist position for a student for a particular
 * waitlist (MAJOR_WAITLIST or OTHER_WAITLIST).
 */
int IsisCourse::waitlist_position(ENROLLMENT_STATUS status, Student s)
{
	Queue temp_queue;
        Queue * waitlist_queue;

        if(status == MAJOR_WAITLIST) {
        	waitlist_queue = &major_waitlist;
        } else if (status == OTHER_WAITLIST) {
        	waitlist_queue = &other_waitlist;
        } else {
        	throw runtime_error("Provide an existing waitlist to find"
        			"the waitlist position for.");
        }

        int position = -1;
        int counter = 0;
        while(!waitlist_queue->is_empty()) {
        	counter++;
        	Student student = waitlist_queue->dequeue();
        	temp_queue.enqueue(student);
        	if(s.name == student.name) {
        		position = counter;
        	}
        }

        while(!temp_queue.is_empty()) {
        	waitlist_queue->enqueue(temp_queue.dequeue());
        }

        return position;
}

/* 
 * @parameter	Student	s		A student
 * @return	ENROLLMENT_STATUS	The status of the given student.
 * 					NONE, ENROLLED, MAJOR_WAITLIST,
 * 					OTHER_WAITLIST
 *
 * Returns an ENROLLMENT_STATUS that says which list (or none) that the
 * student is on.
 */
IsisCourse::ENROLLMENT_STATUS IsisCourse::status(Student s)
{
	if(roster.is_enrolled(s)) {
		return ENROLLED;
	} else if (waitlist_position(MAJOR_WAITLIST, s) != -1) {
		return MAJOR_WAITLIST;
	} else if (waitlist_position(OTHER_WAITLIST, s) != -1) {
		return OTHER_WAITLIST;
	} else {
		return NONE;
	}
}

/*
 * @parameter	ENROLLMENT_STATUS	status	The list to print. ENROLLED,
 * 						MAJOR_WAITLIST, OTHER_WAITLIST
 * @return	none
 *
 * Prints the roster (ENROLLED) or waitlist (either MAJOR_WAITLIST or
 * OTHER_WAITLIST) in the following form (names should be in order of priority
 * from the waitlist):
 * 1. student.name
 * 2. student.name
 * etc.
 */
void IsisCourse::print_list(ENROLLMENT_STATUS status)
{
        Queue *waitlist_queue;
        Queue  temp_queue;

        if (status == ENROLLED) {
                roster.print_class();
                return;
        }
        if (status == MAJOR_WAITLIST) {
                waitlist_queue = &major_waitlist;
        } else {
                waitlist_queue = &other_waitlist;
        }
        // now handle printing the queue
        int count = 0;
        while(!waitlist_queue->is_empty()) {
        	count++;
        	Student s = waitlist_queue->dequeue();
        	std::cout << count << ". " << s.name << "\n";
        	temp_queue.enqueue(s);
        }
        while(!temp_queue.is_empty()) {
        	waitlist_queue->enqueue(temp_queue.dequeue());
        }
}
