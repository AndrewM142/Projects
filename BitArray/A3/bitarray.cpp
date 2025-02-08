// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "bitarray.h"

BitArray::BitArray(int size) : data_(nullptr), LENGTH(BYTES * BIT_IN_BYTE), BYTES(size) //Default Constructor
{
	

}

BitArray::BitArray(const BitArray & array) : LENGTH(array.LENGTH), BYTES(array.BYTES) //Copy Constructor
{
	//Deep copy, copies over contents from initial array to new array
	
	data_ = new char[BYTES];
		
	for(int i = 0; i < BYTES; i++) //Creates deep copy, Copies data from initial array to new array
	{	
		data_[i] = array.data_[i];
	}
	
}

BitArray::~BitArray() //Destructor
{
	if(data_ != nullptr) //Keeps from segfault
	{
		delete [] data_;
	}
	
}

bool BitArray::get(int position) const //Gets a bit at a given position
{
	int BitIndex = (position)/BIT_IN_BYTE; //Initializes BitIndex with a given position
	position = position % BIT_IN_BYTE; //Assigns position of a bit within the byte back to position
	
	if((data_[BitIndex] & (1 << ((BIT_IN_BYTE-1) - position))) !=0) //If bit found by using the AND operation on data_ at BitIndex and a left shift on the bit != 0
	{
	
		return true;	
	}
	else
	{
		
		return false;
	}
	
}

//
// void print()
//
void BitArray::print() //Prints a bitarray into physical sets of bytes with proper syntax.
{	
	std::cout << "|";
	
	for (int i=0; i < BYTES; i++)
	{
		std::bitset<BIT_IN_BYTE> bits = data_[i];
		std::cout << bits << "|";
	}
	
	std::cout << std::endl;	
}

void BitArray::initialize(char * word, int size) //Initializes bitArray using a provided character array of a given word and its size
{
	BYTES = size; //Sets BYTES equal to size
	LENGTH = size * BIT_IN_BYTE; //Sets LENGTH equal to size times BIT_IN_BYTE
	
	delete [] data_; //Clears data before using
	data_ = new char[size]; //Allocates new memory for the bitArray
	
	for(int i = 0; i < size; i++) //For size of word, copies character values to BitArray
	{
		data_[i] = word[i];
	}	
}

bool BitArray::flip(int position) //Flips a bit from 1 or 0 to opposite number at a specified index
{	
	if(position < LENGTH) //Protects from out of bounds error
	{
		
		int BitIndex = position/BIT_IN_BYTE; //Initializes BitIndex with a given position
			
		position = position%BIT_IN_BYTE; //Assigns position of a bit within the byte back to position
				
		data_[BitIndex] ^= (1 << (7-position)); //Uses XOR on data at BitIndex, and shifted position to flip the bit
		
		return true;
	}
	else
	{
		
		return false;
	}
}

bool BitArray::set(int position, int bit) //Sets a bit at a specified position
{
	if(position < LENGTH) //Protects from out of bounds error
	{
		int BitIndex = (position)/BIT_IN_BYTE; //Initializes bitarrayIndex with a given position
		
		position = position%BIT_IN_BYTE; //Assigns position of a bit within the byte back to position
		
		if(bit == 1) //If bit is equal to the value 1
		{
			data_[BitIndex] |= (1 << (7 - position)); //Set bit using OR operator on data at BitIndex and bitmask
		}
		else
		{
			data_[BitIndex] &= ~(1 << (7 - position)); //Set bit using AND with compliment on data at BitIndex and bitmask
		}
		
		return true;
	}
	else
	{
		return false;
	}
}


char BitArray::get8(int position) const //Returns the character in the byte (8 bits) within the BitArray given a specified position.
{
	
	return data_[position / BIT_IN_BYTE]; //Returns character in the byte at provided position
	
}

void BitArray::complement() //Flips all bits in the array from 1 or 0 to its opposite
{
	for(int i=0; i < LENGTH; i++) //For length of bitArray
	{
		flip(i); //Flips each bit
	}	
}

void BitArray::clear() //Clears bitArray to all 0's
{
	for(int i=0; i < BYTES; i++) //For num of bytes in bitArray
	{
		data_[i] = 0; //Sets each bit at each position to 0
	}
}

void BitArray::set8(char c, int index) //Sets the character in given byte with a specified index for the character array
{
	data_[index] = c; //Sets byte at index to provided char c
	
}
