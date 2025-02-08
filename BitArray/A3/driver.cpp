// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "bitarray.h"
#include "set.h"
#include "dictionary.h"
#include <cstring>
#include <iostream>
#include <fstream>

int main()
{	
	//PhaseI
	
	/*
	BitArray bitArray; //Creates a new BitArray
	
	char CHAR[] = "test"; //Creates new char

	bitArray.initialize(CHAR,strlen(CHAR)); //Initializes bitArray with the word bits and its size
	
	bitArray.get(8); //Gets data of bitArray
	
	std::cout << "Number of Bits: " << bitArray.length() << std::endl; //Returns length of bitArray
	
	bitArray.print(); //Prints bitArray
	*/
	
	
	//Phase II
	
	/*
	BitArray newBitArray; //Creates a new BitArray
	
	char CHAR[] = "test"; //Creates new char

	newBitArray.initialize(CHAR,strlen(CHAR)); //Initializes newBitArray with the word bits and its size
		
	newBitArray.print(); //Prints newBitArray
	std::cout << std::endl;
	std::cout << "0th Bit Set: " << newBitArray.get(0)<< std::endl; //Returns value of newBitArray at index 0
	
	std::cout << "10th Bit Set: "<< newBitArray.get(10)<< std::endl; //Returns value of newBitArray at index 10
	
	std::cout << std::endl;
	std::cout << "Setting 0th Position to 1... "<< std::endl;
	newBitArray.set(0,1); //Sets position 0 to value 1
	newBitArray.print(); //Prints newBitArray
	std::cout << std::endl;
	std::cout << "Setting 10th Position to 0... "<< std::endl;
	newBitArray.set(10,0); //Sets position 10 to value 0
	newBitArray.print(); //Prints newBitArray
	std::cout << std::endl;
	std::cout << "Complement: " << std::endl;
	newBitArray.complement(); //Flips all values of the newBitArray
	newBitArray.print(); //Prints newBitArray
	std::cout << std::endl;
	std::cout << "Clear BitArray: " << std::endl;
	newBitArray.clear(); //Clears newBitArray to all 0's
	newBitArray.print(); //Prints newBitArray
	*/
	
	
	//Phase III
	
	/*
	char CHAR[] = "char"; //Creates a new Char array
	char CHAR2[] = "bits"; //Creates a new Char array
	
	BitArray BitArray1; //Creates a new BitArray
	BitArray BitArray2; //Creates a new BitArray
	
	BitArray1.initialize(CHAR,strlen(CHAR)); //Initializes BitArray1 with the word char and its size
	BitArray2.initialize(CHAR2,strlen(CHAR2)); //Initializes BitArray2 with the word bits and its size

	Set Set1; //Creates a new Set
	Set Set2; //Creates a new Set
	
	Set1.initialize(CHAR,strlen(CHAR)); //Initializes Set1 with the word char and its size
	Set2.initialize(CHAR2,strlen(CHAR2)); //Initializes Set2 with the word bits and its size
		
	BitArray1.print(); //Prints BitArray1
	BitArray2.print(); //Prints BitArray2
	std::cout << std::endl;
	
	std::cout << "Cardinality: " << Set1.getCardinality() << std::endl; //Retrieves Cardinality of Set1
	std::cout << std::endl;
	
	std::cout << "Set Union (A U B): " <<std::endl;
	Set1.setUnion(Set2); //Retrieves union of Set1 and Set2
	Set1.getData().print(); //Prints results of union
	
	Set1.initialize(CHAR,strlen(CHAR)); //Reinitializes Set1
	Set2.initialize(CHAR2,strlen(CHAR2)); //Reinitializes Set2
	
	std::cout << std::endl;
	
	std::cout << "Set Intersection (A X B): " <<std::endl;
	Set1.setIntersection(Set2); //Retrieves intersection of Set1 and Set2
	Set1.getData().print(); //Prints results of intersection
	*/
	
	//Phase IV
	
	/*
	char CHAR[] = "test"; //Creates new char array
		
	BitArray BitArray1; //Creates new BitArray
	
	BitArray1.initialize(CHAR,strlen(CHAR)); //Initializes BitArray1 with the word bits and its size
	
	BitArray1.print(); //Prints BitArray1

	Dictionary dictionary1; //Creates new Dictionary
	
	dictionary1.initialize(CHAR,strlen(CHAR)); //Initializes dictionary1 with word bits and its size
	
	std::cout << "Rank: " << dictionary1.rank(strlen(CHAR) * BIT_IN_BYTE) << std::endl; //Retrieves rank of dictionary1
	std::cout << "Rank Range (15,31,1): " << dictionary1.rank_range(15,31,1) << std::endl; //Retrieves rank range of dictionary1
	std::cout << "Select(5,1): " << dictionary1.select(5,1) << std::endl; //Retrieves select of dictionary1
	std::cout << "Select Range(0,15,2,1): " << dictionary1.select_range(0,15,2,1) << std::endl; //Retrieves select range of dictionary1
	*/
	
	//Phase V
	
	
	char CHAR[] = "test"; //Creates new char array
		
	BitArray BitArray2; //Creates new BitArray
	
	BitArray2.initialize(CHAR,strlen(CHAR)); //Initializes BitArray2 with the word bits and its size
	
	BitArray2.print(); //Prints BitArray2
	std::cout << std::endl;

	Dictionary dictionary2; //Creates new Dictionary
	
	dictionary2.initialize(CHAR,strlen(CHAR)); //Initializes dictionary2 with word char and its size
	
	std::cout << "Rank: " << dictionary2.rank(strlen(CHAR) * BIT_IN_BYTE) << std::endl; //Retrieves rank of dictionary2 using lookupTable
	std::cout << "Select(4,1): " << dictionary2.select(4,1) << std::endl; //Retrieves select of dictionary2 using lookupTable
	std::cout << std::endl;
	
	std::ofstream outputFileStream("bitArrayOutput.txt"); //Initializes outputFileStream to output to provided text file
		
	dictionary2.printLookupTable(outputFileStream); //Calls printLookupTable to print to text file
	
	outputFileStream.close(); //Closes outputFileStream
	
	
	return 0;
}
