// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "HashEntry.h"

HashEntry::HashEntry() : key_(0), value_(0), status_(EMPTY) //Constructor
{



}

HashEntry::HashEntry(int key, int value) : key_(key), value_(value), status_(OCCUPIED) //Parameterized Constructor
{



}

HashEntry::~HashEntry() //Destructor
{


}

void HashEntry::setStatus(Status status) //Sets the status
{
	status_ = status;
}

Status HashEntry::getStatus() //Accesses the status
{
	return status_;
}

int HashEntry::getKey() //Returns the key
{
	return key_;
}

int HashEntry::getValue() //Returns the value
{
	return value_;
}

void HashEntry::setValue(int value) //Sets the value
{
	value_ = value;
}

void HashEntry::setKey(int key) //Sets the key
{
	key_ = key;
}
