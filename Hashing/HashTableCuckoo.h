// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#ifndef HASHTABLECUCKOO_H
#define HASHTABLECUCKOO_H

#include "HashTable.h"

class HashTableCuckoo : public HashTable
{	
	public:
		HashTableCuckoo(int size); //Constructor
		HashTableCuckoo(const HashTableCuckoo & hashingCuckoo); //Copy Constructor
		virtual ~HashTableCuckoo(); //Destructor
		virtual void insert(int key, int value); //Inserts entry into hash table
		virtual int search(int key); //searches for entry in hash table
		virtual void remove(int key); //removes entry from hash table
		virtual void print(); //prints entry in hash table
		int getSize(); //Returns size from hash table
		void setSize(int size); //Sets size from hash table
		HashEntry * getEntry(); //returns entry from hash table
		HashEntry * getEntry2(); //returns entry from 2nd hash table
		void setEntry(HashEntry * hashEntry); //Set entry in first hash table
		void setEntry2(HashEntry * hashEntry2); //Set entry in second hash table
		void setCycle(bool isCycle); //Set a cycle
		bool hasCycle(); //return cycle
	private:
		HashTableCuckoo() {}
		int getHashFunction1(int key); //Return hash function 1
		int getHashFunction2(int key); //Return hash function 2
		HashEntry * entry_; //Return entry1
		HashEntry * entry2_; //Return entry2
		int size_; //size of hash table array
		bool isCycle_; //boolean for if a cycle is occuring or not
};

#endif