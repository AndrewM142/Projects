// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <iostream>

enum Status {EMPTY, OCCUPIED, REMOVED}; //Enum Color

class HashEntry
{	
	public:
		HashEntry(); //Constructor
		HashEntry(int key, int value); //Parameterized Constructor
		~HashEntry(); //Destructor
		int getKey(); //Returns key
		int getValue(); //Returns value
		Status getStatus(); //Retrieves status
		void setStatus(Status status); //Sets status
		void setValue(int value); //Sets value
		void setKey(int key); //Sets key
	private:
		int key_; //hash entry key
		int value_; //hash entry value
		Status status_; //Enum Color
};

#endif