// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton
#include "Node.h"

Node::Node(HashEntry entry) : entry_(entry) //Constructor
{
	//entry_ = entry;
}

Node::~Node() //Destructor
{
	
}

HashEntry Node::getValue() //returns value of node
{
	return entry_;
}

void Node::setData(HashEntry entry)
{
	entry_ = entry;
}