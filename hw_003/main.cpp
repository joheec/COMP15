/********** Testing main13.cpp **********/
// Test: Original main provided with assignment
//main13.cpp Passed!
//Running valgrind to check for memory leaks.
//valgrind reported errors!
//---------- test program code: main13.cpp ----------
// Test: Original main provided with assignment
/*
 * main.cpp
 *
 *  Created on: Sep 21, 2014
 *      Author: Chris Gregg
 */
#include<iostream>
#include<string>

#include "Student.h"
#include "Set.h"
#include "Queue.h"
#include "IsisCourse.h"

using namespace std;

#define NUM_STUDENTS 11

void print_student_status(IsisCourse::ENROLLMENT_STATUS status) {
	if (status == IsisCourse::NONE) {
		cout << "Not enrolled or on a waitlist\n";
	}
	if (status == IsisCourse::ENROLLED) {
		cout << "Enrolled.\n";
	}
	if (status == IsisCourse::MAJOR_WAITLIST) {
		cout << "Major waitlist.\n";
	}
	if (status == IsisCourse::OTHER_WAITLIST) {
		cout << "Other waitlist.\n";
	}
}

void print_all_status(IsisCourse &course) {
	cout << "Class Size: " << course.get_roster_size() << "\n";
	cout << "Enrolled in Class:\n";
	course.print_list(IsisCourse::ENROLLED);
	cout << "\n";

	cout << "On Major Waitlist:\n";
	course.print_list(IsisCourse::MAJOR_WAITLIST);
	cout << "\n";

	cout << "On Other Waitlist:\n";
	course.print_list(IsisCourse::OTHER_WAITLIST);
	cout << "\n";
}

void print_all_students(Student *students, IsisCourse *course) {
	for (int i=0;i<NUM_STUDENTS;i++) {
			cout << students[i].name << " status: ";
			print_student_status(course->status(students[i]));
		}
}

int main() {
	Student students[NUM_STUDENTS] = {
			Student("Green,Alice",true),
			Student("Blue,Misha",false),
			Student("Yellow,John",false),
			Student("Orange,Friya",true),
			Student("Pink,Julia",true),
			Student("Black,Henry",false),
			Student("Cyan,Barnaby",true),
			Student("Red,Justin",true),
			Student("Violet,Chester",false),
			Student("Fuchsia,Rebecca",false),
			Student("Beige,Barker",true)
	};
	IsisCourse comp15(3); // a new course with an enrollment cap of 3

	for (int i=0;i<NUM_STUDENTS-1;i++) { // enroll all but the last
		cout << "Class size: " << comp15.get_roster_size() << "\n";

		cout << "Enrolling " << students[i].name << " (" <<
				(students[i].major ? "major" : "non-major")
				<< ")\n\t";
		IsisCourse::ENROLLMENT_STATUS status;
		status = comp15.enroll_student(students[i]);
		print_student_status(status);
		cout << "\n";
	}
	cout << "\n";

	print_all_status(comp15);
	print_all_students(students,&comp15);

	cout << "\nIncreasing capacity to 7.\n";

	comp15.set_class_cap(7);

	print_all_status(comp15);
	print_all_students(students,&comp15);

	cout << "\nDone!\n";

	return 0;
}
//---------- end test program code ----------

//==22759== Memcheck, a memory error detector
//==22759== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
//==22759== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
//==22759== Command: ./hw3
//==22759==
//Class size: 0
//Enrolling Green,Alice (major)
//	Enrolled.
//
//Class size: 1
//Enrolling Blue,Misha (non-major)
//	Other waitlist.
//
//Class size: 1
//Enrolling Yellow,John (non-major)
//	Other waitlist.
//
//Class size: 1
//Enrolling Orange,Friya (major)
//	Enrolled.
//
//Class size: 2
//Enrolling Pink,Julia (major)
//	Enrolled.
//
//Class size: 3
//Enrolling Black,Henry (non-major)
//	Other waitlist.
//
//Class size: 3
//Enrolling Cyan,Barnaby (major)
//	Major waitlist.
//
//Class size: 3
//Enrolling Red,Justin (major)
//	Major waitlist.
//
//Class size: 3
//Enrolling Violet,Chester (non-major)
//	Other waitlist.
//
//Class size: 3
//Enrolling Fuchsia,Rebecca (non-major)
//	Other waitlist.
//
//
//Class Size: 3
//Enrolled in Class:
//Green,Alice, Major
//Orange,Friya, Major
//Pink,Julia, Major
//
//On Major Waitlist:
//1. Cyan,Barnaby
//2. Red,Justin
//
//On Other Waitlist:
//1. Blue,Misha
//2. Yellow,John
//3. Black,Henry
//4. Violet,Chester
//5. Fuchsia,Rebecca
//
//Green,Alice status: Enrolled.
//Blue,Misha status: Other waitlist.
//Yellow,John status: Other waitlist.
//Orange,Friya status: Enrolled.
//Pink,Julia status: Enrolled.
//Black,Henry status: Other waitlist.
//Cyan,Barnaby status: Major waitlist.
//Red,Justin status: Major waitlist.
//Violet,Chester status: Other waitlist.
//Fuchsia,Rebecca status: Other waitlist.
//Beige,Barker status: Not enrolled or on a waitlist
//
//Increasing capacity to 7.
//Class Size: 7
//Enrolled in Class:
//Green,Alice, Major
//Orange,Friya, Major
//Pink,Julia, Major
//Cyan,Barnaby, Major
//Red,Justin, Major
//Blue,Misha, Non-Major
//Yellow,John, Non-Major
//
//On Major Waitlist:
//
//On Other Waitlist:
//1. Black,Henry
//2. Violet,Chester
//3. Fuchsia,Rebecca
//
//Green,Alice status: Enrolled.
//Blue,Misha status: Enrolled.
//Yellow,John status: Enrolled.
//Orange,Friya status: Enrolled.
//Pink,Julia status: Enrolled.
//Black,Henry status: Other waitlist.
//Cyan,Barnaby status: Enrolled.
//Red,Justin status: Enrolled.
//Violet,Chester status: Other waitlist.
//Fuchsia,Rebecca status: Other waitlist.
//Beige,Barker status: Not enrolled or on a waitlist
//
//Done!
//==22759==
//==22759== HEAP SUMMARY:
//==22759==     in use at exit: 3,618 bytes in 147 blocks
//==22759==   total heap usage: 161 allocs, 14 frees, 4,003 bytes allocated
//==22759==
//==22759== LEAK SUMMARY:
//==22759==    definitely lost: 1,032 bytes in 43 blocks
//==22759==    indirectly lost: 2,586 bytes in 104 blocks
//==22759==      possibly lost: 0 bytes in 0 blocks
//==22759==    still reachable: 0 bytes in 0 blocks
//==22759==         suppressed: 0 bytes in 0 blocks
//==22759== Rerun with --leak-check=full to see details of leaked memory
//==22759==
//==22759== For counts of detected and suppressed errors, rerun with: -v
//==22759== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 5 from 5)
//********** Done Testing main13.cpp **********

//********** Testing main2.cpp **********
//// Test: Dequeuing from a queue
//main2.cpp Passed!
//Running valgrind to check for memory leaks.
//valgrind reported errors!
//---------- test program code: main2.cpp ----------
// Test: Dequeuing from a queue
/*
 * main2.cpp
 *
 *  Created on: Oct 1, 2014
 *      Author: chrisgregg
 */
//#include <iostream>
//#include <cstdlib>
//#include <time.h>
//
//#include "Queue.h"
//
//#define NUM_STUDENTS 11
//
//using namespace std;
//
//void print_queue_status(Queue &q) {
//	cout << "Queue is " << (q.is_empty() ? "empty.\n" : "not empty.\n");
//}
//
//int main() {
//	Student students[NUM_STUDENTS] = {
//			Student("Green,Alice",true),
//			Student("Blue,Misha",false),
//			Student("Yellow,John",false),
//			Student("Orange,Friya",true),
//			Student("Pink,Julia",true),
//			Student("Black,Henry",false),
//			Student("Cyan,Barnaby",true),
//			Student("Red,Justin",true),
//			Student("Violet,Chester",false),
//			Student("Fuchsia,Rebecca",false),
//			Student("Beige,Barker",true)
//	};
//	Queue q;
//
//	for (int i=0;i<NUM_STUDENTS;i++) {
//		q.enqueue(students[i]);
//	}
//
//	for (int i=0;i<NUM_STUDENTS;i++) {
//		Student s = q.dequeue();
//		print_queue_status(q);
//		cout << "Student name: " << s.name <<
//				". Major? " <<
//				(s.major ? "Yes.\n" : "No.\n");
//	}
//	return 0;
//}
//---------- end test program code ----------

//==23399== Memcheck, a memory error detector
//==23399== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
//==23399== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
//==23399== Command: ./hw3
//==23399==
//Queue is not empty.
//Student name: Green,Alice. Major? Yes.
//Queue is not empty.
//Student name: Blue,Misha. Major? No.
//Queue is not empty.
//Student name: Yellow,John. Major? No.
//Queue is not empty.
//Student name: Orange,Friya. Major? Yes.
//Queue is not empty.
//Student name: Pink,Julia. Major? Yes.
//Queue is not empty.
//Student name: Black,Henry. Major? No.
//Queue is not empty.
//Student name: Cyan,Barnaby. Major? Yes.
//Queue is not empty.
//Student name: Red,Justin. Major? Yes.
//Queue is not empty.
//Student name: Violet,Chester. Major? No.
//Queue is not empty.
//Student name: Fuchsia,Rebecca. Major? No.
//Queue is empty.
//Student name: Beige,Barker. Major? Yes.
//==23399==
//==23399== HEAP SUMMARY:
//==23399==     in use at exit: 667 bytes in 22 blocks
//==23399==   total heap usage: 22 allocs, 0 frees, 667 bytes allocated
//==23399==
//==23399== LEAK SUMMARY:
//==23399==    definitely lost: 24 bytes in 1 blocks
//==23399==    indirectly lost: 643 bytes in 21 blocks
//==23399==      possibly lost: 0 bytes in 0 blocks
//==23399==    still reachable: 0 bytes in 0 blocks
//==23399==         suppressed: 0 bytes in 0 blocks
//==23399== Rerun with --leak-check=full to see details of leaked memory
//==23399==
//==23399== For counts of detected and suppressed errors, rerun with: -v
//==23399== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 5 from 5)
//********** Done Testing main2.cpp **********


//********** Testing main3.cpp **********
//// Test: Enqueue/Dequeue from Queue
//main3.cpp Passed!
//Running valgrind to check for memory leaks.
//valgrind reported errors!
//---------- test program code: main3.cpp ----------
// Test: Enqueue/Dequeue from Queue
/*
 * main3.cpp
 *
 *  Created on: Oct 1, 2014
 *      Author: chrisgregg
 */
//#include <iostream>
//#include <cstdlib>
//#include <time.h>
//
//#include "Queue.h"
//
//#define NUM_STUDENTS 11
//
//using namespace std;
//
//void print_queue_status(Queue &q) {
//	cout << "Queue is " << (q.is_empty() ? "empty.\n" : "not empty.\n");
//}
//
//int main() {
//	Student students[NUM_STUDENTS] = {
//			Student("Green,Alice",true),
//			Student("Blue,Misha",false),
//			Student("Yellow,John",false),
//			Student("Orange,Friya",true),
//			Student("Pink,Julia",true),
//			Student("Black,Henry",false),
//			Student("Cyan,Barnaby",true),
//			Student("Red,Justin",true),
//			Student("Violet,Chester",false),
//			Student("Fuchsia,Rebecca",false),
//			Student("Beige,Barker",true)
//	};
//	Queue q;
//
//	for (int i=0;i<NUM_STUDENTS;i++) {
//		q.enqueue(students[i]);
//		Student s = q.dequeue();
//		print_queue_status(q);
//		cout << "Student name: " << s.name <<
//				". Major? " <<
//				(s.major ? "Yes.\n" : "No.\n");
//	}
//
//	return 0;
//}
//---------- end test program code ----------

//==23716== Memcheck, a memory error detector
//==23716== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
//==23716== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
//==23716== Command: ./hw3
//==23716==
//Queue is empty.
//Student name: Green,Alice. Major? Yes.
//Queue is empty.
//Student name: Blue,Misha. Major? No.
//Queue is empty.
//Student name: Yellow,John. Major? No.
//Queue is empty.
//Student name: Orange,Friya. Major? Yes.
//Queue is empty.
//Student name: Pink,Julia. Major? Yes.
//Queue is empty.
//Student name: Black,Henry. Major? No.
//Queue is empty.
//Student name: Cyan,Barnaby. Major? Yes.
//Queue is empty.
//Student name: Red,Justin. Major? Yes.
//Queue is empty.
//Student name: Violet,Chester. Major? No.
//Queue is empty.
//Student name: Fuchsia,Rebecca. Major? No.
//Queue is empty.
//Student name: Beige,Barker. Major? Yes.
//==23716==
//==23716== HEAP SUMMARY:
//==23716==     in use at exit: 667 bytes in 22 blocks
//==23716==   total heap usage: 22 allocs, 0 frees, 667 bytes allocated
//==23716==
//==23716== LEAK SUMMARY:
//==23716==    definitely lost: 264 bytes in 11 blocks
//==23716==    indirectly lost: 403 bytes in 11 blocks
//==23716==      possibly lost: 0 bytes in 0 blocks
//==23716==    still reachable: 0 bytes in 0 blocks
//==23716==         suppressed: 0 bytes in 0 blocks
//==23716== Rerun with --leak-check=full to see details of leaked memory
//==23716==
//==23716== For counts of detected and suppressed errors, rerun with: -v
//==23716== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 5 from 5)
//********** Done Testing main3.cpp **********
