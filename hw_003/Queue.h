/*
 * File: Queue.h
 * Name: Johee Chung
 * Due: February 29, 2016
 * Assignment: Homework 3 / ISIS Course
 * Class: COMP 15
 *
 * This is the header for a Queue with the following methods:
 * void enqueue(Student c);
 * Student dequeue();
 * bool is_empty();
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Student.h"

class Queue {
public:
        Queue();
        ~Queue();

        void enqueue(Student s);
        Student dequeue();

        bool is_empty();

private:
        struct Student_Node {
        	Student student;
        	Student_Node * next;
        };
        Student_Node * front;
};

#endif /* QUEUE_H_ */
