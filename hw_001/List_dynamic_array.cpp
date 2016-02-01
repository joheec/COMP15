/*
 * List_dynamic_array.cpp
 * Name: Johee Chung
 * Due: February 1, 2016
 * Assignment: Homework 1 / Modeling a deck of cards
 * Class: COMP 15
 *
 * Create a list using a dynamic array that grows as needed.
 * The list is comprised of an array of Cards, which can be
 * inserted, removed, and replaced in a number of different
 * ways.
 *
 * The "front" of the list is at the beginning of the array
 * The "back"  of the list is at the end of the array
 */

#include "List_dynamic_array.h"

#include <iostream>
#include <cassert>

using namespace std;

/*
 * Constructor
 */
List_dynamic_array::List_dynamic_array()
{
        cards = new Card[INITIAL_CAPACITY];
        hand_capacity = INITIAL_CAPACITY;
        cards_held = 0;
}

/*
 * Destructor
 */
List_dynamic_array::~List_dynamic_array()
{
        delete [] cards;
}

/*
 * explicit copy constructor necessary because of pointer to cards
 * array 
 */
List_dynamic_array::List_dynamic_array(const List_dynamic_array &source)
{

	cards_held    = source.cards_held;
	hand_capacity = source.hand_capacity;

	cards = new Card[hand_capacity];
	for (int i = 0; i < cards_held; i++) {
		cards[i] = source.cards[i];
	}
}

/*
 * explicit operator= overload necessary because of pointer to cards
 * array
 */
List_dynamic_array
List_dynamic_array::operator=(const List_dynamic_array &source)
{
	Card *new_cards;

	// check for self-assignment -- return without doing anything
	if (this == &source) {
		return *this;
	}

	hand_capacity = source.hand_capacity;
	cards_held    = source.cards_held;
	new_cards     = new Card[hand_capacity];

	for (int i = 0; i < hand_capacity; i++) {
		new_cards[i] = source.cards[i];
	}
	delete [ ] cards;
	cards = new_cards;
	return *this;
}

/*
 * @parameter
 * @return	bool
 *
 * Returns true if there are no cards in the list, otherwise returns false
 */
bool List_dynamic_array::is_empty()
{
        return cards_held == 0;
}

/*
 * @parameter
 * @return
 *
 * Sets cards_held to zero showing there are no cards in the list
 */
void List_dynamic_array::make_empty()
{
        cards_held = 0;
}

/*
 * @parameter
 * @return	int cards_held	Number of cards held
 *
 * Returns the number of elements in the list
 */
int List_dynamic_array::cards_in_hand()
{
        return cards_held;
}

/*
 * @parameter
 * @return
 *
 * Prints a list in human-readable form
 */
void List_dynamic_array::print_list()
{
	for (int i = 0; i < cards_held; i++) {
		cards[i].print_card();
		if (i != cards_held - 1) {
			cout << ", ";
		} else {
			cout << "\n";
		}
	}
}

/*
 * @parameter
 * @return
 *
 * Prints the list as integers based on rank and suit
 */
void List_dynamic_array::print_list_int()
{
	for (int i = 0; i < cards_held; i++) {
		cards[i].print_card_int();
		if (i != cards_held - 1) {
			cout << ", ";
		} else {
			cout << "\n";
		}
	}
}

/*
 * @parameter	Card c	The inserted card
 * @return
 *
 * Inserts a card at the beginning of the list
 */
void List_dynamic_array::insert_at_front(Card c)
{
	++cards_held;
	if(cards_held > hand_capacity) {
		expand();
	}

	Card * temp_hand = new Card[hand_capacity];

	for(int i = 0; i < cards_held; i++) {
		temp_hand[i + 1] = cards[i];
	}

	delete [] cards;
	cards = temp_hand;
	cards[0] = c;
}

/*
 * @parameter	Card c	The inserted card
 * @return
 *
 * Inserts a card at the end of the list
 */
void List_dynamic_array::insert_at_back(Card c)
{
	++cards_held;
	if(cards_held > hand_capacity) {
		expand();
	}

	Card * temp_hand = new Card[hand_capacity];

	for(int i = 0; i < cards_held; i++) {
		temp_hand[i] = cards[i];
	}

	delete [] cards;
	cards = temp_hand;
	cards[cards_held - 1] = c;
}

/*
 * @parameter	Card c	The inserted card
 * @return
 *
 * Inserts a card at a given index
 */
void List_dynamic_array::insert_at_index(Card c,int index)
{
	// if index is greater than cards_held, then fail
	assert(index <= cards_held);

	++cards_held;
	if(cards_held > hand_capacity) {
		expand();
	}

	Card * temp_hand = new Card[hand_capacity];
	int new_index = 0;
	for(int i = 0; i < cards_held; i++) {
		if(i == index) {
			new_index = 1;
		}
		temp_hand[i + new_index] = cards[i];
	}

	delete [] cards;
	cards = temp_hand;
	cards[index] = c;
}

/*
 * @parameter	Card c		The card placed in the list
 * 		int index	Where the card is placed
 * @return
 *
 * Replaces card at given index
 */
void List_dynamic_array::replace_at_index(Card c, int index)
{
	// if index is greater than cards_held-1, then fail
	assert(index < cards_held);
	cards[index] = c;
}

/*
 * @parameter	int index	Where the card is in the list
 * @return
 *
 * Returns a card at the index
 */
Card List_dynamic_array::card_at(int index)
{
	// if index is out of bounds, fail
	assert (index >= 0 && index < cards_held);
	return cards[index];
}

/*
 * @parameter	Card c	The card to search for
 * @return	bool
 *
 * Returns true if c is in the list, otherwise returns false.
 */
bool List_dynamic_array::has_card(Card c)
{
	for(int i = 0; i < cards_held; i++) {
		if(cards[i].same_card(c) == true) {
			return true;
		}
	}
	return false;
}

/*
 * @parameter	Card c	The card to remove
 * @return	bool
 *
 * Returns true if Card c is found and removed, otherwise returns false.
 */
bool List_dynamic_array::remove(Card c)
{
	for(int i = 0; i < cards_held; i++) {
		if(cards[i].same_card(c) == true) {
			--cards_held;
			for(int j = i; j < cards_held; j++) {
				cards[i] = cards[i + 1];
			}
			return true;
		}
	}
	return false;
}

/*
 * @parameter
 * @return	Card first_card		The removed card
 *
 * Removes the first card in the list and returns the card
 */
Card List_dynamic_array::remove_from_front()
{
	// if the list is empty, fail
	assert(cards_held > 0);

	--cards_held;
	Card first_card = cards[0];

	for(int i = 0; i < cards_held; i++) {
		cards[i] = cards[i+1];
	}
	return first_card;
}

/*
 * @parameter
 * @return	Card cards[cards_held]		The removed card
 *
 * Removes the last card in the list by subtracting 1
 * from cards_held and returns the last card
 */
Card List_dynamic_array::remove_from_back()
{
	// if the list is empty, fail
	assert(cards_held > 0);

	--cards_held;
	return cards[cards_held];

}

/*
 * @parameter	int index	Where to remove a card
 * @return	Card index_card	The removed card
 *
 * Removes a cards at the index and returns the removed card
 */
Card List_dynamic_array::remove_from_index(int index)
{
	--cards_held;
	Card index_card = cards[index];

	for(int i = index; i < cards_held; i++) {
		cards[i] = cards[i+1];
	}
	return index_card;
	
}

/*
 * @parameter
 * @return
 *
 * Doubles the hand_capacity
 */
void List_dynamic_array::expand()
{
	hand_capacity = hand_capacity * 2;
}
