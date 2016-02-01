/*
 * File: card.cpp
 * Name: Johee Chung
 * Due: February 1, 2016
 * Assignment: Homework 1 / Modeling a deck of cards
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

#include <iostream>
#include <sstream>
#include <cstdlib>

#include "card.h"

using namespace std;

/*
 * Card constructor with default values Ace of Clubs.
 */
Card::Card()
{
	suit = CLUB;
	rank = ACE;
}

/*
 * @parameter	char r	Indicates the rank of the card
 * 		char s	Indicates the suit of the card
 *
 * Card constructor with given values
 */
Card::Card(char r, char s)
{
	switch (s) {
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
	case 'T':
		rank = TEN;
		break;
	case 'J':
		rank = JACK;
		break;
	case 'Q':
		rank = QUEEN;
		break;
	case 'K':
		rank = KING;
		break;
	case 'A':
		rank = ACE;
		break;
	default:
		rank = (Rank)((int)r - '0' - 2);  // Ranks begin with TWO
	}
}

/*
 * Card destructor
 */
Card::~Card()
{
	// nothing to do
}

/*
 * @parameter
 * @return 	Suit suit	The suit of the card
 *
 * Returns the suit of a card.
 */
Suit Card::get_suit()
{
        return suit;
}

/*
 * @parameter	Suit s	The desired suit for a card
 * @return
 *
 * Sets the suit of a card
 */
void Card::set_suit(Suit s)
{
        suit = s;
}

/*
 * @parameter
 * @return	Rank rank	The rank of a card
 *
 * Returns the rank of a card (e.g., "THREE")
 */
Rank Card::get_rank()
{
        return rank;
}

/*
 * @parameter	Rank r	The desired rank of a card
 * @return
 *
 * Sets the rank of a card
 */
void Card::set_rank(Rank r)
{
        rank = r;
}

/*
 * @parameter
 * @return
 *
 * Prints the rank and suit of a card (e.g., "3D")
 */
void Card::print_card()
{
	string suit_str, rank_str;
	ostringstream ss;

	switch (suit) {
	case CLUB:
		suit_str = "C";
		break;
	case HEART:
		suit_str = "H";
		break;
	case DIAMOND:
		suit_str = "D";
		break;
	case SPADE:
		suit_str = "S";
		break;
	}
	switch (rank) {
	case TEN:
		rank_str = "T";
		break;
	case JACK:
		rank_str = "J";
		break;
	case QUEEN:
		rank_str = "Q";
		break;
	case KING:
		rank_str = "K";
		break;
	case ACE:
		rank_str = "A";
		break;
	default:
		ss << ((int)rank + 2);
		rank_str = ss.str();
	}
	cout << rank_str << suit_str;
}

/*
 * @parameter
 * @return
 *
 * Prints the integer value of a card.
 */
void Card::print_card_int()
{
	cout << card_int();
}

/*
 * @parameter	Card c	The card to compare to
 * @return	bool
 *
 * Returns true if the rank and suit of c and the current card are the same,
 * otherwise, returns false.
 */
bool Card::same_card(Card c)
{
	return (rank == c.rank and suit == c.suit);
}

/*
 * @parameter
 * @return	The integer value of a card
 *
 * To calculate the value of a card, each rank and suit has a value.
 * Rank values are TWO = 0, THREE = 1 ... KING = 11, ACE = 12.
 * Suit values are CLUB = 0*13, DIAMOND = 1*13, HEART = 2*13, SPADE = 3*13.
 * There are 13 cards in each suit, so each suit is 13 times greater
 * than the one before it.
 *
 * The total value of a card is the sum of its suit and rank.
 */
int Card::card_int()
{
	return (int)rank + (int)suit * 13;
}
