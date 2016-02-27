/*
 * IsisCourse.cpp
 *
 */

#include <iostream>
#include <exception>
#include <stdexcept>
#include <cassert>

using std::runtime_error;

#include "IsisCourse.h"

IsisCourse::IsisCourse()
{
        class_capacity = 0; // no students allowed in yet
}

IsisCourse::IsisCourse(int init_capacity)
{
	class_capacity = init_capacity;
}

IsisCourse::~IsisCourse()
{
        // nothing to do
}

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
 * See the enrollment logic from the assignment handout or
 * the IsisCourse.h file!
 */
IsisCourse::ENROLLMENT_STATUS IsisCourse::enroll_student(Student s)
{
	// Attempts to enroll a student into the class.
	// Majors go directly into the class, and non-majors
	// go directly onto the waitlist, even if there is space
	// in the class.
	// Simplification:  You do not need to check if a student is
	// on a waitlist already before placing that student onto
	// the appropriate waitlist.

	if(s.major) {
		if(!roster.add(s)) {
			major_waitlist.enqueue(s);
			return MAJOR_WAITLIST;
		} else {
			return ENROLLED;
		}
	} else {
		other_waitlist.enqueue(s);
		return OTHER_WAITLIST;
	}
}

bool IsisCourse::drop_student(Student s)
{
        bool found_student = false;     // if we find the student to drop
        // TODO: Student writes code here
        (void) s;

        // if we dropped a student, there should be room on
        // the roster
//        update_enrollments();
        return found_student;
}

int IsisCourse::waitlist_position(ENROLLMENT_STATUS status, Student s)
{
        // TODO: Student writes code here
	(void) status;
	(void) s;
	return 3;
}

/* 
 * Return an ENROLLMENT_STATUS that says which list
 * (or none) that the student is on.
 */
IsisCourse::ENROLLMENT_STATUS IsisCourse::status(Student s)
{
        // TODO: Student writes code here
	(void) s;
	return NONE;
}

void IsisCourse::print_list(ENROLLMENT_STATUS status)
{
//        Queue *waitlist_queue;
//        Queue  temp_queue;
//
//        if (status == ENROLLED) {
//                roster.print_class();
//                return;
//        }
//        if (status == MAJOR_WAITLIST) {
//                waitlist_queue = &major_waitlist;
//        } else {
//                waitlist_queue = &other_waitlist;
//        }
        // now handle printing the queue

        // TODO: Student writes code here
	(void) status;
}

/*
 * Put students from the waitlists into the class
 * in priority (majors first, then others), up to
 * the class capacity.
 */
void IsisCourse::update_enrollments()
{
        // TODO: Student writes code here
}
