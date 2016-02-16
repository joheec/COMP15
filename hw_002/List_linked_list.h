/*
 * List_linked_list.h
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

#ifndef List_linked_list_h
#define List_linked_list_h

#include <iostream> // for NULL
#include "card.h"

class List_linked_list
{
public:
	List_linked_list();
	~List_linked_list();

	List_linked_list(const List_linked_list &source);
	List_linked_list operator =(const List_linked_list &source);
	
	void print_list();
	void print_list_int();
	bool is_empty() { return front == NULL; }

	int cards_in_hand();
	void make_empty();
	
	void insert_at_front(Card c);
	void insert_at_back(Card c);
	void insert_at_index(Card c, int index);
	void replace_at_index(Card c, int index);

	Card card_at(int index);
	bool has_card(Card c);
	bool remove(Card c);
	Card remove_from_front();
	Card remove_from_back();
	Card remove_from_index(int index);

private:
        struct Card_Node {
                Card       card;
                Card_Node *next;
        };
	Card_Node *front;
	Card_Node *copy_card_list(Card_Node *lst);
};

#endif
