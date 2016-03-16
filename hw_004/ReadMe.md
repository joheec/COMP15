# ReadMe for COMP 15 HW4
## BinarySearchTree

PURPOSE:
	To create a Binary Search Tree. This program can insert values into
	the BST, remove values from the BST, and get information about the BST.
	The possible information to get from the BST:
		- find the minimum value
		- find the maximum value
		- check if the BST contains a value
		- find the height of the tree
		- count the nodes in the tree
		- calculate the total of all the values in the tree
		- find the parent of a node

FILES:
	- main.cpp: Runs the program. Includes tests.
	- BinarySearchTree.h/BinarySearchTree.cpp: Creates a BST, maintains 
	the BST, and provides information about the BST.
	- pretty_print.cpp: Prints a visual representation of the BST.

HOW TO COMPILE:
	- Use included Makefule.
	
DATA STRUCTURE:
	- Uses a Binary Search Tree to hold integer values from INT_MIN to
	INT_MAX.
	- Smaller values are inserted to the left and larger values are
	inserted to the right.
	- A node's count represents how many of that node's value exist
	in the BST.

ALGORITHM: 
	- Assignment Overload: Test if the source is pointing to the same 
	location as the target. If they are the same, there is no work to be 
	done. If they are not the same, delete the target BST and then copy 
	the source's node into the target using the pre-order traversal.
	- Remove: If a value is found in the BST, check the count. If the 
	count is greater than 1, deincrement the count. If the count is 1,
	determine how many children the node has.
		- Node has 2 children: Find the minimum value of the right
		subtree. Copy the count and value from the minimum node to the
		node. Make the minimum node's parent point to null and 
		delete the minimum node
		- Node has 1 child: Have the node's parent point to the child
		and delete the node. 
		- Node has no children: Have the node's parent point to NULL
		and delete the node.
	- Tree Height: Recursively go through each node and add 1 to the
	max subtree. The base case will return -1.

ACKNOWLEDGEMENTS:
	* Original credit goes to Tufts University.