## ReadMe for COMP 15 HW1 
## Dynamic Arrays

Purpose:
*	This program allows a user to create a 52-card deck.
*	Each card has a suit (C, D, H, S) and a rank 
	(2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A).
*	A user can draw from the top or bottom of the deck to create a hand
*	A user can shuffle the deck and order their hand.

Algorithm:
*	Inserting a card into a hand
	1) Increase cards_held by 1.
	2) Compare the cards_held and the hand_capacity to check if there is 
	enough room in the dynamic array. 
	3) If there is not enough room increase hand_capacity using expand() 
	which doubles the current hand capacity.
	4) If increasing the capacity, inserting at the front, or inserting
	at the index, create a temporary array using hand_capacity and move 
	the elements from the original to the temporary array. 
		a) No card will be inserted at index zero if the card is 
		inserted in the front. 
		b) No card will be inserted at the parameter index if the 
		card is inserted at an index.
	5) Set the element at where ever the card is to be inserted to card c.
	
*	When removing a card from the back, subtract 1 from cards_held.
*	When removing a card from the front, subtract 1 from cards_held and
	set the value of an element equal to the element after it, starting 
	with index 0.
*	When removing a card from an index, subtract 1 from cards_held and
	set the value of an element equal to the element after it, starting 
	with the index in the parameter.
*	When removing a given card, loop through the array to find the index 
	of a card of the same rank and suit. If such a card is found,
	subtract 1 from cards_held and set the value of an element equal to 
	the element after it, starting with index found in the loop.

How to compile:
*	Use included Makefile

Acknowledgements:
*	Original credit goes to Tufts University. 