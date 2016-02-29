/*
 * File: IsisCourse.h
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
 *
 */

#ifndef ISISCOURSE_H_
#define ISISCOURSE_H_

#include "Student.h"
#include "Set.h"
#include "Queue.h"

class IsisCourse {
public:
        // the status of a student
        // NONE: not enrolled in the class or on a waitlist
        // ENROLLED: on the class roster (i.e., in the course)
        // MAJOR_WAITLIST: on the majors' waitlist
        // OTHER_WAITLIST: on the non-majors' waitlist
        enum ENROLLMENT_STATUS {NONE, ENROLLED, MAJOR_WAITLIST, OTHER_WAITLIST};

        IsisCourse();
        IsisCourse(int init_capacity);
        ~IsisCourse();

        void set_class_cap(int cap);
        int get_class_cap();

        ENROLLMENT_STATUS enroll_student(Student s);
        bool drop_student(Student s);
        void update_enrollments();

        int get_roster_size();
        int waitlist_position(ENROLLMENT_STATUS status, Student s);
        ENROLLMENT_STATUS status(Student s);
        void print_list(ENROLLMENT_STATUS status);
private:
        Set roster;               // the roster for the course
        Queue major_waitlist;     // the waitlist for majors
        Queue other_waitlist;     // the waitlist for non-majors
        int class_capacity;       // the class capacity
};

#endif /* ISISCOURSE_H_ */
