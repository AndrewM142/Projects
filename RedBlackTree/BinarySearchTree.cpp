// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root_(nullptr) //Constructor
{


}

BinarySearchTree::BinarySearchTree(const BinarySearchTree & binarysearchtree) : root_(nullptr) //Copy Constructor
{
	if(binarysearchtree.root_ != nullptr) //If BST exists
	{
		root_ = new TreeNode(* binarysearchtree.root_); //Copies over root
	}
}

BinarySearchTree::~BinarySearchTree() //Destructor
{
	if(root_ != nullptr) //Recursively deletes the root of a tree
	{
		delete root_;
	}

}

void BinarySearchTree::setRoot(TreeNode * root) //Sets the root of a tree
{
	
	root_ = root;
	
}

TreeNode * BinarySearchTree::getRoot() //Accesses the root of a tree
{
	return root_;
}

void BinarySearchTree::insert(int data) //Inserts a new node into the tree
{
	TreeNode * newNode = new TreeNode(data); //Creates a new TreeNode
	
	root_ = insertNode(root_, newNode);	//Calls helper method with the root and the new node to insert into tree
}

TreeNode * BinarySearchTree::insertNode(TreeNode * root, TreeNode * node) //Helper function for insert
{
	if(root == nullptr) //Tree empty
	{
		return node;
	}
	else
	{
		if(node->getValue() < root->getValue()) //LEFT SUBTREE
		{
			root->setLeftChild(insertNode(root->getLeftChild(), node)); //Recursively finds correct space to insert as left child
			root->getLeftChild()->setParent(root); //Links with root of subtree		
				
		}
		else if(node->getValue() > root->getValue()) //RIGHT SUBTREE
		{
			root->setRightChild(insertNode(root->getRightChild(), node)); //Recursively finds correct space to insert as right child
			root->getRightChild()->setParent(root); //Links with root of subtree
			
		}
		else //duplicate case - we do not need to handle duplicates for this assignment
		{
			
			
		}
		
		return root;
	}
	
	
}

void BinarySearchTree::print(TreeNode * root) //prints as an inorder traversal
{
	if(root == nullptr) //tree empty
	{
		
	}
	else //prints recursively with inorder traversal
	{
		print(root->getLeftChild());
		
		std::cout << root->getValue() << " ";
		
		print(root->getRightChild());
	}
}
