// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "LinkedList.h"

class DoubleLinkedList: public LinkedList
{
	public:
		DoubleLinkedList(); //Constructor
		virtual ~DoubleLinkedList(); //Destructor
		virtual void printList(); //prints out the DLL
		void insertLinkedNode(LinkedNode * node, HashEntry data); //inserts a linked node to DLL
		void insertAfterLinkedNode(LinkedNode * node, HashEntry data); //inserts a linked node to DLL after the current linked node
		void insertBeforeLinkedNode(LinkedNode * node, HashEntry data); //inserts a linked node to DLL before the current linked node
		int find(int key);
		void removeLinkedNode(int key);
	private:
		
	
};

#endif
