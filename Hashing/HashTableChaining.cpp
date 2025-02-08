// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "HashTableChaining.h"

HashTableChaining::HashTableChaining(int size) : HashTable(), size_(0) //Constructor
{
	size_ = size;
	entry_ = new DoubleLinkedList[size_]; //creates new DoubleLinkedList of size
	
	for(int i = 0; i < size; i++) //Fills list with empty entries
	{
		entry_[i].getValue().setStatus(EMPTY);
	}
}

HashTableChaining::HashTableChaining(const HashTableChaining & hashChaining) : size_(hashChaining.size_), entry_(new DoubleLinkedList[hashChaining.size_]) //Copy constructor
{
	for(int i = 0; i < size_; i++) //copys entries over
	{
		entry_[i] = hashChaining.entry_[i];
	}	
}

HashTableChaining::~HashTableChaining() //Destructor
{
	delete [] entry_;
}

void HashTableChaining::insert(int key, int value) //Inserts a hash entry into a node
{
	int hashProbing = key % size_; //Sets hashProbing to basic hash function formula
	HashEntry newEntry(key, value); //Creates new entry with key and value
	LinkedNode * newNode = new LinkedNode(newEntry, nullptr, nullptr); //Creates new node of entries
	
	if(entry_[hashProbing].getHead() == nullptr) //Insert at head if nullptr
	{
		entry_[hashProbing].insert(newEntry); //Inserts new entry
	}
	else //Insert at tail
	{
		entry_[hashProbing].insertLinkedNode(entry_[hashProbing].getTail(), newEntry);
	}
	
	delete newNode; //Delete newNode
}

int HashTableChaining::search(int key) //Searches for hash entry
{
	int hashProbing = key % size_; //Sets hashProbing to basic hash function formula
	
	if(entry_[hashProbing].getValue().getKey() == key) //If key maps to specific hash entry
	{
		return entry_[hashProbing].getValue().getValue(); //return value of hash entry
	}
	else
	{
		return entry_[hashProbing].find(key); //Calls a helper function from double linked list
	}
}

void HashTableChaining::remove(int key) // remove a hash entry
{
	int hashProbing = key % size_; // Sets hashProbing to basic hash function formula
	
	if(entry_[hashProbing].find(key) == -1) //Protects from invalid input
	{
		std::cout << std::endl;
		std::cout << "Invalid Key " << key << " not found in table!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		entry_[hashProbing].removeLinkedNode(key); //Calls helper function from double linked list using key
	}
	
}

void HashTableChaining::print() //Prints out hash table
{
	std::cout << "***********************************" << std::endl;
	for(int i = 0; i < size_; i++) //Runs for size
	{
		std::cout << "[" << i << "]: "; //prints position of hash table
		entry_[i].printList(); //Calls print list from DoubleLinkedList to put in correct DLL form
	}
	std::cout << "***********************************" << std::endl;
	std::cout << std::endl;
}

DoubleLinkedList * HashTableChaining::getEntry() //Returns entry
{
	return entry_;
}

void HashTableChaining::setEntry(DoubleLinkedList * hashEntry) //Sets entry
{
	entry_ = hashEntry;
}

int HashTableChaining::getSize() //Returns size
{
	return size_;
}
		
void HashTableChaining::setSize(int size) //Sets size
{
	size_ = size;
}