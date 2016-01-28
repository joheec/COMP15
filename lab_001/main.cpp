/* 
 * Simple HookBook test.
 * - Adds a bunch of pirates to the book, 
 * - makes every pirate have all previous priates as friends
 *   (e. g., pirate number 4 is friends with pirates 0, 1, 2, 3)
 * - prints result
 *
 * This should NOT be the only test you use, and it should certainly 
 * not be the first test.
 * 
 */

#include <iostream>
#include <string>

#include "hookbook.h"

using namespace std;

int main()
{
    
        string   color[] = {"red",       "blue",         "grey", "white", 
                            "orange",    "burnt sienna", "puse", "black",
                            "cerulean",  "dandelion",    "cyan", "mauve"};
        HookBook hb;
        int      size = sizeof(color) / sizeof(string); // Tricky!  Only works
                                                        // for local arrays.
    
        for (int i = 0; i < size; i++) {
                hb.addPirate(i, color[i] + " beard");
        }
        for (int i = 0; i < size; i++) {
                for (int j = 0; j < i; j++) {
                        if (i != j) {
                                hb.addFriend(i, j);
                        }
                }
        }
        hb.print();
    
        return 0;
}
