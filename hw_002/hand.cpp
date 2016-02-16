/*
 * hand.cpp
 * Name: Johee Chung
 * Due: February 16, 2016
 * Assignment: Homework 2 / Modeling a deck of cards
 * Class: COMP 15
 *
 * A class for representing a collection of Cards.
 * We'll call it hand, but a deck or discard pile could also
 * be represented with hand.
 *
 * The current implementation does not restrict a hand from having
 * more than one of the same card, e.g., there could be 5 jacks of
 * spades.  Some casinos shuffle multiple decks, so this is actually
 * realistic, but if you want to guard against duplicate cards, the
 * application has to do that.
 */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>

#include "hand.h"

using namespace std;

Hand::Hand()
{
	// nothing necessary
}

Hand::~Hand()
{
	// nothing necessary
}

void Hand::order_hand_by_suit()
{
	Card temp;
	int  temp_int;

	// perform an in-place insertion sort
	int cards_held = hand.cards_in_hand();

	for (int i = 1; i < cards_held; i++) {
		temp     = hand.card_at(i);
		temp_int = temp.card_int();
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (hand.card_at(j).card_int() > temp_int) {
				// move card up
				hand.replace_at_index(hand.card_at(j),
                                                      j + 1);
			} else {
				break;
			}
		}
		hand.replace_at_index(temp, j + 1);
	}
}

void Hand::order_hand_by_rank()
{
	Card temp;
	int  temp_rank;

	// perform an in-place insertion sort
	int cards_held = hand.cards_in_hand();
	for (int i = 1; i < cards_held; i++) {
		temp      = hand.card_at(i);
		temp_rank = temp.get_rank();
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (hand.card_at(j).get_rank() > temp_rank) {
				// move card up
				hand.replace_at_index(hand.card_at(j),
                                                      j + 1);
			} else {
				break;
			}
		}
		hand.replace_at_index(temp, j + 1);
	}
}

/*
 * adds to top of hand
 */
void Hand::add_card(Card c)
{
	hand.insert_at_back(c);
}

bool Hand::remove_card(Card c)
{
	return hand.remove(c);
}

bool Hand::has_card(Card c)
{
	return hand.has_card(c);
}

/*
 * use Knuth shuffle (Fisher-Yates)
 * http://en.wikipedia.org/wiki/Fisher–Yates_shuffle
*/
void Hand::shuffle()
{
	int r;
	Card temp;
	int current_cards_in_hand = hand.cards_in_hand();
	for (int i = current_cards_in_hand - 1; i >= 0; i--) {
		r = rand() % (i + 1);
		// swap
		temp = hand.card_at(i);
		hand.replace_at_index(hand.card_at(r), i);
		hand.replace_at_index(temp, r);
	}
}

Card Hand::deal_card_from_top(Hand &h)
{
	// "top" is the end of the array
	Card c = hand.remove_from_back();
	h.add_card(c);
	return c;
}

/*
 * "bottom" is the beginning of the deck
 */
Card Hand::deal_card_from_bottom(Hand &h)
{
	Card c = hand.remove_from_front();
	h.add_card(c);
	return c;
}

void Hand::create_deck()
{
	int s, r;
	Card c;

	for (s = CLUB; s <= SPADE; s++) {
		for (r = TWO; r <= ACE; r++) {
			c.set_suit((Suit)s);
			c.set_rank((Rank)r);
			hand.insert_at_back(c);
		}
	}
}

/*
 * read deck from standard input
 * Cards are all on one line, like this:
 *
 * 2C AD 5S 6S...
 *
 * no error checking is done:  we assume the input line is correctly
 * formatted.
 */
void Hand::read_deck()
{
	string deck;
	getline(cin, deck);
	Card *c;

	// we assume the input is correct, so the line length
	// is divisible by three.  The number of cards per deck is
	// unlimited, but must include only standard cards
	// i.e., the four suits, and thirteen ranks
	// 2C AD 5S 6S...

	int deck_str_len = deck.length();

	for (int i = 0; i < deck_str_len; i += 3) {
		c = new Card(deck[i], deck[i + 1]);
		hand.insert_at_back(*c);
		delete c;
	}
}


