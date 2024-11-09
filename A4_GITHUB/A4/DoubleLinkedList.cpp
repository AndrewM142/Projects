// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() : LinkedList() //Constructor
{
	
}
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList & linkedList) : LinkedList()
{
	LinkedNode * DoubleHead = LinkedList::getHead(); //DoubleHead is set to linked list head due to private variables
	
	LinkedNode * DoubleTail = LinkedList::getTail(); //DoubleTail is set to linked list tail due to private variables

	if(DoubleHead != nullptr) //If head of list is not nullptr
	{
		DoubleHead = new LinkedNode(DoubleHead->getValue(), nullptr, nullptr); //head points to new linked node with head value of previous list
		
		LinkedNode * PrimaryNode = DoubleHead->getNextLinkedNode(); //PrimaryNode points to head's next linked node
		
		LinkedNode * currentLinkedNode = DoubleHead; //currentLinkedNode points to head
		
		while(PrimaryNode != nullptr) //If head has next linked node
		{
			LinkedNode * linkedNode = new LinkedNode(PrimaryNode->getValue(), nullptr, currentLinkedNode); //creates a new node with the value of primary node, with a previous linked node of currentlinkednode
			
			currentLinkedNode->setNextLinkedNode(linkedNode); //currentLinkedNodes next linked node is set to linked node
			
			currentLinkedNode = linkedNode; //current linked node is set equal to linked node for next time
			
			PrimaryNode = PrimaryNode->getNextLinkedNode(); //primary node is moved to next node for next time
		}
		
		DoubleTail = currentLinkedNode; //set tail to currentlinkednode
	}
	
}
DoubleLinkedList::~DoubleLinkedList() //Destructor
{
	
}
void DoubleLinkedList::printList() //Prints out DLL
{
	if(!isEmpty())
	{
		LinkedNode * currentLinkedNode = LinkedList::getHead(); //sets currentLinkedNode to head
		
		std::cout << currentLinkedNode->getValue(); //prints out value of currentLinkedNode
		
		while(currentLinkedNode->hasNextLinkedNode()) //prints out value of all linked nodes in the list
		{
			currentLinkedNode = currentLinkedNode->getNextLinkedNode();
			std::cout << "<-->" << currentLinkedNode->getValue();
		}
		
		std::cout << std::endl;
	}	
	else
	{
		std::cout<<"Empty"<<std::endl;
	}
	
}
void DoubleLinkedList::insertLinkedNode(LinkedNode * node, int data) //Inserts a linked node
{
	LinkedNode * newNode = new LinkedNode(data, nullptr, nullptr); //Creates linked node
	
	if(!isEmpty()) //If DLL is not empty
	{
		if(node == LinkedList::getTail()) //if node is equal to tail derived from linked list
		{
			node->setNextLinkedNode(newNode); //set node's next linked node to newNode
			newNode->setPrevLinkedNode(node); //set newNode's previous linked node to node
			LinkedList::setTail(newNode); // set newNode to tail
		}
		else if(node == LinkedList::getHead()) //if node is equal to head derived from linked list
		{
			node->setPrevLinkedNode(newNode); //set node's previous linked node to newNode
			newNode->setNextLinkedNode(node); //set newNode's next linked node to node
			LinkedList::setHead(newNode); //set newNode to head
		}
		else
		{
			//Inserting after given linkednode if somewhere in list
			node->getNextLinkedNode()->setPrevLinkedNode(newNode);
			newNode->setNextLinkedNode(node->getNextLinkedNode());
			
			node->setNextLinkedNode(newNode); //sets nodes next linked node to newNode
			newNode->setPrevLinkedNode(node); //sets newNodes previous node to node
		}
	}
	else
	{
		//Only one node in DLL, so must be head and tail
		LinkedList::setHead(newNode); 
		LinkedList::setTail(newNode); 
	}	
}
void DoubleLinkedList::insertAfterLinkedNode(LinkedNode * node, int data) //inserts a linked node after the current linked node
{
	LinkedNode * newNode = new LinkedNode(data, nullptr, nullptr); //Creates linked node 
	
	if(!isEmpty())
	{
		LinkedNode * currentLinkedNode = node; //sets currentLinkedNode to passed through node
		
		if(currentLinkedNode == LinkedList::getTail()) //if CurrentLinkedNode is equal to tail derived from linked list
		{
			currentLinkedNode->setNextLinkedNode(newNode); //set currentLinkedNodes next node to newNode
			newNode->setPrevLinkedNode(currentLinkedNode); //set newNodes previous linked node to currentlinkednode
			LinkedList::setTail(newNode); //sets newNode to tail
		}
		else
		{
			newNode->setPrevLinkedNode(currentLinkedNode); //sets newNodes previous linked node to current linked node
			newNode->setNextLinkedNode(currentLinkedNode->getNextLinkedNode()); //sets newNodes next linked node to currentlinkednodes next linked node
			
			//Inserting after given linkednode if somewhere in list
			currentLinkedNode->getNextLinkedNode()->setPrevLinkedNode(newNode);
			currentLinkedNode->setNextLinkedNode(newNode);
		}
	}
	else
	{
		//Only one node in DLL, so must be head and tail
		LinkedList::setHead(newNode);
		LinkedList::setTail(newNode);	
	}
	//std::cout << "Inserting " << newNode->getValue() << "..." << std::endl;
}
void DoubleLinkedList::insertBeforeLinkedNode(LinkedNode * node, int data) //inserts a linked node before the current linked node
{
	LinkedNode * newNode = new LinkedNode(data, nullptr, nullptr); //creates temporary linked node
	
	if(!isEmpty())
	{
		LinkedNode * currentLinkedNode = node; //sets currentLinkedNode to passed through node
		
		if(currentLinkedNode == LinkedList::getHead()) //if CurrentLinkedNode is equal to head derived from linked list
		{
			currentLinkedNode->setPrevLinkedNode(newNode); //set currentlinkednodes previous node to newNode
			newNode->setNextLinkedNode(currentLinkedNode); //set newNodes next linked node to current linked node
			LinkedList::setHead(newNode); //sets newNode to head
		}
		else
		{
			newNode->setNextLinkedNode(currentLinkedNode); //sets newNodes next linked node to currentlinkednode
			newNode->setPrevLinkedNode(currentLinkedNode->getPrevLinkedNode()); //sets newNodes previous linked node to currentlinkednodes previous linked node
			
			//Inserting before given linkednode if somewhere in list
			currentLinkedNode->getPrevLinkedNode()->setNextLinkedNode(newNode);
			currentLinkedNode->setPrevLinkedNode(newNode);
		}
	}
	else
	{
		//Only one node in DLL, so must be head and tail
		LinkedList::setHead(newNode);
		LinkedList::setTail(newNode);
	}
}
