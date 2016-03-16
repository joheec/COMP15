/*
 * File: BinarySearchTree.cpp
 * Name: Johee Chung
 * Due: March 14, 2016
 * Assignment: Homework 4 / Binary Search Tree
 * Class: Comp 15
 *
 * A Binary Search Tree that holds integer values from INT_MIN to INT_MAX.
 * The smaller integers are to the left and bigger integers are to the right.
 * Each node in the BST has a value (data), a count, and a left and right
 * pointer. The count represents how many values are in the node.
 *
 * The functions aid in finding information about the BST as well as add
 * and remove values.
 */

#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>

#include "BinarySearchTree.h"

using namespace std;

//Constructor
BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

//Destructor
BinarySearchTree::~BinarySearchTree()
{
        post_order_delete(root);
}

/*
 * Uses post-order traversal to delete a node and all its descendants.
 *
 * @parameter	Node* node - A pointer to a node that needs to be deleted
 * @return	void
 */
void BinarySearchTree::post_order_delete(Node *node)
{
	// base case for recursion: return when hits an empty node
	if(node == NULL) {
		return;
	}
	//traverse the left and then right subtree
	if(node->left != NULL) {
		post_order_delete(node->left);
	}
	if(node->right != NULL) {
		post_order_delete(node->right);
	}

	delete node;
}

//Copy Constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        root = pre_order_copy(source.root);
}

//Assignment Overload
BinarySearchTree &BinarySearchTree::operator= (const BinarySearchTree &source)
{
        // check for self-assignment
	if(this == &source) {
		return * this;
	}

        // delete this tree if it exists
	post_order_delete(this->root);

        // use pre-order traversal to copy the tree
	this->root = pre_order_copy(source.root);

	return * this;
}

/*
 * Uses pre-order traversal to copy properties of the node to a new_node.
 * It will create copies of the node and all its descendants.
 * Returns a pointer to a new_node.
 *
 * @parameter	Node *node - A pointer to a node that needs to be copied
 * @return	Node *new_node - A pointer to a copied node
 */
Node *BinarySearchTree::pre_order_copy(Node *node) const
{
        //base case for recursion: return NULL if their is no node struct
        if (node == NULL)
                return NULL;

        //copy node properties into a new node
        Node *new_node = new Node();
        new_node->data = node->data;
        new_node->count = node->count;

        //use recursion to copy the left then the right subtrees
	new_node->left = pre_order_copy(node->left);
	new_node->right = pre_order_copy(node->right);

        return new_node;
}

/*
 * Returns the minimum value in the tree. Returns INT_MIN if the tree
 * is empty.
 *
 * @parameter	none
 * @return	integer - The minimum value
 */
int BinarySearchTree::find_min() const
{
        if (root == NULL)
                return INT_MIN;

        return find_min(root)->data;
}

/*
 * Finds the minimum value by traversing down the left subtree of each node.
 * If the left pointer is null, the value was found.
 *
 * @parameter	Node *node - A pointer to a node
 * @return	Node *node - A pointer to the node with the min value
 */
Node *BinarySearchTree::find_min(Node *node) const
{
        if(node->left == NULL) {
        	return node;
        }
        //traverse left to find min
        return find_min(node->left);
}

/*
 * Returns the maximum value in the tree. Returns INT_MAX if the tree
 * is empty.
 *
 * @parameter	none
 * @return	integer - The maximum value
 */
int BinarySearchTree::find_max() const
{
        if(root == NULL) {
        	return INT_MAX;
        }

        return find_max(root)->data;
}

/*
 * Finds the maximum value by traversing down the right subtree of each node.
 * If the right pointer is null, the value was found.
 *
 * @parameter	Node *node - A pointer to a node
 * @return	Node *node - A pointer to the node with the max value
 */
Node *BinarySearchTree::find_max(Node *node) const
{
        if(node->right == NULL) {
        	return node;
        }
        //traverse right to find max
        return find_max(node->right);
}

/*
 * Returns true if the tree contains the value. Returns false if the tree
 * does not contain the value.
 *
 * @parameter	int value - The value to check the tree for
 * @return	bool - Whether the tree contains the value
 */
bool BinarySearchTree::contains(int value) const
{
        return contains(root, value);
}

/*
 * Returns true if the tree contains the value. Returns false if the tree
 * does not contain the value.
 *
 * @parameter	Node *node - A pointer to a node
 * 		int value - The value to check the tree for
 *
 * @return	bool - Whether the tree contains the value
 */
bool BinarySearchTree::contains(Node *node, int value) const
{
        if(node == NULL) {
        	return false;
        }
        //traverse BST
        if(node->data > value) {
        	return contains(node->left, value);
        } else if(node->data < value) {
        	return contains(node->right, value);
        } else {
        	return true;
        }
}

/*
 * Inserts a value into a tree.
 *
 * @parameter	int value - The value to insert into the tree
 * @return	void
 */
void BinarySearchTree::insert(int value)
{
        insert(root, NULL, value);
}

/*
 * Inserts a value into the tree. If a value already exists in the tree,
 * increase the count by 1.
 *
 * @parameter	Node *node - A pointer to a node
 * 		Node *parent - A pointer to the parent of the node
 * 		int value - The value to insert into the tree
 *
 * @return	void
 */
void BinarySearchTree::insert(Node *node, Node *parent, int value)
{
	//insert into empty tree
	if(root == NULL) {
		root = create_node(value);
		return;
	}
	//base case
	if(node == NULL) {
		if(parent->data > value) {
			parent->left = create_node(value);
		} else{
			parent->right = create_node(value);
		}
		return;
	}
	//traverse tree
	if(node->data > value) {
		insert(node->left, node, value);
	} else if(node->data < value) {
		insert(node->right, node, value);
	} else {
		++(node->count);
	}
}

/*
 * Creates a node with an initial count of 1, empty pointers, and a given
 * value.
 *
 * @parameter	int value - The data
 * @return	Node * - A pointer to the created node
 */
Node *BinarySearchTree::create_node(int value)
{
	Node * new_node = new Node;
	new_node->data = value;
	new_node->count = 1;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

/*
 * Returns true if deincrements a count or deletes a node with the given value.
 * Returns false if the given value is not in the BST.
 *
 * @parameter	int value - The integer to remove from the BST
 * @return	bool - Whether the value was removed
 */
bool BinarySearchTree::remove(int value)
{
        return remove(root, NULL, value);
}

/*
 * Returns true if deincrements a count or deletes a node with the given value.
 * Returns false if the given value is not in the BST.
 *
 * @parameter	Node *node - A pointer to the given node
 * 		Node *parent - A pointer to the parent of the given node
 * 		int value - The integer to remove from the BST
 *
 * @return	bool - Whether the value was removed
 */
bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
        //value does not exist in BST
	if(node == NULL) {
		return false;
	}
	//traverse BST to find value
	if(node->data > value) {
		return remove(node->left, node, value);
	} else if (node->data < value) {
		return remove(node->right, node, value);
	}
	//found value
	if(node->count > 1) {
		--node->count;
		return true;
	}
	if(node->left != NULL && node->right != NULL) {
		//if the found node has 2 children
		return two_children(node);
	} else {
		//if the found node has 1 or no children
		return one_no_child(node, parent, value);
	}
}

/*
 * Helper function that removes a node with 2 children. Returns true when the
 * given node has been removed.
 *
 * @parameter	Node *node - A pointer to the node that needs to be removed
 * @return	bool - When the give node is removed
 */
bool BinarySearchTree::two_children(Node *node)
{
	Node * temp = NULL;
	//the right node does not have a left subtree
	if(node->right->left == NULL) {
		node->data = node->right->data;
		node->count = node->right->count;
		temp = node->right;
		node->right = node->right->right;
	} else {
		//the right node has a left subtree
		Node * temp_parent = NULL;
		temp = find_min(node->right);
		temp_parent = find_parent(root, temp);

		node->data = temp->data;
		node->count = temp->count;
		temp_parent->left = temp->right;
	}
	delete temp;
	return true;
}

/*
 * Helper function that removes a node with 1 or no children. Returns true
 * when the given node has been removed
 *
 * @parameter	Node *node - A pointer to the node that needs to be removed
 * 		Node *parent - A pointer to the parent of the given node
 * 		int value - The value that is being removed
 */
bool BinarySearchTree::one_no_child(Node *node, Node *parent, int value)
{
	//the right child is not NULL or there are no children
	if(node->left == NULL) {
		if(parent == NULL) {
			root = node->right;
		} else if(parent->data > value) {
			parent->left = node->right;
		} else {
			parent->right = node->right;
		}
	} else {
		//the left child is not NULL
		if(parent == NULL) {
			root = node->left;
		}
		else if(parent->data > value) {
			parent->left = node->left;
		} else {
			parent->right = node->left;
		}
	}
	delete node;
	return true;
}

/*
 * Returns the maximum distance from the root to it's farthest leaf.
 * An empty tree has a height of -1 and a tree with just the root has a
 * height of 0.
 *
 * @parameter	none
 * @return	int - The height of the tree
 */
int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}

/*
 * Returns the maximum distance from the root to it's farthest leaf.
 * An empty tree has a height of -1 and a tree with just the root has a
 * height of 0.
 *
 * @parameter	Node *node - A pointer to a node
 * @return	int - The height of the tree
 */
int BinarySearchTree::tree_height(Node *node) const
{
	//height of empty tree
        if(node == NULL) {
        	return -1;
        }

        return 1 + max(tree_height(node->left), tree_height(node->right));
}

/*
 * Returns the total number of nodes. Does not include repeated data.
 *
 * @parameter	none
 * @return	int - Total number of nodes
 */
int BinarySearchTree::node_count() const
{
        return node_count(root);
}

/*
 * Returns the total number of nodes. Does not include repeated data.
 *
 * @parameter	Node *node - Pointer to a node
 * @return	int - Total number of nodes
 */
int BinarySearchTree::node_count(Node *node) const
{
        if(node == NULL) {
        	return 0;
        }

        return 1 + node_count(node->left) + node_count(node->right);
}

/*
 * Return the sum of all the node values. Includes duplicates.
 *
 * @parameter	none
 * @return	int - Sum of all the node values
 */
int BinarySearchTree::count_total() const
{
        return count_total(root);
}

/*
 * Return the sum of all the node values. Includes duplicates.
 *
 * @parameter	Node *node - Pointer to a node
 * @return	int - Sum of all the node values
 */
int BinarySearchTree::count_total(Node *node) const
{
        if(node == NULL) {
        	return 0;
        }
        return (node->data * node->count) +
        		count_total(node->left) + count_total(node->right);

}

/*
 * Prints the tree
 *
 * @parameter	none
 * @return	none
 */
void BinarySearchTree::print_tree() const
{
        printPretty(root, 1, 0, std::cout);
}

/*
 * Finds the parent of a given node
 *
 * @parameter	Node *node - A pointer to a node
 * 		Node *child - A pointer to the child. Searching for its parent
 *
 * @return	Node * - A pointer to the parent of the child
 */
Node *BinarySearchTree::find_parent(Node *node, Node *child) const
{
        if (node == NULL) return NULL;
        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left==child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}
