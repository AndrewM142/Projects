// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#ifndef NODE_H
#define NODE_H

#include "HashEntry.h"

class Node
{
	public:
		Node(HashEntry entry); //Constructor
		virtual ~Node(); //Destructor
		virtual HashEntry getValue(); //returns value of node
		void setData(HashEntry entry);
	private:
		//int data_; //value of node
		HashEntry entry_;
		
	protected:
		Node() {}
		
		
};

#endif