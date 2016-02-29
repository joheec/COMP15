/*
 * File: Set.h
 * Name: Johee Chung
 * Due: February 29, 2016
 * Assignment: Homework 3 / ISIS Course
 * Class: COMP 15
 *
 * This class is a Set, which holds Students.
 * The Set has the following public methods:
 * bool Set::add(Student s)
 * bool drop(Student s);
 * bool is_enrolled(Student s);
 * void print_class();
 * int size();
 */

#ifndef SET_H_
#define SET_H_

#include "Student.h"

class Set {
public:
        Set();
        ~Set();

        bool add        (Student s);
        bool drop       (Student s);
        bool is_enrolled(Student s);
        void print_class();
        int size        ();

private:
        struct Student_Node
        {
        	Student student;
        	Student_Node * next;
        };
        Student_Node * front;
        int class_size;
};

#endif /* SET_H_ */
