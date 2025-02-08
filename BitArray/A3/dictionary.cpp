// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "dictionary.h"

Dictionary::Dictionary() : lookupTable_(new int[DICTIONARY_SIZE]) //Constructor
{
	for(int i = 0; i < DICTIONARY_SIZE; i++) //Loops for DICTIONARY_SIZE
	{
		Set set1; //Temp Set
		char temp[1]; //Temp Char Array
		temp[0] = i; //Sets temp at position 0 to different cases between 0 and dictionary size
		
		set1.initialize(temp, 1); //Initializes set1 with temp array
		lookupTable_[i] = set1.getCardinality(); //Gets cardinality for all lookupTable cases
		
	}
	
}

Dictionary::Dictionary (const Dictionary & dict) : lookupTable_(nullptr) //Copy Constructor
{
	//Creates a deepcopy
	if(dict.lookupTable_) //If lookupTable not null
	{
		lookupTable_ = new int[DICTIONARY_SIZE]; //Initializes a new lookupTable
		
		for(int i = 0; i < DICTIONARY_SIZE; i++) //For dictionary size
		{
			lookupTable_[i] = dict.lookupTable_[i];	//Copys values to a new lookUpTable array
		}
	}
}

Dictionary::~Dictionary() //Destructor
{
	if(lookupTable_ != nullptr) //Protects against Segfault
	{
		delete [] lookupTable_; //Deletes lookupTable
	}	
}

void Dictionary::initialize(char * word, int size) //Initializes bitArray using a provided character array of a given word and its size
{
	data_.initialize(word,size);
	
	
}

int Dictionary::rank_range(int start, int end, int bit) //Left to Right, Start is inclusive [, End is exclusive )
{
	int count(0);
	
	for(int i = start; i < end; i++) //Loops from start to end
	{
		if(bit == 1) //if bit is equal to the value 1
		{
			if(data_.get(i)) //if bit is equal to 1 at position i
			{
				count++; //increases count by 1
			}
		}
		else
		{
			if(!data_.get(i)) //if bit is not equal to 1 at position i
			{
				count++; //increases count by 1
			}
		}
	}
	
	return count;
}

int Dictionary::select_range(int start, int end, int k, int bit) //Left to Right, Start is inclusive [, End is exclusive )
{
	int count(0);
	
	for(int i = start; i < end; i++) //Loops from start to end
	{
		if(bit == 1) //If bit is equal to value 1
		{
			if(data_.get(i)) //If bit is equal to 1 at position i
			{
				count++; //increases count by 1
				
				if(count == k) //If count reaches provided value of k
				{
					return i;
				}
			}
		}
		else
		{
			if(!data_.get(i)) //If bit is not equal to 1 at position i
			{
				count++; //increase count by 1
				
				if(count == k) //If count reaches provided value of k
				{
					return i;
				}
			}
		}
	}
	
	return -1; //Occurs if count never reaches k
}


int Dictionary::rank(int end, int bit) //Left to Right, Start is inclusive [, End is exclusive )
{
	//PHASE IV Rank
	
	/*
	int count(0);
	
	for(int i = 0; i < end; i++) //Runs from 0 to end value
	{
		if(bit == 1) //If bit is equal to value 1
		{
			if(data_.get(i)) //If bit is equal to 1 at position i
			{
				count++; //increases count by 1
			}
		}
		else
		{
			if(!data_.get(i)) //If bit is not equal to 1 at position 1
			{
				count++; //increases count by 1
			}
		}
	}

	return count;
	*/
	
	
	//PHASE V RANK
	
	int count = 0; //Initializes count at 0
	
	int position = end / BIT_IN_BYTE; //Determines number of complete bytes 
	
	int LeftOverPosition = 0; //Initializes LeftOverPosition at 0
	
	for(int i=0; i < position; i++) //For position length
	{		
		count = count + lookupTable_[data_.get8(i*BIT_IN_BYTE)]; //Adds amount of desired bit to count
	}
	
	LeftOverPosition = end % BIT_IN_BYTE; //Determines leftover bits in last byte if applicable
	
	if(LeftOverPosition != (BIT_IN_BYTE - 1)) //If leftover bits in last byte
	{
		count = count + rank_range((position * BIT_IN_BYTE), end, bit); //Add leftover bits in last byte to count
	}
	
	return count;
	
}

int Dictionary::select(int k, int bit) //Left to Right, Start is inclusive [, End is exclusive )
{
	//PHASE IV select
	
	/*
	int count(0);
	
	for(int i = 0; i < data_.length(); i++) //Loops from 0 to length of BitArray
	{
		if(bit == 1) //If bit is equal to value 1
		{
			if(data_.get(i)) //If bit is equal to positon i
			{
				count++; //increases count by 1
			}	
			if(count == k) //If count reaches provided value of k 
			{
				return i;
			}
			
		}
		else
		{
			if(!data_.get(i)) //If bit is not equal to position i
			{
				count++; //increases count by 1
			}
			if(count == k) //If count reaches provided value of k
			{
				return i;
			}
		}
	}
	
	return -1; //Occurs if count never reaches k
	*/
	
	
	//PHASE V SELECT
	
	int count(0); //Initializes count
	int EndByte(0); //Initializes EndByte - Refers to last byte
	int Edge(0); //Initializes Edge - Used to prevent Edge Case
		
	for(int i=0; i < data_.bytes(); i++) //For length of data_.bytes
	{		
		count = count + lookupTable_[data_.get8(i*BIT_IN_BYTE)]; //Adds amount of desired bit to count
		
		if((count + EndByte) >= k) //If the kth occurence of a bit is in the current byte
		{
			return select_range((i * BIT_IN_BYTE), ((i + 1) * BIT_IN_BYTE), k - EndByte, bit); //Returns position of the kth occurence of a bit
		}
		else
		{
			EndByte = count; //If kth occurence is not in current byte, set EndByte equal to count
		}
	}
	
	Edge = select_range(0, BIT_IN_BYTE, k, bit); //Calls regular select_range to prevent edge case if kth occurence doesn't occur
	
	return Edge; //return location for edge case prevention
	
}

void Dictionary::printLookupTable(std::ostream & output) //Writes output of lookup table
{
	std::cout << "Printing Lookup Table..." << std::endl;
	
	for(int i = 0; i < DICTIONARY_SIZE; i++) //Prints all possible byte combinations
	{
		output<< "lookupTable_[" << i << "]" << " " << lookupTable_[i] << std::endl; //Writes data to lookupTable	
	}
}
