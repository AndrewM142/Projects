// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "LinkedNode.h"

//Constructor
LinkedNode::LinkedNode(HashEntry data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode) : Node(data), nextLinkedNode_(nextLinkedNode), prevLinkedNode_(prevLinkedNode)
{

}

//Copy Constructor
/*LinkedNode::LinkedNode(const LinkedNode & node) : Node(node.getValue()), nextLinkedNode_(nullptr), prevLinkedNode_(nullptr)
{
	LinkedNode * PrimaryNode = node.nextLinkedNode_; //Points to next node
	LinkedNode * currentLinkedNode = nullptr; //Initializes first node in list to nullptr
	
	if(PrimaryNode != nullptr) //If node has a nextLinkedNode
	{
		currentLinkedNode = new LinkedNode(PrimaryNode->getValue(), nullptr, nullptr); //Creates new node using primary node value
		
		nextLinkedNode_ = currentLinkedNode; //This instance is nextLinkedNode_ is equal to currentLinkedNode
		
		PrimaryNode = PrimaryNode->getNextLinkedNode(); //Primary Node is set equal to its next linked node
	}
	
	while(PrimaryNode != nullptr) //If node has a nextLinkedNode
	{
		LinkedNode * newNode = new LinkedNode(PrimaryNode->getValue(), nullptr, currentLinkedNode); //Creates new node with PrimaryNodes value, and is linked with currentLinkedNode as a previous node
		
		currentLinkedNode->nextLinkedNode_ = newNode; //sets currentLinkedNode's next Linked node to new node
		currentLinkedNode = newNode; //sets current linked node to new node for next time
		PrimaryNode = PrimaryNode->getNextLinkedNode(); //moves to next linked node for next time
	}
}*/

LinkedNode::~LinkedNode() //Destructor
{
	if(hasNextLinkedNode()) //Recursively deletes next linked nodes in a list
	{
		delete nextLinkedNode_;
	}
}

LinkedNode * LinkedNode::getNextLinkedNode() //Accesses next linked node in a list
{
	if (hasNextLinkedNode()) //Uses boolean to check for next linked node
	{
		return nextLinkedNode_; //returns next linked node
	}
		
	return nullptr; //returns nullptr if no next linked node
}
void LinkedNode::setNextLinkedNode(LinkedNode * node) //sets next linked node in a list
{
	nextLinkedNode_ = node;
}
bool LinkedNode::hasNextLinkedNode() //checks if the next linked node exists
{
	if (nextLinkedNode_ == nullptr) // if next linked node is nullptr
	{
		return false; //no next linked node
	}
	
	return true; //otherwise there is a next linked node 
}
/*HashEntry LinkedNode::getValue() //gets value of node /////////////////////////////////////////////////////////////////////////CHECK
{
	return Node::getValue();
}*/
LinkedNode * LinkedNode::getPrevLinkedNode() //accesses previous linked node in a list
{
	if (hasPrevLinkedNode()) //Uses boolean to check for prev linked node
	{
		return prevLinkedNode_; //returns prev linked node
	}
		
	return nullptr; // returns nullptr if no prev linked node
	
}
void LinkedNode::setPrevLinkedNode(LinkedNode * prevLinkedNode) //sets previous linked node in a list
{
	
	prevLinkedNode_ = prevLinkedNode;
	
}
bool LinkedNode::hasPrevLinkedNode() //checks if the previous linked node exists
{
	if (prevLinkedNode_ == nullptr) // if prev linked node is nullptr
	{
		return false; // no prev linked node
	}
	
	return true; //otherwise there is a prev linked node
}
