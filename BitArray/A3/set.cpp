// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "set.h"

Set::Set(int size) : data_(BitArray(size)) //Constructor 
{
	
	
}

Set::~Set() //Destructor
{

	
}

void Set::initialize(char * word, int size) //Initializes bitArray using a provided character array of a given word and its size
{
	data_.initialize(word, size);
	
}

int Set::getCardinality() const //Retrieves the number of 1's present in the Bitarray
{
	int count(0);
	int bitVal(0);
	
	for(int i=0; i < data_.length(); i++)
	{
		bitVal = data_.get(i); //Retrieves data at given index
		if(bitVal == 1) //if bit is 1
		{
			count++; 
		}		
	}
	
	return count;
	
}

BitArray & Set::getData() //Retrieves data from bitArray
{
	return data_;
	
}

bool Set::setUnion(Set & B) //Retrives results of a union of set A and set B
{	
	if(data_.length() == B.getData().length()) //If both arrays are same size
	{
		
		//Initializes two unsigned char variables to have proper value ranges during computation.
		unsigned char setA = ' ';
		unsigned char setB = ' ';
		
		for(int i=0; i < data_.bytes(); i++) //Loops for amount of bytes
		{
			setA = data_.get8(i * 8); //Sets setA to ith byte in BitArray
			setB = B.data_.get8(i * 8); //Sets setB to ith byte in B set
			
			setA = setA | setB; //Computes union of Set A and Set B
			data_.set8(setA,i); //Sets computed union to BitArray
		}
		
		return true;
	}
	else
	{
		
		return false;
	}
}

bool Set::setIntersection(Set & B) //Retrieves results of a intersection of set A and set B
{	
	if(data_.length() == B.getData().length())
	{
		
		//Initializes two unsigned char variables inorder to have proper value ranges during computation.
		unsigned char setA = ' ';
		unsigned char setB = ' ';
		
		for(int i=0; i < data_.bytes(); i++)
		{
			setA = data_.get8(i * 8); //Sets setA to ith byte in BitArray
			setB = B.data_.get8(i * 8); //Sets setB to ith byte in B set
			
			setA = setA & setB; //Computes intersection of Set A and Set B
			data_.set8(setA, i); //Sets computed intersection to BitArray
		}
		
		return true;
	}
	else
	{
		
		return false;
	}
}
