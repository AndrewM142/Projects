// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "HashTableCuckoo.h"

HashTableCuckoo::HashTableCuckoo(int size) : HashTable(), size_(0), isCycle_(false) //Constructor
{
	if(size > 0) //If at least one entry exists
	{
		entry_ = new HashEntry[size]; //Create new HashTable array of size
		entry2_ = new HashEntry[size]; //Creates new HashTable array of size
		
		for(int i = 0; i < size; i++) //For size of hash tables
		{
			HashEntry newEntry; //Create new entry
			newEntry.setStatus(EMPTY); //Set status to empty
			entry_[i] = newEntry; //Fills hash table 1 with new entries
			entry2_[i] = newEntry; //Fills hash table 2 with new entries
		}
		
		size_ = size;
	}
}

HashTableCuckoo::HashTableCuckoo(const HashTableCuckoo & hashingCuckoo) : size_(hashingCuckoo.size_), entry_(new HashEntry[hashingCuckoo.size_]), entry2_(new HashEntry[hashingCuckoo.size_]), isCycle_(false) //Copy Constructor
{
	for(int i = 0; i < size_; i++) //Copies over entries to each respective hash table
	{
		entry_[i] = hashingCuckoo.entry_[i];
		entry2_[i] = hashingCuckoo.entry2_[i];
	}
}

HashTableCuckoo::~HashTableCuckoo() //Destructor
{
	delete [] entry_;
	delete [] entry2_;
}

void HashTableCuckoo::insert(int key, int value) //Inserts new entries into hash table cuckoo
{
	int hashProbing = 0;
	hashProbing = getHashFunction1(key); //hashProbing becomes the first hash function for the first hash table
	HashEntry newEntry(key, value); //Creates new entry with key and value
	newEntry.setStatus(OCCUPIED); //Set status of new entry to occupied
	
	if(entry_[hashProbing].getStatus() == EMPTY) //If hashprobing key maps to empty spot
	{
		entry_[hashProbing] = newEntry; //Set entry to that 1st hash table array spot
	}
	else //Both hash tables will need to be used
	{
		HashEntry movingEntry; //Denotes an entry that may be moved per cuckoo rules
		bool moved(false); //Denotes if an entry was moved
		bool cycle(false); //Denotes if a cycle is occuring
		int count(0); //Keeps track of iterations
		
		while(moved != true && cycle != true) //While hash entry is not moved and cycle is not occuring
		{
			if(count % 2 == 1) //Denotes odd number, inserted into the second table by default according to cuckoo rules
			{
				movingEntry = entry2_[hashProbing]; //the entry2 in the second table is being moved
				entry2_[hashProbing] = newEntry; //entry is relocated to second table spot
				
				hashProbing = getHashFunction1(movingEntry.getKey()); //hashProbing is equal to hash function 1 implementation using the moving entries key
				
				if(entry_[hashProbing].getStatus() == EMPTY) //If hash table spot is empty
				{
					entry_[hashProbing] = movingEntry; //entry that was pushed out of second table is placed in first table
					moved = true; //entry is moved
				}
				else
				{
					newEntry = movingEntry; //moving entry not able to be moved, continue attempting to move it
					moved = false; //entry is not moved
				}
			}
			else
			{
				movingEntry = entry_[hashProbing]; //the entry in the first table is being moved
				entry_[hashProbing] = newEntry; //entry is relocated to the first table spot
				
				hashProbing = getHashFunction2(movingEntry.getKey()); //HashProbing is equal to hash function 2 implementation using the moving entries key
				
				if(entry2_[hashProbing].getStatus() == EMPTY) //If hash table 2 spot is empty
				{
					entry2_[hashProbing] = movingEntry; //entry that was pushed out of first table is placed in second table
					moved = true; //entry is moved
				}
				else
				{
					newEntry = movingEntry; //moving entry was not able to be moved, continute attempting to move it
					moved = false; // entry is not moved
				}
			}
			count++; //Move forward an iteration
			
			if(count == size_) //Every case for relocation was unsuccessful, so a cycle has begun
			{
				cycle = true; //Set cycle equal to true
				setCycle(cycle); //Transfers cycle value to driver
				
				std::cout << "Cycle Present - Rehash!" << std::endl;
				std::cout << "Key Unpositioned: " << key << std::endl;
				std::cout << std::endl;
				std::cout << "<<<--- Insufficient Hash Table Size! Re-Hash! --->>>" << std::endl;
				std::cout << std::endl;
				
			}
		}
	}
}

int HashTableCuckoo::search(int key) //Searches for hash entry in each of the tables
{
	int hashProbing = getHashFunction1(key); //hashProbing is set equal to the hash function 1 helper function key
	int value = -1;
	
	if(entry_[hashProbing].getKey() == key) //If key maps to a entry in hash table 1
	{
		value = entry_[hashProbing].getValue(); //value is equal to the value of the respective entry
	}
	
	hashProbing = getHashFunction2(key); // Hash probing is set equal to the hash function 2 helper function key
	
	if(entry2_[hashProbing].getKey() == key) //If key maps to a entry in hash table 2
	{
		value = entry2_[hashProbing].getValue(); //value is equal to the value of the respective entry. If not working, SET BACK TO JUST ENTRY
	}
	
	return value; //return value
}

void HashTableCuckoo::remove(int key)
{
	int hashProbing = getHashFunction1(key); //hashProbing is set to hash function 1 helper function key
	int value = -1;
	
	if(entry_[hashProbing].getKey() == key) //If key maps to an entry in hash table 1
	{
		value = entry_[hashProbing].getValue(); //value is equal to the respective entries value
		HashEntry newEntry; //Creates new entry
		newEntry.setStatus(EMPTY); //entry is set to empty
		entry_[hashProbing] = newEntry; //overwrites old entry
	}
	
	hashProbing = getHashFunction2(key); //hashProbing is set to hash function 1 helper function key
	
	if(entry2_[hashProbing].getKey() == key) //If key maps to an entry in hash table 2
	{
		value = entry2_[hashProbing].getValue(); //value is equal to the respective entries value
		HashEntry newEntry; //Creates new entry
		newEntry.setStatus(EMPTY); //entry is set to empty
		entry2_[hashProbing] = newEntry; //overwrites old data
	}
	
	if(value == -1) //Protects from invalid input
	{
		std::cout << std::endl;
		std::cout << "Invalid Key " << key << " not found in table!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Key: " << key << " removed" << std::endl;
		std::cout << std::endl;
	}
}

void HashTableCuckoo::print() //Prints both hash tables
{
	std::cout << "***********************************" << std::endl;
	for(int i = 0; i < size_; i++) //Runs for size of each table
	{
		if(entry_[i].getStatus() == OCCUPIED) //Prints out entry position key
		{
			std::cout << "[" << i << "]: " << entry_[i].getKey() << std::endl;
		}
		else //Prints just position
		{
			std::cout << "[" << i << "]: " << std::endl;
		}
	}
	std::cout << "***********************************" << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "***********************************" << std::endl;
	for(int i = 0; i < size_; i++) //Runs for size of each table
	{
		if(entry2_[i].getStatus() == OCCUPIED) //Prints out entry position key
		{
			std::cout << "[" << i << "]: " << entry2_[i].getKey() << std::endl;
		}
		else //Prints just position
		{
			std::cout << "[" << i << "]: " << std::endl;
		}
	}
	std::cout << "***********************************" << std::endl;
	
	std::cout << std::endl;
}

int HashTableCuckoo::getSize() //Returns size
{
	return size_;
}

void HashTableCuckoo::setSize(int size) //Sets size
{
	size_ = size;
}

HashEntry * HashTableCuckoo::getEntry() //Returns entry
{
	return entry_;
}

HashEntry * HashTableCuckoo::getEntry2() //Returns entry 2
{
	return entry2_;
}
	
void HashTableCuckoo::setEntry(HashEntry * hashEntry) //Sets entry
{
	entry_ = hashEntry;
}

void HashTableCuckoo::setEntry2(HashEntry * hashEntry2) //Sets entry2
{
	entry2_ = hashEntry2;
}

int HashTableCuckoo::getHashFunction1(int key) //Returns hash function 1
{
	return(key % size_);	
}

int HashTableCuckoo::getHashFunction2(int key) //Returns hash function 2
{
	return(key / size_) % size_;
}

void HashTableCuckoo::setCycle(bool isCycle) //Sets cycle
{
	
	isCycle_ = isCycle;
	
}

bool HashTableCuckoo::hasCycle() //Returns cycle
{
		
	return isCycle_;
	
}