/*
 * A simple program that uses hands of cards.
 *
 * It just does some simple tests.
 * You should write other tests, which you can include here, and you
 * can write other test files.
 *
 * If you're doing well and ambitious, are encouraged to write a real
 * application, including one that plays a game.  Have fun with it!
 *
 */

#include <iostream>
#include <cstdlib>
#include <time.h>


#include "hand.h"
#include "List_dynamic_array.h"

#define SEED_RANDOM false

int main(int argc, char *argv[])
{
        // We're not using command line arguments, so the following makes
        // compiler warnings go away.
        (void) argc;
        (void) argv;


	if (SEED_RANDOM) srand(time(NULL));
	
	List_dynamic_array test1;


	Hand deck, hand1, hand2;

	deck.create_deck();
	deck.print_hand();

	Card c;
	c.set_suit(HEART);
	c.set_rank(THREE);

	deck.remove_card(c);

	deck.shuffle();
	deck.print_hand_int();

	for (int i = 0; i < 5 ; i++) {
		deck.deal_card_from_top(hand1);
		deck.deal_card_from_top(hand2);
	}
//	hand1.order_hand();
//	hand2.order_hand();
//	deck.print_hand();
//	hand1.print_hand();
//	hand2.print_hand();
	
	return 0;
}
