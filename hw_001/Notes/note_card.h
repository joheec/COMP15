// 52 card deck
// Card = Rank + Suit
// Default = Ace + Clubs

//Checks whether the given token has ben #defined earlier in the file or in an included file.
#ifndef __card_h__ 
#define __card_h__

enum Suit {CLUB, DIAMOND, HEART, SPADE};
enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

class Card
{
public:
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

private:
	Suit suit;
	Rank rank;
};

#endif //__card_h__