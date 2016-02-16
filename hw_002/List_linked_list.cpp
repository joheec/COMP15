/*
 * List_linked_list.cpp
 * Name: Johee Chung
 * Due: February 16, 2016
 * Assignment: Homework 2 / Modeling a deck of cards
 * Class: COMP 15
 *
 * Create a list using a standard, singly linked list that grows as needed.
 * The list is comprised of an linked list of card nodes, which can be
 * inserted, removed, and replaced in a number of different ways.
 *
 * Each card node has a card and a pointer to the next card node in the list.
 * Cards contain the suit and rank of the card
 *
 * There is a "front" pointer, which points to the first card node in the
 * linked list.
 */

#include "List_linked_list.h"

#include <iostream>
#include <cassert>

using namespace std;

/*
 * The following #define allows us to use Card_Node as a type.
 * Because the node structure is private, we would otherwise
 * have to write List_linked_list::Card_node everywhere.
 *
 * I put a few of those in, so you can see what I mean (see
 * the copy constructor.
 */
#define Card_Node List_linked_list::Card_Node

/*
 * Constructor: sets the front pointer to NULL.
 */
List_linked_list::List_linked_list()
{
	front = NULL;
}

/*
 * Destructor
 */
List_linked_list::~List_linked_list()
{
	Card_Node * next;
	while(front != NULL) {
		next = front->next;
		delete front;
		front = next;
	}
}

/*
 * A function used by the explicit copy constructor to create new nodes
 * to copy the node data into.
 */
List_linked_list::Card_Node 
*List_linked_list::copy_card_list(List_linked_list::Card_Node *lst)
{
        // Easy to copy an empty list
        if (lst == NULL)
                return NULL;

        // Otherwise make a new node
        List_linked_list::Card_Node *new_node_p
                = new List_linked_list::Card_Node;

        // Copy node data
        new_node_p->card = lst->card;

        // and copy the rest of the nodes
        new_node_p->next = copy_card_list(lst->next);

        // Return pointer to first node in copied list
        return new_node_p;
}

/*
 * Explicit copy constructor necessary because of cards list 
 * in the heap.
 */
List_linked_list::List_linked_list(const List_linked_list &source)
{
        front = copy_card_list(source.front);
}

/*
 * Explicit operator= overload necessary because of heap-allocated 
 * card nodes
 */
List_linked_list List_linked_list::operator =(const List_linked_list &source)
{
	// check for self-assignment -- return without doing anything
	if (this == &source) {
		return *this;
	}
	// delete all current cards
	while (front != NULL) {
		Card_Node *next = front->next;
		delete front;
		front = next;
	}
	// copy over all cards from source list
	if (source.front == NULL) return *this; // nothing to do

	front = new Card_Node;
	Card_Node *this_current   = front;
	Card_Node *source_current = source.front;

	while (source_current != NULL) {
		// deep copy each Card_Node
		this_current->card = source_current->card;
		if (source_current->next != NULL) {
			Card_Node *new_node = new Card_Node();
			this_current->next  = new_node;
		} else {
			this_current->next = NULL; // at back
		}
		source_current = source_current->next;
		this_current   = this_current->next;
	}
	return *this;
}

/*
 * @parameter 	none
 * @return	none
 *
 * Prints the rank and the suit (in that order) of each card node,
 * beginning with the card node the 'front' pointer is pointing to.
 * The rank can be represented by a number between 2 and 9 or
 * the letter 'T', 'J', 'Q', 'K', and 'A' representing
 * ten, Jack, Queen, King, and Ace, respectively.
 */
void List_linked_list::print_list()
{
	Card_Node *current = front;
	while (current != NULL) {
		current->card.print_card();
		if (current->next != NULL) {
			cout << ",";
		} else {
			cout << "\n";
		}
		current = current->next;
	}
}

/*
 * @parameter	none
 * @return	none
 *
 * Prints the integer value of each card node,
 * beginning with the card node the 'front' pointer is pointing to.
 *
 * To calculate the value of a card, each rank and suit has a value.
 * Rank values are TWO = 0, THREE = 1 ... KING = 11, ACE = 12.
 * Suit values in ascending order are CLUB, DIAMOND, HEART, SPADE.
 * There are 13 cards in each suit, so each suit is 13 times greater
 * than the one before it.
 *
 * The total value of a card is the sum of its suit and rank.
 */
void List_linked_list::print_list_int()
{
	Card_Node *current = front;
	while (current != NULL) {
		current->card.print_card_int();
		if (current->next != NULL) {
			cout << ",";
		} else {
			cout << "\n";
		}
		current = current->next;
	}
}

/*
 * @parameter	none
 * @return	integer	count	Number of cards in the hand.
 *
 * return number of cards in hand
 */
int List_linked_list::cards_in_hand()
{
	int count = 0;
	Card_Node * curr_ptr = front;
	while(curr_ptr != NULL) {
		++count;
		curr_ptr = curr_ptr->next;
	}

	return count;
}

/*
 * @parameter	none
 * @return	none
 *
 * Empties the list. The front pointer is set to NULL.
 */
void List_linked_list::make_empty()
{
	while(front != NULL) {
		Card_Node * next = front->next;
		delete front;
		front = next;
	}
}

/*
 * @parameter	Card	c	A card containing the suit and rank.
 * @return	none
 *
 * Inserts a card node at the front of the list.
 */
void List_linked_list::insert_at_front(Card c)
{
	Card_Node * new_node = new Card_Node;
	new_node->card = c;
	new_node->next = front;
	front = new_node;
}

/*
 * @parameter	Card	c	A card containing the suit and rank.
 * @return	none
 *
 * Inserts a card node at the end of the list.
 */
void List_linked_list::insert_at_back(Card c)
{
	Card_Node * new_node = new Card_Node;
	new_node->card = c;
	new_node->next = NULL;

	if(front == NULL) {
		front = new_node;
	} else {
		Card_Node * curr = front;
		Card_Node * prev = NULL;

		while(curr != NULL) {
			prev = curr;
			curr = curr->next;
		}

		prev->next = new_node;
	}
}

/*
 * @parameter	Card	c	A card containing the suit and rank.
 * 		int	index	Where to insert the card node.
 * @return	none
 *
 * Inserts a card node at an index. Will fail if the index is greater than the
 * number of card nodes in a hand.
 */
void List_linked_list::insert_at_index(Card c, int index)
{
	assert(index <= cards_in_hand());

	Card_Node * new_node = new Card_Node;
	new_node->card = c;

	if(index == 0){
		new_node->next = front;
		front = new_node;
	} else {
		Card_Node * curr = front;
		for(int i = 1; i < index; i++) {
			curr = curr->next;
		}
		new_node->next = curr->next;
		curr->next = new_node;
	}
}

/*
 * @parameter	Card	c	A card containing a suit and rank.
 * 		int	index	Where to replace the card node.
 * @return	none
 *
 * Replaces the card at the index.
 */
void List_linked_list::replace_at_index(Card c, int index)
{
	assert(index < cards_in_hand());

	if(index == 0) {
		front->card = c;
	} else {
		Card_Node * curr = front;
		for(int i = 0; i < index; i++) {
			curr = curr->next;
		}
		curr->card = c;
	}
}

/*
 * @parameter	int	index		Where the card is located.
 * @return	Card	curr->card	The card at the index.
 *
 * Returns the card at the index. Will fail if the index is greater than or
 * equal to the number of card nodes in a hand.
 */
Card List_linked_list::card_at(int index)
{
	assert(index < cards_in_hand());
	if(index == 0) {
		return front->card;
	} else {
		Card_Node * curr = front;
		for(int i = 0; i < index; i++) {
			curr = curr->next;
		}
		return curr->card;
	}
}

/*
 * @parameter	Card	c	A card containing a suit and rank.
 * @return	bool	true	When the card is in the list.
 * 			false	When the card is not in the list.
 *
 * Determines whether a card is in the hand.
 */
bool List_linked_list::has_card(Card c)
{
	if(front == NULL) {
		return false;
	}

	Card_Node * curr = front;

	while((!c.same_card(curr->card)) && (curr->next != NULL)) {
		curr = curr->next;
	}

	if(c.same_card(curr->card)) {
		return true;
	} else {
		return false;
	}
}

/*
 * @parameter	Card	c	A card containing a suit and rank.
 * @return	bool	true	If the card was removed.
 * 			false	If the card was not in the list.
 *
 * Removes a card from the list. If the card is not in the list, the function
 * returns false.
 */
bool List_linked_list::remove(Card c)
{
	if(front == NULL) {
		return false;
	}

	Card_Node * curr = front;
	Card_Node * prev = NULL;
	while((!c.same_card(curr->card)) && curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}

	if(c.same_card(curr->card)) {
		prev->next = curr->next;
		delete curr;
		return true;
	} else {
		return false;
	}
}

/*
 * @parameter	none
 * @return	Card	c	The first card in the list.
 *
 * Removes the card from the front of the list and returns the card.
 * Fails if the list is empty.
 */
Card List_linked_list::remove_from_front()
{
	assert(front != NULL);
	Card c = front->card;
	Card_Node * next = front->next;
	delete front;
	front = next;
	return c;
}

/*
 * @parameter	none
 * @return	Card	c	The last card in the list.
 *
 * Removes the card from the back of the list and returns the card.
 * Fails if the list is empty.
 */
Card List_linked_list::remove_from_back()
{
	assert(front != NULL);
	Card_Node * curr = front;
	Card_Node * prev = NULL;
	while(curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}
	Card c = curr->card;
	delete curr;
	if(front->next == NULL) {
		front = NULL;
	} else {
		prev->next = NULL;
	}
	return c;
}

/*
 * @parameter	int	index	The location of the card.
 * @return	Card	c	A card containing a suit and rank.
 *
 * Removes the card node from the index and returns the card.
 * Will fail if the index is not less than the number of cards in the hand.
 */
Card List_linked_list::remove_from_index(int index)
{
	assert(index < cards_in_hand());
	Card c;
	if(index == 0) {
		c = front->card;
		delete front;
		return c;
	} else {
		Card_Node * curr = front;
		Card_Node * prev = NULL;
		for(int i = 0; i < index; i++) {
			prev = curr;
			curr = curr->next;
		}
		c = curr->card;
		prev->next = curr->next;
		delete curr;
		return c;
	}
}
