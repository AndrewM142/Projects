// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "TreeNode.h"

//Constructor Only one parameter data
TreeNode::TreeNode(int data) : Node(data), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr), color_(NONE) //Constructor
{



}

//Copy Constructor
TreeNode::TreeNode(const TreeNode & node) : Node(node.getValue()), parent_(nullptr), leftChild_(nullptr), rightChild_(nullptr), color_(NONE) //Copy constructor
{	
	color_ = node.color_; //Copies over color
	
	if(node.leftChild_ != nullptr) //If left child is not nullpointer
	{
		leftChild_ = new TreeNode(*node.leftChild_); //LeftChild_ is set to a new tree node that is set to the value of nodes left child
		leftChild_->setParent(this); //"this" is a pointer to the current object
	}
	else
	{
		leftChild_ = nullptr;
	}
	
	if(node.rightChild_ != nullptr) //If right child is not a nullpointer
	{
		rightChild_ = new TreeNode(*node.rightChild_); //RightChild_ is set to a new tree node that is set to the value of nodes right child
		rightChild_->setParent(this); //"this" is a pointer to the current object
	}
	else
	{
		rightChild_ = nullptr;
	}
}

TreeNode::~TreeNode() //Destructor
{
	if (leftChild_ != nullptr) //Recursively deletes left children
	{
		delete leftChild_;
	}
	
	if(rightChild_ != nullptr) //Recursively deletes right children
	{
		delete rightChild_;		
	}
}

TreeNode * TreeNode::getParent() //Accesses parent of a node
{
	return parent_;
}

TreeNode * TreeNode::getRightChild() //Accesses right child of a node
{

	return rightChild_;

}

TreeNode * TreeNode::getLeftChild() //Accesses left child of a node
{

	return leftChild_;

}

void TreeNode::setParent(TreeNode * parent) //Sets the parent of a node
{

	parent_ = parent;

}

void TreeNode::setLeftChild(TreeNode * leftChild) //Sets the leftChild of a node
{

	leftChild_ = leftChild;

}

void TreeNode::setRightChild(TreeNode * rightChild) //Sets the rightChild of a node
{

	rightChild_ = rightChild;

}

void TreeNode::setColor(Color color) //Sets the color of a node
{
	color_ = color;
}

Color TreeNode::getColor() //Accesses the color of a node
{
	return color_;
}
