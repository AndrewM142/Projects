// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include <fstream>
#include "HashTable.h"
#include "HashTableArray.h"
#include "HashTableChaining.h"
#include "HashTableCuckoo.h"

//Option Set #1 Function
void HashType() //Prints Chaining Types
{
	std::cout<< "1) Linear Probing" << std::endl;
	std::cout<< "2) Quadratic Probing" << std::endl;
	std::cout<< "3) Seperate Chaining" << std::endl;
	std::cout<< "4) Cuckoo Hashing" << std::endl;
	std::cout<< "5) Quit Program" << std::endl;
	
	std::cout << std::endl;
	std::cout << "Please enter your choice: ";
}

//Option Set #2 Function

void EntryOptions() //Prints options
{
	std::cout<< "1) Search For Entry" << std::endl;
	std::cout<< "2) Remove Entry" << std::endl;
	std::cout<< "3) Print Hash Table" << std::endl;
	std::cout<< "4) Return to Main Menu" << std::endl;
	
	std::cout << std::endl;
	std::cout << "Please enter your choice: ";
}

int main()
{
	int HashNum(0); //Denotes what type of hash you want
	int HashSize(0); //Size of hash table
	int EntryNum(0); //Denotes what options to use on hash table
	int dataValue(0); //Creates integer to store input values
	int keyValue(0); // inserted key
	int searchKey(0); // key of the searched entry
	int removeKey(0); // key of the removed entry
	int searchVal(0); // value of the searched entry
	int numAmt(0); //Amount of entries in hashtable
	
	std::cout << "Welcome to Blue IV's Can of Who Hash!" << std::endl;
	std::cout << std::endl;
	
	while(HashNum != 5) //While user has not asked to quit program
	{
		int HashNum = 0;
		int HashSize = 0;
		int EntryNum = 0;
		
		while(HashNum != 1 && HashNum != 2 && HashNum != 3 && HashNum != 4 && HashNum != 5) //If invalid number is pressed ask for hash type again
		{
			// Set #1
			HashType(); //prints hash types
			std::cin >> HashNum; //user inputs hash type that they want
			std::cout << std::endl;
			
			if(HashNum == 5) //Quits program
			{
				std::cout << "Thank you for using Blue IV's program - Goodbye!" << std::endl;
				return 0;
			}
		}
		
		HashSize = 0;
		
		while(HashSize == 0) //0 is not valid, you cannot divide by 0 in some key cases
		{
			std::cout<< "Please enter the size of the Hash Table you wish to create: ";
			std::cin >> HashSize; //User inputs size of hash table
			std::cout << std::endl;
			
			if(HashSize == 0) // Again, 0 is not valid for a hash table size
			{
				std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
				std::cout << std::endl;
			}
		}
			
		
		if(HashNum == 1) //User desires linear hash type
		{			
			HashTableArray * Hash123 = new HashTableArray(HashSize, LINEAR); //Creates a new linear hash table array
	
			std::ifstream input; //initializes my input file stream
				
			input.open("data.txt"); //opens file
				
			if (input.is_open()) //while input file is open
			{
				while (!input.eof()) //while the file has not reached end
				{	
					input >> keyValue >> dataValue; //inputs key and respective data from file
					Hash123->insert(keyValue, dataValue); //inserts key and respective data into hash table
				}
			}
			else //File not read
			{
				std::cout << "File does not exist!" << std::endl;
				std::cout << std::endl;
			}
			input.close(); //closes input file
			input.clear(); //clears input file
			
			Hash123->print(); //Prints once after table is created per Assignment #6 sample output
			
			while(EntryNum != 1 && EntryNum != 2 && EntryNum != 3 && EntryNum != 4) //While invalid entry option is chosen
			{
				while(EntryNum != 4) //While user has not requested to return to main menu
				{
					// Set #1
					EntryOptions(); //prints options for hash table procedures
					std::cin >> EntryNum; // requests entry option
					std::cout << std::endl;
				
					if(EntryNum == 1) //User requests to search for a key
					{
						searchKey = 0;
						searchVal = 0;
						std::cout << "Search (Please Enter A Key): ";
						std::cin >> searchKey; //request for user to input key
						searchVal = Hash123->search(searchKey); //searchVal becomes the value returned from a search operation for a given key
						
						if(searchVal == -1) //Protects from invalid input
						{
							std::cout << std::endl;
							std::cout << "Invalid Key! Key " << searchKey << " not found in table!" << std::endl;
							std::cout << std::endl;
						}
						else
						{
							std::cout << std::endl;
							std::cout << "Key: " << searchKey << " Value: " << searchVal << std::endl; //prints key and value
							std::cout << std::endl;
						}
					}
					else if(EntryNum == 2) //User requests to remove a key
					{
						removeKey = 0;
						std::cout << "Remove (Please Enter A Key): ";
						std::cin >> removeKey; //requests a key to be removed
						Hash123->remove(removeKey);	//provided key is removed
					}
					else if(EntryNum == 3) //User requests to print hash table
					{
						Hash123->print();
					}
				}
			}
			delete Hash123; //deletes the hashtable
		}
		else if(HashNum == 2) //user requests a quadratic hash table
		{			
			HashTableArray * Hash123 = new HashTableArray(HashSize, QUADRATIC); // a new Quadratic hash table array is created
	
			std::ifstream input; //initializes my input file stream
				
			input.open("data.txt"); //opens file
				
			if (input.is_open()) //while input file is open
			{
				while (!input.eof()) //while the file has not reached end
				{	
					input >> keyValue >> dataValue; //inputs key and value from text file
					Hash123->insert(keyValue, dataValue); //inserts a key and its respective value
				}
			}
			else //File not read
			{
				std::cout << "File does not exist!" << std::endl;
				std::cout << std::endl;
			}
			input.close(); //closes input file
			input.clear(); //clears input file
			
			Hash123->print(); //Hash table is printed once after creation per Assignment #6 sample output
			
			while(EntryNum != 1 && EntryNum != 2 && EntryNum != 3 && EntryNum != 4)
			{
				while(EntryNum != 4) //While user has not requested to return to menu
				{
					// Set #1
					EntryOptions(); //prints entry options
					std::cin >> EntryNum; //requests user to enter a hash table operation
					std::cout << std::endl;
				
					if(EntryNum == 1) //If user requests to search for a key
					{
						searchKey = 0;
						searchVal = 0;
						std::cout << "Search (Please Enter A Key): ";
						std::cin >> searchKey; //request for user to input a key to search for
						searchVal = Hash123->search(searchKey); //searchVal becomes the value returned from a search operation for a given key
						
						if(searchVal == -1) //Protects from invalid input
						{
							std::cout << std::endl;
							std::cout << "Invalid Key! Key " << searchKey << " not found in table!" << std::endl;
							std::cout << std::endl;
						}
						else
						{
							std::cout << std::endl;
							std::cout << "Key: " << searchKey << " Value: " << searchVal << std::endl; //Prints key and respective value
							std::cout << std::endl;
						}
					}
					else if(EntryNum == 2) //User requests to remove a key
					{
						removeKey = 0;
						std::cout << "Remove (Please Enter A Key): ";
						std::cin >> removeKey; //input a key to be removed
						Hash123->remove(removeKey); //key is removed from hashtable
					}
					else if(EntryNum == 3) //User requests to print hash table
					{
						Hash123->print();
					}
				}
			}
			delete Hash123; //Hash table is deleted
		}
		else if(HashNum == 3) //User has requested a seperate chaining hash table
		{			
			HashTableChaining * Hash123 = new HashTableChaining(HashSize); //A seperate chaining hash table is created
	
			std::ifstream input; //initializes my input file stream
				
			input.open("data.txt"); //opens file
				
			if (input.is_open()) //while input file is open
			{
				while (!input.eof()) //while the file has not reached end
				{	
					input >> keyValue >> dataValue; //inputs key and its respective data
					Hash123->insert(keyValue, dataValue); //key and respective data are inserted into hash table
				}
			}
			else //File not read
			{
				std::cout << "File does not exist!" << std::endl;
				std::cout << std::endl;
			}
			input.close(); //closes input file
			input.clear(); //clears input file
			
			Hash123->print(); //Hash table is printed once per Assignment #6 sample output
			
			while(EntryNum != 1 && EntryNum != 2 && EntryNum != 3 && EntryNum != 4) //While invalid entry options are input
			{
				while(EntryNum != 4) //While user has not request to return to main menu
				{
					// Set #1
					EntryOptions(); //Entry options are printed
					std::cin >> EntryNum; //User selects an entry option
					std::cout << std::endl;
				
					if(EntryNum == 1) //User requests to search for a key
					{
						searchKey = 0;
						searchVal = 0;
						std::cout << "Search (Please Enter A Key): ";
						std::cin >> searchKey; //User inputs key to search for
						searchVal = Hash123->search(searchKey); //searchVal becomes the value returned from a search operation for a given key
						
						if(searchVal == -1) //Protects from invalid input
						{
							std::cout << std::endl;
							std::cout << "Invalid Key! Key " << searchKey << " not found in table!" << std::endl;
							std::cout << std::endl;
						}
						else
						{
							std::cout << std::endl;
							std::cout << "Key: " << searchKey << " Value: " << searchVal << std::endl; //Key and respective value are printed
							std::cout << std::endl;
						}
					}
					else if(EntryNum == 2) //User requests for a key to be removed
					{
						removeKey = 0;
						std::cout << "Remove (Please Enter A Key): ";
						std::cin >> removeKey; //user inputs key to be removed
						Hash123->remove(removeKey); //Key is removed
					}
					else if(EntryNum == 3) //User requests to print hash table
					{
						Hash123->print();
					}
				}
			}
			delete Hash123; //Hash table is deleted
		}
		else if(HashNum == 4) //User request for a cuckoo hash table
		{					
			HashTableCuckoo * Hash123 = new HashTableCuckoo(HashSize); //Cuckoo hash table is created
	
			std::ifstream input; //initializes my input file stream
				
			input.open("data.txt"); //opens file
				
			if (input.is_open()) //while input file is open
			{
				while (!input.eof()) //while the file has not reached end
				{	
					input >> keyValue >> dataValue; //inputs key and data from input file
					numAmt++;
					
					if(numAmt >= (HashSize)) //There are more inserted numbers than there are spots available in both hash tables
					{
						Hash123->setCycle(false); //set cycle to false because we only want it to say insufficient hash table size
						std::cout << "<<<--- Insufficient Hash Table Size! Re-Hash! --->>>" << std::endl;
						std::cout << std::endl;
						
						break; //We want to get back to menu since it is insufficient hash table size
					}
					
					 // Keeps track of values inserted
					Hash123->insert(keyValue, dataValue); //key and respective data are inserted into the hash table
					
					if(Hash123->hasCycle()) //If a cycle is present in the hash table
					{
						/*
						//TESTING - This is located elsewhere as well
						std::cout << "Cycle Present - Rehash!" << std::endl;
						std::cout << "Key Unpositioned: " << keyValue << std::endl;
						std::cout << std::endl;
						std::cout << "<<<--- Insufficient Hash Table Size! Re-Hash! --->>>" << std::endl;
						std::cout << std::endl;
						*/
						
						break; //If a cycle happens, we want to go back to menu and rehash
					}
				}
			}
			else //File not read
			{
				std::cout << "File does not exist!" << std::endl;
				std::cout << std::endl;
			}
			input.close(); //closes input file
			input.clear(); //clears input file
			
			//Testing
			//Hash123->print();
			
			if(!Hash123->hasCycle() && numAmt < (HashSize)) //If no cycle and entries less than or equal to HashSize
			{
				Hash123->print();
			}
			else //We do not want to print a cuckoo hash table with invalid hash size or a cycle
			{
				delete Hash123; //delete faulty hash table
				numAmt = 0;
				continue; //we want to go to next iteration of the loop and skip rest of the operations for the faulty loop
			}
			
			numAmt = 0; //reset amount of numbers to 0 for next iteration
			
			while(EntryNum != 1 && EntryNum != 2 && EntryNum != 3 && EntryNum != 4)
			{
				while(EntryNum != 4) //While user has not requested to return to the menu
				{
					// Set #1
					EntryOptions(); //Entry options are printed
					std::cin >> EntryNum; //Requests for user to insert an entry number
					std::cout << std::endl;
				
					if(EntryNum == 1) //User requests to search for a key
					{
						searchKey = 0;
						searchVal = 0;
						std::cout << "Search (Please Enter A Key): ";
						std::cin >> searchKey; //User inputs a key to be searched
						searchVal = Hash123->search(searchKey); //searchVal becomes the value returned from a search operation for a given key
						
						if(searchVal == -1) //Protects from invalid input
						{
							std::cout << std::endl;
							std::cout << "Invalid Key! Key " << searchKey << " not found in table!" << std::endl;
							std::cout << std::endl;
						}
						else
						{
							std::cout << std::endl;
							std::cout << "Key: " << searchKey << " Value: " << searchVal << std::endl; //Prints key and its respective value
							std::cout << std::endl;
						}
					}
					else if(EntryNum == 2) //User requests to remove a key
					{
						removeKey = 0;
						std::cout << "Remove (Please Enter A Key): ";
						std::cin >> removeKey; //Requests user to input a key to be removed
						Hash123->remove(removeKey); //Removes key from Hash table	
					}
					else if(EntryNum == 3) //User requests to print
					{
						Hash123->print();
					}
				}
			}
			delete Hash123; //Deletes Hash table
		}
	}
	
	return 0;
}
