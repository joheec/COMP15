/*
 * main.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: chrisgregg
 */

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

void print_tree_details(BinarySearchTree &bst) {
        bst.print_tree();
        cout << "\n";
        cout << "min: " << bst.find_min() << "\n";
        cout << "max: " << bst.find_max() << "\n";
        cout << "nodes: " << bst.node_count() << "\n";
        cout << "count total: " << bst.count_total() << "\n";
        cout << "tree height: " << bst.tree_height() << "\n";
        cout << "\n";
}

void test_big_three() {
	//copy constructor
	BinarySearchTree tree1;
	tree1.insert(1);
	BinarySearchTree tree2 = tree1;
	tree2.insert(2);

	//assignment operator
	BinarySearchTree tree3;
	tree3 = tree2;
	tree3.insert(3);

	tree1.print_tree();
	tree2.print_tree();
	tree3.print_tree();

	//assignment operator with existing data
	BinarySearchTree tree4;
	tree4.insert(3);
	tree3.insert(4);
	tree4 = tree3;

	cout << "2nd tree3 w/ a 4.\n";
	tree3.print_tree();
	tree4.print_tree();
}

void test_insert(BinarySearchTree * tree) {
//	BinarySearchTree tree;
	tree->insert(5);
//	tree.print_tree();
	tree->insert(5);
//	tree.print_tree();
	tree->insert(2);
//	tree.print_tree();
	tree->insert(8);
//	tree.print_tree();
//	tree->insert(2);
////	tree.print_tree();
	tree->insert(9);
////	tree.print_tree();
	tree->insert(3);
////	tree.print_tree();
	tree->insert(7);
////	tree.print_tree();
}

void test_duplicate_count() {
	BinarySearchTree tree;
	tree.insert(4);
	tree.insert(4);
	tree.insert(4);
	tree.insert(4);
}

void test_find_min() {
	BinarySearchTree * tree = new BinarySearchTree;
	test_insert(tree);
	cout << tree->find_min() << "\n";
}

void test_find_max() {
	BinarySearchTree * tree = new BinarySearchTree;
	test_insert(tree);
	cout << tree->find_max() << "\n";
}

void test_contains() {
	BinarySearchTree * tree = new BinarySearchTree;
	test_insert(tree);
	cout << "Contains -2? (false): " << tree->contains(-2) << "\n";
	cout << "Contains 7? (true): " << tree->contains(7) << "\n";
}
void test_remove() {
	BinarySearchTree * tree = new BinarySearchTree;
	//remove empty tree
	cout << tree->remove(2);
	test_insert(tree);
	tree->print_tree();
	//remove 2 children
	tree->remove(8);
	tree->print_tree();
	//remove 1 child
	tree->remove(2);
	tree->print_tree();
	//remove no children
	tree->remove(3);
	tree->print_tree();
	//remove no parent
	tree->remove(5);
	tree->print_tree();
	tree->remove(5);
	tree->print_tree();
	//remove doesn't exist
	tree->remove(8);
	tree->print_tree();
	//remove only right child
	tree->insert(10);
	tree->insert(11);
	tree->insert(12);
	tree->print_tree();
	tree->remove(10);
	tree->print_tree();

}

int main() {

//	test_big_three();
//	test_insert();
//	test_duplicate_count();
//	test_find_min();
//	test_find_max();
//	test_contains();
	test_remove();

//        int values[14] = {4,2,11,15,9,1,-6,5,3,15,2,5,13,14};
//        BinarySearchTree bst;
//        for (int i=0;i<14;i++) {
//                bst.insert(values[i]);
//        }
//        cout << "Original tree " <<
//                        "(asterisks denote a count of more than 1):\n";
//        print_tree_details(bst);
//
//        // make a copy with copy constructor
//        BinarySearchTree bst_copy_constructor = bst;
//        //bst_copy_constructor.print_tree();
//
//        // make a copy with assignment overload
//        BinarySearchTree bst_copy_1;
//        bst_copy_1 = bst;
//
//        cout << "Removing 9 from original tree:\n";
//        bst.remove(9); // remove a node with no children
//        print_tree_details(bst);
//
//        bst = bst_copy_1;
//
//        cout << "Removing 1 from original tree:\n";
//        bst.remove(1); // remove a node with one child
//        print_tree_details(bst);
//
//        bst = bst_copy_1;
//
//        cout << "Removing 11 from original tree:\n";
//        bst.remove(11); // remove a node with one child
//        print_tree_details(bst);
//
//        bst = bst_copy_1;
//
//        cout << "Removing 5 from original tree " <<
//                        "(should still have one 5):\n";
//        bst.remove(5); // remove a node with one child
//        print_tree_details(bst);
//
//        // check if the tree contains values
//        bst = bst_copy_1;
//        for (int i=-10;i<20;i++) {
//                cout << "Tree " << (bst.contains(i) ?
//                                "contains " :
//                                "does not contain ")
//                                << "the value " << i << "\n";
//        }
//
//        cout << "\nFinished!\n";
        return 0;
}
