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

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>

struct Node {
        int   data;
        int   count;
        Node *left;
        Node *right;
};

// defined in pretty_print.cpp
void printPretty(Node *root, int level, int indentSpace, std::ostream &out);

class BinarySearchTree {
public:
        BinarySearchTree();
        ~BinarySearchTree();
        BinarySearchTree(const BinarySearchTree &source);
        BinarySearchTree &operator= (const BinarySearchTree &source);

        int find_min() const;
        int find_max() const;

        bool contains(int value) const;
        void insert(int value);
        bool remove(int value);

        int tree_height() const;
        int node_count() const;
        int count_total() const;

        void print_tree() const;
private:
        Node *root;
        Node *find_min(Node *node) const;
        Node *find_max(Node *node) const;
        bool  contains(Node *node, int value) const;
        void  insert(Node *node,Node *parent, int value);
        //A function to create nodes
        Node *create_node(int value);
        bool  remove(Node *node, Node *parent, int value);
        bool  two_children(Node *node);
        bool  one_no_child(Node *node, Node *parent, int value);
        int   tree_height(Node *node) const;
        int   node_count(Node *node) const;
        int   count_total(Node *node) const;
        Node *pre_order_copy(Node *node) const;
        void  post_order_delete(Node *node);
        Node *find_parent(Node *node, Node *child) const;
};


#endif /* BINARYSEARCHTREE_H_ */
