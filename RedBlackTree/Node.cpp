// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "Node.h"

Node::Node(int data) : data_(data) //Constructor
{
	
}

Node::~Node() //Destructor
{
	
}

int Node::getValue() const //returns value of node
{
	return data_;
}
