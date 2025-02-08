// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H

#include "HashTable.h"

enum Probing_Type{LINEAR, QUADRATIC}; //Type of probing that we desire to use

class HashTableArray : public HashTable
{	
	public:
		HashTableArray(int size, Probing_Type type); //Constructor
		HashTableArray(const HashTableArray & hashtablearray); //Copy Constructor
		~HashTableArray(); //Destructor
		HashEntry * getEntry(); //Returns hash entry
		void setEntry(HashEntry * hashEntry); //Sets hash entry
		virtual void insert(int key, int value); //Inserts a hash entry into table
		virtual int search(int key); //Searches for a hash entry 
		virtual void remove(int key); //Removes a hash entry
		virtual void print(); //Prints hash table
		int getHashFunction(int key); //Helper function, retrieves hash function
	private:
		HashEntry * entry_; //hash entry
		int size_; //size of table
		Probing_Type type_; //enum probing type
};

//convenience method to keep track of which type of probing we are using can be implemented

#endif