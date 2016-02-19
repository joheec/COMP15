/*
 * Set.cpp
 *
 * Add your code below.  Do not change the print function.
 *
 */

#include <iostream>
#include "Set.h"

using namespace std;


void Set::print_class()
{
        for (int i = 0; i < class_size; i++) {
                Student s = set_array[i];
                cout << s.name << ", "
                                << (s.major ? "Major" : "Non-Major")
                                << "\n";
        }
}

// TODO --- students complete this class
