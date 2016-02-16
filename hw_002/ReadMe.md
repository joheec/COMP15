# ReadMe for COMP 15 HW2 
## Dynamic Arrays

Purpose:
*	This program allows a user to create a 52-card deck.
*	Each card has a suit (C, D, H, S) and a rank 
	(2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A).
*	A user can draw from the top or bottom of the deck to create a hand
*	A user can shuffle the deck and order their hand.

List of files:
*	card.cpp & card.h: Creates individual cards, which are defined by
	suit and rank. Provides functions to set the cards,
	get information about the cards, and see if cards are the same.
*	List_linked_list.cpp & List_linked.list.h: A linked list that
	represents a pile/hand of cards. Provides functions that insert and
	remove cards anywhere in the pile/hand and get information about the
	cards.
*	hand.cpp & hand.h: Creates and interacts with a pile/hand of cards.
*	main.cpp: Creates and interacts a hand and deck of cards. Also creates
	a card.

How to compile:
*	Use included Makefile

Data structure:
*	Uses a singly linked list comprised of card nodes. The card nodes
	is made up of a card and a pointer to the next card node in the list.
	There is a front pointer pointing to the first card node in the list.

Outline of algorithm
*	When inserting a card, create a card node with the parameter. Do not
	create a card node if replacing or removing a card. 
*	Transverse the linked list until reaching the card node before the 
	given position, given index, or finding the given card. If replacing 
	a card, transverse to the desired card node and set the card (in the 
	card node) to the given card. 
*	If inserting, point the new card node pointer to the next card node in 
	the list. If there are no card nodes after, set the pointer to NULL.
*	If inserting, set the previous card node pointer tot he new card node.
	If removing, set the previous card node pointer to the next card node
	and delete the desired card node. If the card node is the first node
	in the list, the "previous" pointer will be the front pointer.

Acknowledgements:
*	Original credit goes to Tufts University. 