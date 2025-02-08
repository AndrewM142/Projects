// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Node.h"

class LinkedNode : public Node
{
	public:
		LinkedNode(HashEntry entry, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode); //Constructor
		//LinkedNode(const LinkedNode & node); //Copy Constructor
		virtual ~LinkedNode(); //Destructor
		LinkedNode * getNextLinkedNode(); //Accesses the next linked node in a list
		LinkedNode * getPrevLinkedNode(); //Accesses the previous linked node in a list
		void setNextLinkedNode(LinkedNode * node); //Sets the next linked node in a list
		void setPrevLinkedNode(LinkedNode * prevLinkedNode); //Sets the next linked node in a list
		bool hasNextLinkedNode(); //Checks if the next linked node exists
		bool hasPrevLinkedNode(); //Checks if the previous linked node exists
		//HashEntry getValue(); //returns value of node

	private:
		LinkedNode * nextLinkedNode_; //pointer to the next linked node
		LinkedNode * prevLinkedNode_; //pointer to the previous linked node
		LinkedNode() {}
};

#endif
