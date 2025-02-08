// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
	public:
		Node(int data = -1); //Constructor
		~Node(); //Destructor
		int getValue() const; //returns value of node
	private:
		int data_; //value of node
};

#endif
