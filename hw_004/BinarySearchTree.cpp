/*
 * BinarySearchTree.cpp
 */

#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>

#include "BinarySearchTree.h"

using namespace std;

/*
 * Constructor
 */
BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

/*
 * Destructor
 */
BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
}

/*
 * @parameter	Node*	node	The pointer to the node and its children that
 * 				are to be deleted.
 * @return	void
 *
 * Using a post-order traversal to remove all nodes
 */
void BinarySearchTree::post_order_delete(Node *node)
{
	// base case for recursion: delete node with no children.
	if(node == NULL) {
		return;
	}
	//delete the left and then right children
	if(node->left != NULL) {
		post_order_delete(node->left);
	}
	if(node->right != NULL) {
		post_order_delete(node->right);
	}

	delete node;
}

/*
 * Copy Constructor
 */
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        // use pre-order traversal to copy the tree
        root = pre_order_copy(source.root);
}

/*
 * Assignment overload
 */
BinarySearchTree &BinarySearchTree::operator= (const BinarySearchTree &source)
{
        // check for self-assignment
	if(this == &source) {
		return * this;
	}

        // delete current tree if it exists
	post_order_delete(this->root);

        // use pre-order traversal to copy the tree
	this->root = pre_order_copy(source.root);

        // don't forget to "return *this"

	return * this;
}

/*
 * @parameter	Node *	node	A pointer to the tree that is to be copied
 * @return	Node *	new_node	A pointer to the new node created
 * 					from the parameter node.
 *
 * Using a pre-order traversal to copy details from the node to a new_node.
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

        //using recursion to copy the left then the right potential subtree.
	new_node->left = pre_order_copy(node->left);
	new_node->right = pre_order_copy(node->right);

        return new_node;
}

int BinarySearchTree::find_min() const
{
        if (root == NULL)
                return INT_MIN;
        return find_min(root)->data;
}

Node *BinarySearchTree::find_min(Node *node) const
{
        if(node->left == NULL) {
        	return node;
        }
        //traverse left to find min
        return find_min(node->left);
}

int BinarySearchTree::find_max() const
{
        if(root == NULL) {
        	return INT_MAX;
        }

        return find_max(root)->data;
}

Node *BinarySearchTree::find_max(Node *node) const
{
        if(node->right == NULL) {
        	return node;
        }
        //traverse right to find max
        return find_max(node->right);
}

bool BinarySearchTree::contains(int value) const
{
        return contains(root, value);
}

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

void BinarySearchTree::insert(int value)
{
        insert(root, NULL, value);
}

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

Node *BinarySearchTree::create_node(int value)
{
	Node * new_node = new Node;
	new_node->data = value;
	new_node->count = 1;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

bool BinarySearchTree::remove(int value)
{
        return remove(root, NULL, value);
}

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
		return remove_two_child(node, parent, value);
	} else {
		return remove_one_no_child(node, parent, value);
	}
}

bool BinarySearchTree::remove_two_child(Node * node, Node * parent, int value)
{
	//removed node has 2 children
	Node * moved_node = find_min(node->right);
	if(node->right == moved_node) {
		node->right = NULL;
	} else {
		node->left = NULL;
	}
	//reset the parent pointer of moved_node then delete
	node->data = moved_node->data;
	delete moved_node;
	return true;
}

bool BinarySearchTree::remove_one_no_child(Node *node,Node *parent,int value)
{
	//if node has one or no children
	if(parent != NULL) {
		Node ** par = NULL;
		par = parent->data > value ? &parent->left : &parent->right;
		if(node->left != NULL) {
			*par = node->left;
		} else {
			*par = node->right;
		}
	}
	cerr << node;
	delete node;
	return true;
}

int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}

int BinarySearchTree::tree_height(Node *node) const
{
        // TODO: Students write code here
	(void) node;
	return 0;
}

// returns the total number of nodes
int BinarySearchTree::node_count() const
{
        return node_count(root);
}

int BinarySearchTree::node_count(Node *node) const
{
        // TODO: Students write code here
	(void) node;
	return 0;
}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() const
{
        return count_total(root);
}

int BinarySearchTree::count_total(Node *node) const
{
        // TODO: Students write code here:
	(void) node;
	return 0;
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        printPretty(root, 1, 0, std::cout);
}

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
