/*
 * Queue.h
 *
 * This is the header for a Queue with the following methods:
 * void enqueue(Student c);
 * Student dequeue();
 * bool is_empty();
 *
 * You may add private members to this class, but you cannot change
 * the public section.
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Student.h"

class Queue {
public:
        // constructor
        Queue();

        // destructor
        ~Queue();

        // enqueue a student onto at the back of the queue
        void enqueue(Student stu);

        // dequeue a student from the front of the queue
        Student dequeue();

        // returns true if there are no elements in the
        // queue, false if the queue has elements
        bool is_empty();

private:
        struct Student_Node {
        	Student student;
        	Student_Node * next;
        };
        Student_Node * front;
};

#endif /* QUEUE_H_ */
