
/*
 * Implementation of the HookBook class
 *
 * COMP 15  Lab 1
 *
 * There are two functions you must write.  You may create as many 
 * private helper functions (or local helper functions) as you like,
 * but you must NOT change the public part of the HookBook class, the
 * actual interface in hookbook.h.  New private member functions
 * declarations will have to be added to the .h file, of course.
 */
#include <iostream>
#include <string>

#include "hookbook.h"

using std::string;
using std::cout;
using std::endl;

/*
 * return larger of a and b
 */
static inline int max(int a, int b)
{
        return (a < b) ? b : a;
}

/* constructor */
HookBook::HookBook()
{
        hbook           = new Pirate[INIT_CAPACITY];
        pirateCapacity  = INIT_CAPACITY;
        pirateCount     = 0;
}

/* destructor */
HookBook::~HookBook()
{
	for (int i = 0; i < pirateCount; i++) {

			delete [] hbook[i].friendList;

	}
	delete [] hbook;
}

/* 
 * Adds a new pirate to HookBook, probably the member should
 * be created by the hookbook system, for now it is sent in
 * from main.
 *
 * If we run out of memory, throws bad_alloc exception.
 * We could catch the exception and return false in that case.
 */
bool HookBook::addPirate(int memberID, string memberName)
{
        if (pirateIndex(memberID) != -1)   // ensure ID not in use
                return false;   
        ensurePirateCapacity(pirateCount + 1);
        initializePirate(pirateCount, memberID, memberName);
        pirateCount++;
        return true;
}

/* Prints the values in the list in ascending order. */
/* This method is "const", which is a promise to the compiler
 * that it won't change the value of any private variables. 
 */
void HookBook::print() const
{
        cout << "There are " << pirateCount
             << " pirates in the system." << endl;

        for (int i = 0; i < pirateCount; i++) {
                cout << "Pirate: "         << hbook[i].name
                     << " with memberID: " << hbook[i].memberID
                     << " has friends ";
        
                /* print pirate i's friend list */
                for (int j = 0; j < hbook[i].friendCount; j++) {
                        cout << hbook[i].friendList[j] << " ";
                }
                cout << endl;
        }
}

/*
 * The function you will write
 * Note:  The list will be empty the first time through
 * Throw bad_alloc exception if out of space.
 */
bool HookBook::addFriend(int memID, int friendID)
{

	//go through pirate array to find memID. Return false if no pirate with ID
	if(pirateIndex(memID) == -1) {
		return false;
	}
	//check if friend is already set in the pirate's friend array.


        int index = -1;
        for (int i = 0; i < hbook[pirateIndex(memID)].friendCount; i++) {
                if (hbook[pirateIndex(memID)].friendList[i] == friendID) {
                        index = i;
                }
        }
        if(index != -1){
        	return false;
        }

	//check if friend array is at capacity

	ensureFriendCapacity(memID, hbook[pirateIndex(memID)].friendCount + 1);

	//add to friend list
	hbook[pirateIndex(memID)].friendList[hbook[pirateIndex(memID)].friendCount - 1] = friendID;

	//add to friend count
	++hbook[pirateIndex(memID)].friendCount;
	return true;

}

/**********************************************************************/
/*                      Private member functions                      */
/*                                                                    */
/* The first two are given as examples, and you need to complete the  */
/* the second one.                                                    */
/* Feel free to add more.                                             */
/* Just remember to add them to the .h file, too.                     */
/**********************************************************************/

/*
 * friendList is a pointer to a dynamically allocated array.
 * If it is null the pirate has no friends.
 */
void HookBook::initializePirate(int pirateCount,
                                int memberID,
                                string memberName)
{
        hbook[pirateCount].memberID       = memberID;
        hbook[pirateCount].name           = memberName;
        hbook[pirateCount].friendList     = NULL;
        hbook[pirateCount].friendCount    = 0;
        hbook[pirateCount].friendCapacity = 0;
}

/*
 * Makes sure there are at least desiredCapacity slots in the array.
 * If there aren't already, it expands the array to be big enough.
 * If the expansion fails (out of memory), new will throw a
 * bad_alloc exception.
 */
void HookBook::ensurePirateCapacity(int desiredCapacity)
{
        /* If there is already enough space, do nothing */
        if (pirateCapacity >= desiredCapacity)
                return;

        /* Otherwise, expand the array */

        int     newCapacity = max(desiredCapacity, pirateCapacity * 2);
        Pirate *temp        = new Pirate[newCapacity];

        /* Copy existing data to new space */
        for (int i = 0; i < pirateCount; i++) {
                temp[i] = hbook[i];
        }
        delete [] hbook;
        hbook          = temp;
        pirateCapacity = newCapacity;
}

/*
 * Return index of pirate with given member ID
 * Return -1 if the pirate is not found (i. e., memID is invalid)
 */
int HookBook::pirateIndex(int memID)
{
        int index = -1;
        for (int i = 0; i < pirateCount; i++) {
                if (hbook[i].memberID == memID) {
                        index = i;
                }
        }
        return index;
}

/* 
 * Make sure there are at least desiredCapacity slots in the array.
 * If there aren't, expand the array so there are.
 * If there is not enough memory, new throws a bad_alloc exception.
 */
void HookBook::ensureFriendCapacity(int pirateIdx, int desiredCapacity)
{
        // If there is already enough space, there's nothing to do
        if (hbook[pirateIdx].friendCapacity >= desiredCapacity)
                return;
        
        // the "+ 2" in the new capacity below means that this will
        // work when the capacity is 0, i. e., for the first friend.

        int  currentCapacity = hbook[pirateIdx].friendCapacity;
        int  newCapacity     = max(desiredCapacity, (currentCapacity * 2) + 2);
        int *temp            = new int[newCapacity];

        /* Copy the old friend list data */
        for (int i = 0; i < hbook[pirateIdx].friendCount; i++) {
                temp[i] = hbook[pirateIdx].friendList[i];
        }
        delete [] hbook[pirateIdx].friendList;
        hbook[pirateIdx].friendList     = temp;
        hbook[pirateIdx].friendCapacity = newCapacity;
}
