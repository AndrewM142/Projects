// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "HashTableArray.h"

HashTableArray::HashTableArray(int size, Probing_Type type) : HashTable(), size_(0), type_(LINEAR) //Constructor
{
	if(size > 0) //If at least one entry is created
	{
		entry_ = new HashEntry[size]; //create new hash entry array of size
		
		for(int i = 0; i < size; i++) //fills array with new empty entries
		{
			HashEntry newEntry;
			newEntry.setStatus(EMPTY);
			entry_[i] = newEntry;
		}
		
		size_ = size;
		type_ = type;
	}
}

HashTableArray::HashTableArray(const HashTableArray & hashtablearray) : size_(hashtablearray.size_), entry_(new HashEntry[hashtablearray.size_]), type_(LINEAR) //Copy Constructor
{
	for(int i = 0; i < size_; i++) //Copies entries over
	{
		entry_[i] = hashtablearray.entry_[i];
	}	
}

HashTableArray::~HashTableArray() //Destructor
{
	delete [] entry_;
}

void HashTableArray::insert(int key, int value) //Inserts key and value to empty entries
{
	HashEntry newEntry(key,value); //Give key and value to a hash entry
	newEntry.setStatus(OCCUPIED); //new Entry is now occupied
	
	int hashValue(0);
	
	hashValue = getHashFunction(key); //Accesses helper function
	
	if(entry_[hashValue].getStatus() == EMPTY) //Using the hash function if a entry maps to an empty hash entry spot in the array
	{
		entry_[hashValue] = newEntry; //Set the entry to the array spot
	}
	else
	{
		for(int i = 0; i < size_; i++) //Checks all spots in array
		{
			int newHashValue(0);
			
			if(type_ == LINEAR) //Use Linear hash fuction to map to array spot
			{
				newHashValue = (hashValue + i) % size_;
			}
			else //Use Quadratic hash function to map to array spot
			{
				newHashValue = (hashValue + (i * i)) % size_;
			}
			
			if(entry_[newHashValue].getStatus() == EMPTY) //If a entry maps to an empty hash entry spot in the array using the new hash value
			{
				entry_[newHashValue] = newEntry; //Set the entry to the array spot
				break; //We want to break out of the loop when we find the successful spot because we do not want to rehash the same thing
			}
		}
	}
}

int HashTableArray::search(int key)
{
	int hashIndex(0);
	int value(-1);
	
	hashIndex = getHashFunction(key); //Accesses helper function
	
	if(entry_[hashIndex].getKey() == key && entry_[hashIndex].getStatus() == OCCUPIED) //Uses key to determine specific entry in the array, and checks if that entry is occupied
	{
		value = entry_[hashIndex].getValue(); //Accesses value from that specific entry
	}
	else
	{
		int originalHash = hashIndex; //stores old hash index to a new variable so the old variable can be used again
		int count = 0; //Keeps track of iterations
		
		do //Checks while specific conditions are not met
		{
			if(type_ == LINEAR) //Use linear hash function
			{
				hashIndex = (hashIndex + 1) % size_;
			}
			else //Use quadratic hash function with count iterations per quadratic formula 
			{
				hashIndex = (getHashFunction(key) + (count * count)) % size_;
				
				if(originalHash == hashIndex) //If hash functions are the same
				{
					count++; //move forward an iteration
					hashIndex = (hashIndex + (count * count)) % size_;
				}
			}
			
			if(entry_[hashIndex].getKey() == key && entry_[hashIndex].getStatus() == OCCUPIED) //Uses key to map to specific entry in the array and checks if entry is occupied
			{
				value = entry_[hashIndex].getValue(); //We retrieve value from the specific entry
				break; //We want to break out of the loop when we find the successful spot because we do not want to rehash the same thing
			}
			
			count++; //more forward an iteration
			
		}
		while(entry_[hashIndex].getKey() != key && originalHash != hashIndex && count < size_); //execute while key does not map to a specific entry and original hash function does not equal the new one, and while count is less than size
	}
		
	return value; //returns the found value
}

void HashTableArray::remove(int key) //Removes a hash entry 
{	
	int hashIndex(0);
	int value(-1);
	
	hashIndex = getHashFunction(key); //Accesses helper function to determine hash function
	
	if(entry_[hashIndex].getKey() == key && entry_[hashIndex].getStatus() == OCCUPIED) //If key maps to a specific hash entry and that entry is occupied
	{
		value = entry_[hashIndex].getValue(); //value is equal to value of the specific hash entry. IF DOES NOT WORK PUT BACK TO getKey!!!!!!!!!!
		HashEntry newEntry; //Creates a newEntry to overwrite old
		newEntry.setStatus(REMOVED); //Sets status of new entry to removed 
		entry_[hashIndex] = newEntry; //Overwrites old entry, removing it
	}
	else //Almost exact same as search else statement, refer to those comments for the majority of this
	{
		int originalHash = hashIndex;
		int count = 0;
		
		do
		{
			if(type_ == LINEAR)
			{
				hashIndex = (hashIndex + 1) % size_;
			}
			else
			{
				hashIndex = (getHashFunction(key) + (count * count)) % size_;
				
				if(originalHash == hashIndex)
				{
					count++;
					hashIndex = (hashIndex + (count * count)) % size_;
				}
			}
			
			if(entry_[hashIndex].getKey() == key && entry_[hashIndex].getStatus() == OCCUPIED)
			{
				value = entry_[hashIndex].getValue(); //value is equal to value of the specific hash entry. IF DOES NOT WORK PUT BACK TO getKey
				HashEntry newEntry; //Creates new entry to overwrite old
				newEntry.setStatus(REMOVED); //Sets status to removed
				entry_[hashIndex] = newEntry; //Overwrites old entry, removing it
			}
			
			count++; //Move forward an iteration
			
		}
		while(entry_[hashIndex].getKey() != key && originalHash != hashIndex && count < size_);
	}
	
	if(value == -1) //Protects from invalid input
	{
		std::cout << std::endl << "Invalid key!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << std::endl <<"Key " << key << " removed." << std::endl;
		std::cout << std::endl;
	}
}

void HashTableArray::print() //Prints out Hash Table
{
	std::cout << "***********************************" << std::endl;
	for(int i = 0; i < size_; i++) //Checks all positions of hash table array
	{
		if(entry_[i].getStatus() == OCCUPIED) //If occupied, print position and key 
		{
			std::cout << "[" << i << "]: " << entry_[i].getKey() << std::endl;
		}
		else //Print just position
		{
			std::cout << "[" << i << "]: " << std::endl;
		}
	}
	std::cout << "***********************************" << std::endl;
	
	std::cout << std::endl;
}

HashEntry * HashTableArray::getEntry() //Accesses entry
{
	return entry_;
}

void HashTableArray::setEntry(HashEntry * hashEntry) //Sets entry
{
	entry_ = hashEntry;
}

int HashTableArray::getHashFunction(int key) //Accesses hash function
{
	return(key % size_);
}