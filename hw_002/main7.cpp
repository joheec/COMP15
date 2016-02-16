#include <iostream>
#include <cstdlib>
#include <time.h>

#include "hand.h"

using namespace std;

int main() {
	List_linked_list ll;

	Card c('A','D');

	ll.insert_at_index(c,0);

	c.set_suit(HEART);
	c.set_rank(TEN);
	ll.insert_at_index(c,0);

	c.set_suit(SPADE);
	c.set_rank(FIVE);
	ll.insert_at_index(c,0);

	c.set_suit(CLUB);
	c.set_rank(TWO);
	ll.insert_at_index(c,0);

	c.set_rank(NINE);
	ll.insert_at_index(c,0);

	c.set_suit(HEART);
	c.set_rank(FOUR);
	ll.insert_at_index(c,0);
	ll.print_list();

	int rand_order[6] = {1,0,3,1,1,0};
	for (int i=0;i<6;i++) {
		cout << "Removed ";
		ll.remove_from_index(rand_order[i]).print_card();
		cout << "\n";
		ll.print_list();
	}

	return 0;
}
