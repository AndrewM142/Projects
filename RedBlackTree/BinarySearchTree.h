// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"

class BinarySearchTree
{
	public:
		BinarySearchTree(); //Constructor
		BinarySearchTree(const BinarySearchTree & tree); //Copy Constructor
		virtual ~BinarySearchTree(); //Destructor
		void insert(int data); //Inserts a new node into the tree
		TreeNode * getRoot(); //Accesses the root of a tree
		void setRoot(TreeNode * root); //Sets the root of a tree
		void print(TreeNode * root); //prints the tree
		TreeNode * insertNode(TreeNode * root, TreeNode * node); //Helper function for insert
	private:
		TreeNode * root_; //Points to the root of a tree
};

#endif
