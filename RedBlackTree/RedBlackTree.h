// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "BinarySearchTree.h"

class RedBlackTree : public BinarySearchTree
{
	public:
		RedBlackTree(); //Constructor
		virtual ~RedBlackTree(); //Virtual Destructor
		virtual void insert(int data); //Virtual implementation of BST insert
		void printRedNodes(TreeNode * root); //Prints Red nodes in RBT
		void printBlackNodes(TreeNode * root); //Prints Black nodes in RBT
		
	private:
		void rotateLeft(TreeNode *& root, TreeNode *& newNode); //Left rotate on RBT
		void rotateRight(TreeNode *& root, TreeNode *& newNode); //Right rotate on RBT
		void balanceColor(TreeNode *& root, TreeNode *& newNode); //Balances the color according to RBT rules
};

#endif
