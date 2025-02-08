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
DoubleLinkedList::~DoubleLinkedList() //Destructor
{
	
}
void DoubleLinkedList::printList() //Prints out DLL
{
	if(!isEmpty())
	{
		LinkedNode * currentLinkedNode = LinkedList::getHead(); //sets currentLinkedNode to head
		
		std::cout << currentLinkedNode->getValue().getKey(); //prints out value of currentLinkedNode
		
		while(currentLinkedNode->hasNextLinkedNode()) //prints out value of all linked nodes in the list
		{
			currentLinkedNode = currentLinkedNode->getNextLinkedNode();
			std::cout << "<-->" << currentLinkedNode->getValue().getKey();
		}
		
		std::cout << std::endl;
	}	
	else
	{
		//std::cout<<"Empty"<<std::endl;
		std::cout << std::endl;
	}
	
}
void DoubleLinkedList::insertLinkedNode(LinkedNode * node, HashEntry data) //Inserts a linked node
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
void DoubleLinkedList::insertAfterLinkedNode(LinkedNode * node, HashEntry data) //inserts a linked node after the current linked node
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
void DoubleLinkedList::insertBeforeLinkedNode(LinkedNode * node, HashEntry data) //inserts a linked node before the current linked node
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

int DoubleLinkedList::find(int key) //provided
{
	LinkedNode * find = getHead(); //set find equal to head of list
	while(find != nullptr) //Iterate through nodes until find equals nullptr
	{
		if(find->getValue().getKey() == key) //If nodes key is mapped to passed through key
		{
			return find->getValue().getValue(); //return the value of the node
		}
		find = find->getNextLinkedNode(); //move to next node
	}
	return -1; //return -1 if conditions fail
	delete find; //delete find
}

void DoubleLinkedList::removeLinkedNode(int key) //provided, added several checks to eliminate data leaks and seg faults
{
	bool isFound(false); //initialize to false
	
	if(isEmpty()) //If list is empty
	{
		std::cout << "List is Empty." << std::endl;
		
		//return;
	}
	else
	{
		if(key == getHead()->getValue().getKey() && getHead() == getTail()) //If key is equal to the key of the head node, and there is only one node
		{
			LinkedNode * currentNode = LinkedList::getHead(); //set current node to head
			setHead(nullptr); //set head to nullptr
			setTail(nullptr); //set tail to nullptr
			delete currentNode; //delete node
			
			std::cout << std::endl;
			std::cout << "Key " << key << " removed" << std::endl;
			std::cout << std::endl;
			
			isFound = true; //key was found
		}
		else if(key == LinkedList::getHead()->getValue().getKey()) //If key is equal to the key of the head node but there are multiple nodes
		{
			LinkedNode * oldHead = LinkedList::getHead(); //set oldhead to head
			LinkedNode * newHead = LinkedList::getHead()->getNextLinkedNode(); //set newhead to heads next node
			
			LinkedList::setHead(newHead); //set the head of the list to newhead
			
			oldHead->setNextLinkedNode(nullptr); //set oldheads next linked node to nullptr
			newHead->setPrevLinkedNode(nullptr); //set newheads prev linked node to nullptr
			
			delete oldHead; //delete oldhead
			
			std::cout << std::endl;
			std::cout << "Key " << key << " removed" << std::endl;
			std::cout << std::endl;
			
			isFound = true; //key was found
		}
		else if(key == LinkedList::getTail()->getValue().getKey()) //If key is equal to the key of the tail node but there are multiple nodes
		{
			LinkedNode * oldTail = LinkedList::getTail(); //set old tail to the tail of the list
			LinkedNode * newTail = LinkedList::getTail()->getPrevLinkedNode(); //set new tail to the node before the tail
			
			LinkedList::setTail(newTail); //set tail to new tail
			
			newTail->setNextLinkedNode(nullptr); //set newtails next linked node to nullptr
			oldTail->setPrevLinkedNode(nullptr); //set oldtails prev linked node to nullptr
			
			delete oldTail; //delete oldtail
			
			std::cout << std::endl;
			std::cout << "Key " << key << " removed" << std::endl;
			std::cout << std::endl;
			
			isFound = true; //key was found
		}
		else
		{
			LinkedNode * curNode = LinkedList::getHead(); //set curnode equal to the head of the list
			
			while(curNode != nullptr && !isFound) //while curnode is not a nullptr and key has not been found
			{
				if(curNode->getValue().getKey() == key) //if curnodes key maps to key
				{
					LinkedNode * nextNode = curNode->getNextLinkedNode(); //nextnode is set equal to curNodes next linked node
					LinkedNode * prevNode = curNode->getPrevLinkedNode(); //prevnode is set equal to curNodes prev linked node
					
					nextNode->setPrevLinkedNode(prevNode); //nextnodes previous linked node is set to prevnode
					prevNode->setNextLinkedNode(nextNode); //prevnodes next linked node is set to nextnode
					
					curNode->setPrevLinkedNode(nullptr); //curnodes previous linked node is set to nullptr
					curNode->setNextLinkedNode(nullptr); //curnodes next linked node is set to nullptr
					
					delete curNode; //delete curnode
					
					std::cout << std::endl;
					std::cout << "Key " << key << " removed" << std::endl;
					std::cout << std::endl;
					
					isFound = true; //key was found
				}
				else
				{
					curNode = curNode->getNextLinkedNode(); //Iterates through the DLL
				}
			}
		}
		
		if(!isFound)
		{
			std::cout << "Element does not exist in List." << std::endl;
		}
		else
		{
			
		}
	}
}