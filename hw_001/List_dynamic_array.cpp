#include "List_dynamic_array.h"

#include <iostream>
#include <cassert>

using namespace std;

List_dynamic_array::List_dynamic_array()
{
        // TODO: Student writes code here
	// create list
}

List_dynamic_array::~List_dynamic_array()
{
        // TODO: Student writes code here
	// delete list
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

bool List_dynamic_array::is_empty()
{
        return cards_held == 0;
}

void List_dynamic_array::make_empty()
{
        cards_held = 0;
}


int List_dynamic_array::cards_in_hand()
{
        return cards_held;
}

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

void List_dynamic_array::insert_at_front(Card c)
{
        // TODO: Student writes code here
	// check if we need to expand, and expand if necessary

	// move all items over one, starting from the last one

	// insert the new card

	// update cards_held
}

void List_dynamic_array::insert_at_back(Card c)
{
        // TODO: Student writes code here
	// check if we need to expand, and expand if necessary

	// insert the new card at the end

	// update cards_held
}

void List_dynamic_array::insert_at_index(Card c,int index)
{
	// if index is greater than cards_held, then fail
	assert(index <= cards_held);
	
	// TODO: Student writes code here
	// check if we need to expand, and expand if necessary
	
	// move all elements past the insertion point up one
	
	// insert the card
	
	// update cards_held
}

void List_dynamic_array::replace_at_index(Card c, int index)
{
	// if index is greater than cards_held-1, then fail
	assert(index < cards_held);

	// TODO: Student writes code here
	// replace the card at index with c
}

Card List_dynamic_array::card_at(int index)
{
	// if index is out of bounds, fail
	assert (index >= 0 && index < cards_held);
	
	// return the card at index
	// TODO: Student writes code heres
}

bool List_dynamic_array::has_card(Card c)
{
        // TODO: Student writes code here
        // loop through the cards and use the same_card()
        // method in Card.cpp to compare the cards
        // Returns true if the card is in the hand, false otherwise
}

bool List_dynamic_array::remove(Card c)
{
        // TODO: Student writes code here
	// find the card and remove from the hand
	// Returns true if the card was found and removed,
	// false otherwise
}

Card List_dynamic_array::remove_from_front()
{
	// if the list is empty, fail
	assert(cards_held > 0);

        // TODO: Student writes code here
        // remove the card at the front, and move all the other
        // cards back one spot
        // Returns the card that was removed

}

Card List_dynamic_array::remove_from_back()
{
	// if the list is empty, fail
	assert(cards_held > 0);

        // TODO: Student writes code here
	// removes the card that is at the back, and returns it
}

Card List_dynamic_array::remove_from_index(int index)
{
	// if the list is empty, fail
	assert(cards_held > 0);
	
	// if loc is outside of bounds, fail
	assert(index >= 0 && index < cards_held);

        // TODO: Student writes code here
	// similar to remove_from_front(), but
	// we remove the card at index

	// Returns the card that was removed
	
}

void List_dynamic_array::expand()
{
        // TODO: Student writes code here
	// five steps
	// 1. create new list with twice the capacity

	// 2. copy all cards to the new list

	// 3. delete the old list

	// 4. set cards variable to point to the new list

	// 5. update hand_capacity
}
