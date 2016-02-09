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

List_linked_list::List_linked_list()
{
// hint: in your constructor, you might want to set the front to NULL
	front = NULL;
}

List_linked_list::~List_linked_list()
{
	// delete list by looping through and deleting each node
	while(front != NULL) {
		Card_Node * next = front->next;
		delete front;
		front = next;
	}
}

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

// return number of cards in hand
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

// empties the list; front should be NULL
void List_linked_list::make_empty()
{
	while(front != NULL) {
		Card_Node * next = front->next;
		delete front;
		front = next;
	}
}

// insert a card at the front
// Should allow insert into an empty list
void List_linked_list::insert_at_front(Card c)
{
	Card_Node * new_node = new Card_Node;
	new_node->card = c;
	new_node->next = front;
	front = new_node;
}

// insert a card at the back (after the end)
// should allow insert into an empty list
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

// insert a card at an index such that
// all cards following the index will be moved farther
// down the list by one.
// The index can be one after the back of the list
// I.e., you can insert at index 0 into an empty list,
// and you can insert at index 4 in a list with 4 nodes.
// In the first case, the node inserted would become the front
// In the second case, the node inserted would be inserted
// after the current back.
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

// replace the card at index
// A card at index must already exist
void List_linked_list::replace_at_index(Card c, int index)
{
	assert(index < cards_in_hand());

	Card_Node * new_node = new Card_Node;
	new_node->card = c;

	if(index == 0) {
		new_node->next = front->next;
		delete front;
		front = new_node;
	} else {
		Card_Node * curr = front;
		for(int i = 1; i < index; i++) {
			curr = curr->next;
		}
		new_node->next = curr->next->next;
		delete curr->next;
		curr->next = new_node;
	}
}

// return the card at index.
// allowed to crash if index is not in the list
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

// return true if the card is in the list
// return false if the card is not in the list
bool List_linked_list::has_card(Card c)
{
	if(front == NULL) {
		return false;
	}

	Card_Node * curr = front;
	while((curr->card != c) && (curr->next != NULL)) {
		curr = curr->next;
	}

	if(curr->card == c) {
		return true;
	} else {
		return false;
	}
}

// remove the card from the list
// Returns true if the card was removed
// Returns false if the card was not in the list
bool List_linked_list::remove(Card c)
{
	if(front == NULL) {
		return false;
	}

	Card_Node * curr = front;
	Card_Node * prev = NULL;
	while(curr->card != c && curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}

	if(curr->card == c) {
		prev->next = curr->next;
		delete curr;
		return true;
	} else {
		return false;
	}
}

// Remove the card from the front and
// return the card that was removed
// Allowed to fail if list is empty
// NB:  Doesn't lose cards after the first card.
Card List_linked_list::remove_from_front()
{
	assert(front != NULL);
	Card c = new Card;
	c = front->card;
	Card_Node * next = front->next;
	delete front;
	front = next;
	return c;
}

// Remove the card from the back
// Return the card that was removed
// Allowed to fail if the list is empty
Card List_linked_list::remove_from_back()
{
	assert(front != NULL);
	Card_Node * curr = front;
	Card_Node * prev = NULL;
	while(curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}
	Card c = new Card;
	c = curr->card;
	delete curr;
	if(front->next == NULL) {
		front = NULL;
	} else {
		prev->next = NULL;
	}
	return c;
}

// Remove the card from index
// Return the card that was removed
// Allowed to fail if index is beyond the end of the list
Card List_linked_list::remove_from_index(int index)
{
	assert(index < cards_in_hand());
	Card c = new Card;
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
