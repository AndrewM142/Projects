// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "LinkedList.h"

LinkedList::LinkedList() : head_(nullptr), tail_(nullptr) //Constructor
{
	
	
}
LinkedList::LinkedList(const LinkedList & linkedList) : head_(nullptr), tail_(nullptr)
{
	if(head_ != nullptr) //If list exists
	{
		head_ = new LinkedNode(linkedList.head_->getValue(), nullptr, nullptr); //Initializes the head of the new list with head value of previous list 
		
		LinkedNode * PrimaryNode = linkedList.head_->getNextLinkedNode(); //Points to head's next node
		
		LinkedNode * currentLinkedNode = head_; //Points to head of list
		
		while(PrimaryNode != nullptr) //While head of list has a next linked node
		{
			LinkedNode * newlinkedNode = new LinkedNode(PrimaryNode->getValue(), nullptr, currentLinkedNode); //creates a new node for new list with currentlinkednode as a previous node
			
			currentLinkedNode->setNextLinkedNode(newlinkedNode); //sets current linked nodes next node to linkednode
			
			currentLinkedNode = newlinkedNode; //current linked node is set equal to new linked node for next time
			
			PrimaryNode = PrimaryNode->getNextLinkedNode(); //primary node is moved to next node for next time
		}
		
		tail_ = currentLinkedNode; //set tail to current linked node
	}
}
LinkedList::~LinkedList() //Destructor
{
	if(head_ != nullptr) //Delete head if not set to nullptr
	{
		delete head_;
	}	
}
bool LinkedList::isEmpty()
{
	if(head_ != nullptr) //if list is empty
	{	
		return false;
	}
	else
	{	
		return true;
	}	
}
int LinkedList::getLength() //Retrieves length of linked list
{
	int count(0);
	
	if(!isEmpty()) //If list is not empty
	{
		count++; //Increases once for head node
		LinkedNode * node = head_; //points to head of list
		
		while(node->hasNextLinkedNode()) //counts all next linked nodes
		{
			count++;
			node = node->getNextLinkedNode();
		}
	}
	
	return count;
	
}
void LinkedList::insert(HashEntry element) //Inserts node into linked list
{
	insertLinkedNode(tail_, element); //Automatically set to tail as default
	
}
void LinkedList::printList() //prints linked list
{
	if(!isEmpty()) //If list is not empty
	{
		LinkedNode * currentLinkedNode = head_; //points to head of list
		
		std::cout << currentLinkedNode->getValue().getKey(); //prints value of head node
		
		while(currentLinkedNode->hasNextLinkedNode()) //prints value of next linked nodes
		{
			currentLinkedNode = currentLinkedNode->getNextLinkedNode();
			std::cout << "-->" << currentLinkedNode->getValue().getKey();
		}
		
		std::cout << std::endl;
	}	
	else
	{
		std::cout<<"Empty"<<std::endl;
	}	
}

//Helper Function

void LinkedList::insertLinkedNode(LinkedNode * node, HashEntry element) //Helps insert objects with referenced node
{
	LinkedNode * newLinkedNode = new LinkedNode(element, nullptr, nullptr);  //creates new LinkedNode
	
	if(!isEmpty()) //If list is not empty
	{
		if(node == tail_) //if referenced node is equal to tail
		{
			tail_ = newLinkedNode; //tail is set equal to the new linked node
			node->setNextLinkedNode(tail_); //the next linked node of referenced node is set to tail
		}
		else if(node == head_) //if referenced node is equal to head
		{
			head_ = newLinkedNode; // head is set equal to newLinkedNode
			head_->setNextLinkedNode(node); // the next linked node of head is set to node
		}
		else
		{
			//Inserting after given linkednode if somewhere in list
			newLinkedNode->setNextLinkedNode(node->getNextLinkedNode());
			node->setNextLinkedNode(newLinkedNode);
		}
	}
	else //List is empty
	{
		//Only one linked node in list, so it must be head and tail
		head_ = newLinkedNode;
		tail_ = newLinkedNode;
	}
}

LinkedNode * LinkedList::getHead() //Accesses the head of the linked list
{
	return head_;
}

void LinkedList::setHead(LinkedNode * head) //Sets the head of the linked list
{
	head_ = head;
}

LinkedNode * LinkedList::getTail() //Accesses the tail of the linked list
{
	return tail_;
}

void LinkedList::setTail(LinkedNode * tail) //Sets the tail of the linked list
{
	tail_ = tail;
}
