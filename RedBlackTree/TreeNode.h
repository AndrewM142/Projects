// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#ifndef TREENODE_H
#define TREENODE_H

#include "Node.h"

enum Color {NONE, RED, BLACK}; //Enum Color

class TreeNode : public Node
{	
	public:
		TreeNode(int data); //Constructor
		TreeNode(const TreeNode & node); //Copy constructor
		virtual ~TreeNode(); //Destructor
		TreeNode * getLeftChild(); //Pointer to access left child
		TreeNode * getRightChild(); //Pointer to access right child
		TreeNode * getParent(); //Pointer to parent
		void setParent(TreeNode * Node); //Sets parent of node
		void setLeftChild(TreeNode * Node); //Sets leftChild of node
		void setRightChild(TreeNode * Node); //Sets rightChild of node
		void setColor(Color color); //Sets color of node
		Color getColor(); //Retrieves color of node
	private:
		TreeNode * leftChild_; //Left child of a node
		TreeNode * rightChild_; //Right child of a node
		TreeNode * parent_; //parent of a node
		Color color_; //Enum Color
};

#endif
