// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include "HashTable.h"
#include "DoubleLinkedList.h"

class HashTableChaining : public HashTable
{	
	public:
		HashTableChaining(int size); //Constructor
		HashTableChaining(const HashTableChaining & hashChaining); //Copy Constructor
		virtual ~HashTableChaining(); //Destructor
		DoubleLinkedList * getEntry(); //Returns entry
		void setEntry(DoubleLinkedList * hashEntry); //Sets entry
		int getSize(); //Gets size
		void setSize(int size); //Sets size
		virtual void insert(int key, int value); //Inserts entry into a node
		virtual int search(int key); //Searches for provided entry
		virtual void remove(int key); //Removes entry from hash table
		virtual void print(); //Prints hash table
	private:
		HashTableChaining() {}
		DoubleLinkedList * entry_; //Creates a entry
		int size_; //Size of hash table
};

#endif