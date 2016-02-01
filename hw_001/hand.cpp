/*
 * File: hand.cpp
 * Name: Johee Chung
 * Due: February 1, 2016
 * Assignment: Homework 1 / Modeling a deck of cards
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

/*
 * Constructs a hand
 */
Hand::Hand()
{
	// nothing necessary
}

/*
 * Destructs a hand
 */
Hand::~Hand()
{
	// nothing necessary
}

/*
 * @parameter
 * @return
 *
 * Orders the cards in hand by the int value of the cards
 */
void Hand::order_hand()
{
	Card temp;
	int temp_int;
	// perform an in-place insertion sort
	int cards_held = hand.cards_in_hand();
	for (int i = 1; i < cards_held; i++) {
		temp = hand.card_at(i);
		temp_int = temp.card_int();

		int j;
		for (j = i - 1; j >= 0; j--) {
			if (hand.card_at(j).card_int() > temp_int) {
				// move card up
				hand.replace_at_index(hand.card_at(j), j + 1);
			} else {
				break;
			}
		}
		hand.replace_at_index(temp, j + 1);
	}
}

/*
 * @parameter
 * @return
 *
 * Prints the cards in a hand
 */
void Hand::print_hand()
{
        hand.print_list();
}

/*
 * @parameter
 * @return
 *
 * Prints the integer values of the cards in a hand
 */
void Hand::print_hand_int()
{
        hand.print_list_int();
}

/*
 * @parameter
 * @return	int hand.cards_in_hand()	The number of cards in hand
 *
 * Return number of cards currently in the hand
 */
int Hand::cards_in_hand()
{
        return hand.cards_in_hand();
}

/*
 * @parameter	Card c	The card to add to the hand
 * @return
 *
 * Adds card to the end of the hand
 */
void Hand::add_card(Card c)
{
	// adds to top of hand
	hand.insert_at_back(c);
}

/*
 * @parameter	Card c	The card to remove from the hand
 * @return	bool
 *
 * Removes a card from the hand
 * Returns true if the card was successfully removed, false otherwise
 */
bool Hand::remove_card(Card c)
{
	return hand.remove(c);
}

/*
 * @parameter	Card c	The compared card
 * @return	bool	True if the hand as the card, otherwise false
 *
 * Returns true if the hand contains the card, false otherwise
 */
bool Hand::has_card(Card c)
{
	return hand.has_card(c);
}

/*
 * @parameter
 * @return
 *
 * Randomly shuffles the hand
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

/*
 * @parameter	Hand &h		A pointer to the hand
 * @return	Card c		The card that is removed from the deck and
 * 				added to the hand
 *
 * Deals a card from the top of the hand (the last card)
 */
Card Hand::deal_card_from_top(Hand &h)
{
	// "top" is the end of the array
	Card c = hand.remove_from_back();
	h.add_card(c);
	return c;
}

/*
 * @parameter	Hand &h		A pointer to the hand
 * @return	Card c		The card that is removed from the deck and
 * 				added to the hand
 *
 * Deals a card from the top of the hand (the last card)
 * deals a card from the bottom of the hand (the first card)
 */
Card Hand::deal_card_from_bottom(Hand &h)
{
	// "bottom" is the beginning of the deck
	Card c = hand.remove_from_front();
	h.add_card(c);
	return c;
}

/*
 * @parameter
 * @return
 *
 * Creates a standard 52-card deck
 */
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
 * @parameter
 * @return
 * read input from stdin
 *
 * NB:  We assume the input is correct, so the line length
 * is divisible by three.  The number of cards per deck is
 * unlimited, but must include only standard cards
 * i.e., the four suits, and thirteen ranks
 * 2C, AD, 5S, 6S...
 */
void Hand::read_deck() {
	string deck;
	getline(cin, deck);
	Card *c;
		
	int deck_str_len = deck.length();
	
	for (int i = 0; i < deck_str_len; i += 3) {
		c = new Card(deck[i], deck[i + 1]);
		hand.insert_at_back(*c);
		delete c;
	}
}
