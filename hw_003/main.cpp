/*
 * main.cpp
 *
 *  Created on: Sep 21, 2014
 *      Author: Chris Gregg
 */
#include<iostream>

#include "Student.h"
#include "IsisCourse.h"
#include <cassert>

//TODO temp for testing
#include "Set.h"
#include "Queue.h"

using namespace std;

//static const int NUM_STUDENTS = 11;

//void print_student_status(IsisCourse::ENROLLMENT_STATUS status)
//{
//        if (status == IsisCourse::NONE) {
//                cout << "Not enrolled or on a waitlist\n";
//        }
//        if (status == IsisCourse::ENROLLED) {
//                cout << "Enrolled.\n";
//        }
//        if (status == IsisCourse::MAJOR_WAITLIST) {
//                cout << "Major waitlist.\n";
//        }
//        if (status == IsisCourse::OTHER_WAITLIST) {
//                cout << "Other waitlist.\n";
//        }
//}
//
//void print_all_status(IsisCourse &course)
//{
//        cout << "Class Size: " << course.get_roster_size() << "\n";
//        cout << "Enrolled in Class:\n";
//        course.print_list(IsisCourse::ENROLLED);
//        cout << "\n";
//
//        cout << "On Major Waitlist:\n";
//        course.print_list(IsisCourse::MAJOR_WAITLIST);
//        cout << "\n";
//
//        cout << "On Other Waitlist:\n";
//        course.print_list(IsisCourse::OTHER_WAITLIST);
//        cout << "\n";
//}
//
//void print_all_students(Student *students, IsisCourse *course)
//{
//        for (int i = 0; i < NUM_STUDENTS; ++i) {
//                        cout << students[i].name << " status: ";
//                        print_student_status(course->status(students[i]));
//                }
//}
//
//bool test_set()
//{
//	Set * temp_set = new Set;
//
//	Student students[3] = {
//		Student("Chung, Johee",true),
//		Student("Green,Alice", true),
//		Student("Blue,Misha", false),
//	};
//
//	//adding students
//	for(int i = 0; i < 2; i++) {
//		temp_set->add(students[i]);
//	}
//
//	temp_set->print_class();
//
//	//only 1 node
//	temp_set->add(students[0]);
//	cout << "\nBefore 1 node: " << temp_set->size() << "\n";
//	temp_set->print_class();
//	temp_set->drop(students[0]);
//	cout << "\nAfter 1 node: " << temp_set->size() << "\n";
//	temp_set->print_class();
//
//	//first node
//	for(int i = 0; i < 3; i++) {
//		temp_set->add(students[i]);
//	}
//	cout << "\nBefore first node: " << temp_set->size() << "\n";
//	temp_set->print_class();
//	temp_set->drop(students[0]);
//	cout << "\nAfter first node: " << temp_set->size() << "\n";
//	temp_set->print_class();
//
//	//last node
//	temp_set->add(students[0]);
//	cout << "\nBefore last node: " << temp_set->size() << "\n";
//	temp_set->print_class();
//	temp_set->drop(students[0]);
//	cout << "\nAfter first node: " << temp_set->size() << "\n";
//	temp_set->print_class();
//
//	//"middle" node
//	temp_set->add(students[0]);
//	cout << "\nBefore middle node: " << temp_set->size() << "\n";
//	temp_set->print_class();
//	temp_set->drop(students[2]);
//	cout << "\nAfter middle node: " << temp_set->size() << "\n";
//	temp_set->print_class();
//
////	//not enrolled
////	cerr << "is enrolled " << temp_set->is_enrolled(students[0]);
////	//is enrolled
////	cerr << "\nnot enrolled " << temp_set->is_enrolled(students[2]);
//	return true;
//}
//
//bool test_queue()
//{
//	Student s[2] = {
//		Student("Johee Chung", true),
//		Student("Steph Alkatib", false)
//	};
//
//	Queue * q = new Queue;
//
//	for(int i = 0; i < 2; i++) {
//		q->enqueue(s[i]);
//	}
//
//	for(int i = 0; i < 2; i++) {;
//		cerr << q->dequeue().name << "\n";
//	}
//
//	return q->is_empty();
//}

int main()
{
//	if(test_set()) {
//		cout << "\nWorks!";
//	}
//
//	if(test_queue()) {
//		cerr << "Works!\n";
//	}


//        Student students[NUM_STUDENTS] = {
//                        Student("Green,Alice",     true),
//                        Student("Blue,Misha",      false),
//                        Student("Yellow,John",     false),
//                        Student("Orange,Friya",    true),
//                        Student("Pink,Julia",      true),
//                        Student("Black,Henry",     false),
//                        Student("Cyan,Barnaby",    true),
//                        Student("Red,Justin",      true),
//                        Student("Violet,Chester",  false),
//                        Student("Fuchsia,Rebecca", false),
//                        Student("Beige,Barker",    true)
//        };
//        IsisCourse comp15(3); // a new course with an enrollment cap of 3
//
//        for (int i = 0; i < NUM_STUDENTS - 1; ++i) { // enroll all but the last
//                cout << "Class size: " << comp15.get_roster_size() << "\n";
//
//                cout << "Enrolling " << students[i].name << " (" <<
//                                (students[i].major ? "major" : "non-major")
//                                << ")\n\t";
//                IsisCourse::ENROLLMENT_STATUS status;
//                status = comp15.enroll_student(students[i]);
//                print_student_status(status);
//                cout << "\n";
//        }
//        cout << "\n";
//
//        print_all_status(comp15);
//        print_all_students(students, &comp15);
//
//        cout << "\nIncreasing capacity to 7.\n";
//
//        comp15.set_class_cap(7);
//
//        print_all_status(comp15);
//        print_all_students(students, &comp15);
//
//        cout << "\nDone!\n";

        return 0;
}
