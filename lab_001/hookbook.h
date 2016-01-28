/* 
 * HookBook Social Network
 * COMP 15  Lab 1
 */

#ifndef HOOKBOOK_H
#define HOOKBOOK_H

#include <string>

class HookBook
{

public:
        HookBook();   /* constructor */

        /* 
         * Adds a new pirate to HookBook, probably the member should
         * be created by the hookbook system, for now it is sent in
         * from main as an integer pirate ID.
         * The pirate starts out with no friends.
         * Return false if memberID is in use.
         */
        bool addPirate(int memberID, std::string memberName);

        /* 
         * Prints the values in the list in ascending order.
         *
         * This method is "const", which is a promise to the compiler
         * that it won't change the value of any private variables. 
         */
        void print() const;

        /* The function you will write */
        /* Add a new friend to memID's friend list.
         * Return false if there is no pirate with ID memID
         */
        bool addFriend(int memID, int friendID);


        //return bool true when works
    
        ~HookBook();   /* destructor */
        
private:
        struct Pirate
        {
                int          memberID;
                std::string  name;
                int         *friendList;
                int          friendCount;
                int          friendCapacity;

        };

        static const int INIT_CAPACITY = 5; 

        Pirate *hbook;
        int     pirateCount;
        int     pirateCapacity;

        void    initializePirate(int         pirateCount,
                                 int         memberID,
                                 std::string memberName);
        void    ensurePirateCapacity(int desiredCapacity);
        int     pirateIndex(int memID);

        void	ensureFriendCapacity(int memID, int desiredCapacity);
};

#endif
