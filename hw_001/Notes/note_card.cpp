#include <iostream>
#include <sstream>
#include <cstdlib>

#include "card.h"

using namespace std;

Card::Card()
{
	suit = CLUB;
	rank = ACE;
}

Card::Card(char r, char s)
{
	switch(s) {
		case 'C' :
			suit = CLUB;
			break;
		case 'H' :
			suit = HEART;
			break;
		case 'D' :
			suit = DIAMOND;
			break;
		case 'S' : 
			suit = SPADE;
			break;
	}

	switch (r) {
		case 'T' :
			rank = TEN;
			break;
		case 'J' :
			rank = JACK
			break;
		case 'Q' :
			rank = QUEEN;
			break;
		case 'K' :
			rank = KING;
			break;
		case 'A' :
			rank = ACE;
			break;
		default : 
			rank = (Rank)()
	}
}


//REMEMBER DEFAULTS
	Card();
	Card(char r, char s);
	~Card();

	void print_card();
	//prints integer value of card
	void print_card_int();

	Suit get_suit() const;
	void set_suit(Suit s);

	Rank get_rank() const;
	void set_rank();

	bool same_card(Card c);
	//returns integer value of the card
	int card_int();