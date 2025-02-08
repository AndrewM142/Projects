// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedNode.h"

class LinkedList : public Node
{
	public:
		LinkedList(); //Constructor
		virtual ~LinkedList(); //Destructor
		LinkedList(const LinkedList & linkedList); //Copy Constructor
		virtual bool isEmpty(); //Checks if list is empty
		virtual int getLength(); //Retrieves length of a list
		virtual void insert(HashEntry element); //inserts a node into a list
		virtual void printList(); //prints out list
		LinkedNode * getHead(); //Accesses the head of the list
		void setHead(LinkedNode * head); //sets the head of the list
		LinkedNode * getTail(); //Accesses the tail of the list
		void setTail(LinkedNode * tail); //sets the tail of the list
		void insertLinkedNode(LinkedNode * node, HashEntry element); //Helper Function for insert
		
	private:
		LinkedNode * head_; //pointer to the head of a linked list
		LinkedNode * tail_; //pointer to the tail of a linked list
};

#endif
