/*
 * File: Student.h
 * Name: Johee Chung
 * Due: February 29, 2016
 * Assignment: Homework 3 / ISIS Course
 * Class: COMP 15
 *
 * This header file defines a Student struct.
 *
 * Students have a name (string) and a bool that indicates whether
 * the Student is a major (true) or a non-major (false).
 *
 * You may not have seen constructors in a struct before,
 * but you can use them in C++.
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

struct Student {
        Student()
        {
                name  = "";
                major = false;
        }

        Student(std::string n, bool maj)
        {
                name  = n;
                major = maj;
        }
        std::string name;
        bool        major;
};

#endif /* STUDENT_H_ */
