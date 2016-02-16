/*
 * File: card.cpp
 * Name: Johee Chung
 * Due: February 16, 2016
 * Assignment: Homework 2 / Modeling a deck of cards
 * Class: COMP 15
 *
 * Class for representing cards in a standard 52-card deck.  Each
 * card's state is given by  the card's Rank and Suit, e.g., three of
 * diamonds.
 *
 * We supply enumerations for usual four suits (Clubs, Diamonds,
 * Hearts, and Spades) and for the usual ranks (2 -- 10 and the four
 * face cards).
 *
 * The default card (the one you get from the default constructor) is
 * the ace of clubs.
 *
 * Cards are mutable:  their suit and rank are separately settable.
 */

#ifndef __card_h__
#define __card_h__

enum Suit {CLUB, DIAMOND, HEART, SPADE};
enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
           JACK, QUEEN, KING, ACE};

class Card
{
public:
	Card(); 
	Card(char r, char s); 
	~Card();

	void print_card();
	void print_card_int();
	
	Suit get_suit();
	void set_suit(Suit s);
	
	Rank get_rank();
	void set_rank(Rank r);
	
	bool same_card(Card c);
	int card_int();
private:
	Suit suit;
	Rank rank;
};

#endif // __card_h__

