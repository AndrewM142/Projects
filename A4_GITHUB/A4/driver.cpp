// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Node.h"
#include "LinkedNode.h"
#include "LinkedList.h"
#include "DoubleLinkedList.h"

//Phase 5 Helper Methods

void PrintFile(DoubleLinkedList * DLL, std::string file)
{
	std::ofstream Output;
	Output.open(file); //Opens output file
	if(DLL->getLength() != 0) //If list has nodes
	{
		LinkedNode * printerNode = DLL->getHead(); //gets head of DLL
		Output << printerNode->getValue(); //Prints first nodes value at head of DLL
		
		while(printerNode->hasNextLinkedNode()) //While there is a next linked node, print their value to file
		{
			printerNode = printerNode->getNextLinkedNode();
			Output << "<-->" << printerNode->getValue();
		}
		Output << std::endl;
	}
	else
	{
		Output << "Empty" << std::endl;
	}
	Output.close(); //Close output file
	Output.clear(); //Clear output file
}
	
//Checks amount of hops when doing a tail insert
int checkTailInsert(DoubleLinkedList * DLL, LinkedNode *& head, LinkedNode*& tail, int data, int TailHops)
{
	if(data > tail->getValue() || data == tail->getValue()) //If data is greater than tail value or equal to tail value
	{
		return TailHops; //return Tailhops
	}
	else
	{
		if(tail->getPrevLinkedNode() == nullptr) //if tail's previous linked node is a nullptr
		{
			return TailHops; //return Tailhops
		}
		
		tail = tail->getPrevLinkedNode(); // sets tail equal to its previous linked node
		TailHops++; //Increases Tailhops
		TailHops = checkTailInsert(DLL, head, tail, data, TailHops); //Recursively calls function until a return case occurs
	}
	
	return TailHops; //Default check to be safe
}

//Checks amount of hops when doing a head insert
int checkHeadInsert(DoubleLinkedList * DLL, LinkedNode *& head, LinkedNode*& tail, int data, int HeadHops)
{
	if(data < head->getValue() || data == head->getValue()) //If data is less than head value or equal to head value
	{
		return HeadHops; //return HeadHops
	}
	else
	{
		if(head->getNextLinkedNode() == nullptr) //If head's next linked node is a nullptr
		{
			return HeadHops; //return HeadHops
		}
		
		head = head->getNextLinkedNode(); //sets head equal to its next linked node
		HeadHops++; //Increases HeadHops
		HeadHops = checkHeadInsert(DLL, head, tail, data, HeadHops); //Recursively calls function until a return case occurs
	}
	
	return HeadHops; //Default check to be safe
}

int main()
{

	//PHASE1 & TESTING
	
	/*
	LinkedNode * node1 = new LinkedNode(15, nullptr, nullptr); //Creates new node with value 15
	LinkedNode * node2 = new LinkedNode(7, nullptr, nullptr); //Creates new node with value 15
	LinkedNode * node3 = new LinkedNode(10, nullptr, nullptr); //Creates new node with value 10
		
	node1->setNextLinkedNode(node2); //Links node 1 with 2
	node2->setNextLinkedNode(node3); //Links node 2 with 3

	LinkedNode * test = node1; //Creates test node to check links
	
	while (test->hasNextLinkedNode()) //Prints out linked nodes
	{
		std::cout << test->getValue() << "->";
		test = test->getNextLinkedNode();
	}	
	
	std::cout << test->getValue() << std::endl; //test
	
	delete node1; //deletes head of the list to delete all nodes along with test
	*/
	
	
	//PhaseII
	
	/*
	LinkedList * newLinkedList = new LinkedList(); //Creates a LinkedList
	newLinkedList->insert(15); //Inserts value 15 to LinkedList
	std::cout<<"Inserting 15..."<<std::endl;
	newLinkedList->insert(7); //Inserts value 7 to LinkedList
	std::cout<<"Inserting 7..."<<std::endl;
	newLinkedList->insert(10); //Inserts value 10 to LinkedList
	std::cout<<"Inserting 10..."<<std::endl;
	newLinkedList->printList(); //Prints LinkedList
	std::cout<<"Length: ";
	std::cout <<newLinkedList->getLength() << std::endl; //Retrieves length of LinkedList
	
	delete newLinkedList; //Deletes newLinkedList
	*/
	
	
	//PHASE III (TESTING)
	
	/*
	//Creates 3 LinkedNodes with values
	LinkedNode * node1 = new LinkedNode(15, nullptr, nullptr); //Creates new node with value 15
	LinkedNode * node2 = new LinkedNode(7, nullptr, nullptr); //Creates new node with value 7
	LinkedNode * node3 = new LinkedNode(10, nullptr, nullptr); //Creates new node with value 10
		
	node1->setNextLinkedNode(node2); //Links node1 to next linked node (node2)
	node2->setNextLinkedNode(node3); //Links node2 to next linked node (node3)
	
	node2->setPrevLinkedNode(node1); //Links node 2 to previous linked node (node1)
	node3->setPrevLinkedNode(node2); //Links node 3 to previous linked node (node2)

	LinkedNode * test = node1; //Creates test node to check links
	
	while (test->hasNextLinkedNode()) //Prints out linked nodes (test)
	{
		std::cout << test->getValue() << "->";
		test = test->getNextLinkedNode();
	}	
	
	std::cout << test->getValue() << std::endl; //test
	
	std::cout << "Node 2: ";
	std::cout << node2->getValue()<<std::endl;
	std::cout << "Previous Node: ";
	std::cout << node2->getPrevLinkedNode()->getValue()<<std::endl; //Checks getPrevLinkedNode
	
	delete node1; //deletes head of the list to delete all nodes along with test
	*/
	
	//Phase IV
	
	/*
	DoubleLinkedList * newDoubleLinkedList = new DoubleLinkedList(); //Creates new DLL
	std::cout<<"Inserting 15..."<<std::endl;
	newDoubleLinkedList->insertLinkedNode(newDoubleLinkedList->getTail(), 15); //Inserts linked node at DLL tail 
	std::cout<<"Inserting 7..."<<std::endl;
	newDoubleLinkedList->insertLinkedNode(newDoubleLinkedList->getTail(), 7); //Inserts linked node at DLL tail
	std::cout<<"Inserting 10..."<<std::endl;
	newDoubleLinkedList->insertLinkedNode(newDoubleLinkedList->getTail(), 10); //Inserts linked node at DLL tail
	
	//newDoubleLinkedList->insertAfterLinkedNode(newDoubleLinkedList->getHead(), 20); //test
	//newDoubleLinkedList->insertBeforeLinkedNode(newDoubleLinkedList->getHead(), 40); //test
	//newDoubleLinkedList->insertBeforeLinkedNode(newDoubleLinkedList->getTail()->getPrevLinkedNode(), 60); //test
	
	newDoubleLinkedList->printList(); //prints DLL
	std::cout<<"Length: ";
	std::cout <<newDoubleLinkedList->getLength() << std::endl; //Retrieves length of DLL
	
	delete newDoubleLinkedList; //deletes DLL
	*/
	
	//Phase V
	
	DoubleLinkedList * dataDLL = new DoubleLinkedList(); //Creates new DLL
	DoubleLinkedList * sortedDLL = new DoubleLinkedList(); //Creates new DLL
		
	int dataInputVal(0); //integers to be input from data.txt
	int sortedInputVal(0); //integers to be input from sorted.txt
	int inputsVal(0); //integers to be input from inputs.txt 
	int TailHops(0); //Amount of hops from Tail
	int HeadHops(0); //Amount of hops from Head
	int TotalSorted(0); //Total Amount of hops
	int TotalData(0); //Total Amount of hops
		
	std::ifstream input; //initializes my input file stream
		
	input.open("data.txt"); //opens file
		
	if (input.is_open()) //while input file is open
	{
		while (!input.eof()) //while the file has not reached end
		{	
			input >> dataInputVal; //inputs integers from text file
			dataDLL->insertLinkedNode(dataDLL->getTail(), dataInputVal); //Fills dataDLL with new nodes from file
		}
		input.close(); //closes input file
		input.clear(); //clears input file
	}
	else //File not read
	{
		std::cout << "File does not exist!" << std::endl;
		std::cout << std::endl;
	}
		
	LinkedNode * dHead = dataDLL->LinkedList::getHead(); //pointer to head of dataDLL derived from LinkedList
	LinkedNode * dTail = dataDLL->LinkedList::getTail(); //pointer to tail of dataDLL derived from LinkedList
	
	dataDLL->printList(); //test
	std::cout << std::endl;
	
	input.open("sorted.txt"); //opens text file
		
	if (input.is_open()) //while input file is open
	{
		while (!input.eof()) //while the file has not reached end
		{	
			input >> sortedInputVal; //inputs integers from text file
						
			sortedDLL->insertLinkedNode(sortedDLL->getTail(), sortedInputVal); //Fills sortedDLL with new nodes
		}
		input.close(); //closes input file
		input.clear();
	}
	else //File not read
	{
		std::cout << "File does not exist!" << std::endl;
		std::cout << std::endl;
	}
		
	LinkedNode * sHead = sortedDLL->LinkedList::getHead(); //pointer to head of sortedDLL derived from LinkedList
	LinkedNode * sTail = sortedDLL->LinkedList::getTail(); //pointer to tail of sortedDLL derived from LinkedList 
	
	sortedDLL->printList(); //test
	
	input.open("inserts.txt"); //opens text file
		
	if (input.is_open()) //while input file is open
	{
		while (!input.eof()) //while the file has not reached end
		{	
			input >> inputsVal; //inputs integers from text file //IF PROBLEM WITH INPUTSVAL CHANGE TO SORTEDINPUTVAL
			TailHops = 0;
			HeadHops = 0;
			
			TailHops = checkTailInsert(sortedDLL, sHead, sTail, inputsVal, TailHops); //Calls helper function
			HeadHops = checkHeadInsert(sortedDLL, sHead, sTail, inputsVal, HeadHops); //Calls helper function
			
			if(TailHops < HeadHops) //If TailHops is more optimized
			{
				if(inputsVal == sHead->getValue()) //Duplicate value case
				{
					sortedDLL->insertAfterLinkedNode(sHead, inputsVal); //inserts after head of SortedDLL
					TotalSorted = TotalSorted + TailHops + 1; //Count total sorted hops, account for duplicate movement
				}
				
				sortedDLL->insertAfterLinkedNode(sTail, inputsVal); //inserts after tail of sortedDLL
				TotalSorted = TotalSorted + TailHops; //Count total sorted hops
			}
			else if(HeadHops < TailHops) //If HeadHops is more optimized
			{
				if(inputsVal == sHead->getValue()) //Duplicate value case
				{
					sortedDLL->insertAfterLinkedNode(sHead, inputsVal); //Inserts after head of sortedDLL
					TotalSorted = TotalSorted + HeadHops + 1; //Count total sorted hops, account for duplicate movement
				}
				else
				{
					sortedDLL->insertBeforeLinkedNode(sHead, inputsVal); //Inserts before head of sortedDLL
					TotalSorted = TotalSorted + HeadHops; //Count total sorted hops
				}
			}
			else
			{
				sortedDLL->insertAfterLinkedNode(sTail, inputsVal); //inserts after tail of sortedDLL
				TotalSorted = TotalSorted + TailHops; //Count total sorted hops
			}
			
			sTail = sortedDLL->getTail(); //Reset
			sHead = sortedDLL->getHead(); //Reset
			
		}
		input.close(); //closes input file
		input.clear();
	}
	else //File not read
	{
		std::cout << "File does not exist!" << std::endl;
		std::cout << std::endl;
	}
	
	
	input.open("inserts.txt"); //opens text file
		
	if (input.is_open()) //while input file is open
	{
		while (!input.eof()) //while the file has not reached end
		{	
			input >> inputsVal; //inputs integers from text file //IF PROBLEM WITH INPUTSVAL CHANGE TO SORTEDINPUTVAL
			TailHops = 0;
			HeadHops = 0;
			
			TailHops = checkTailInsert(dataDLL, dHead, dTail, inputsVal, TailHops); //Calls helper function
			HeadHops = checkHeadInsert(dataDLL, dHead, dTail, inputsVal, HeadHops); //Calls helper function
			
			if(TailHops < HeadHops) //If Tailhops more optimized
			{
				if(inputsVal == dHead->getValue()) //Duplicate value case
				{
					dataDLL->insertAfterLinkedNode(dHead, inputsVal); //inserts after head of dataDLL
					TotalData = TotalData + TailHops + 1; //Count total data hops, account for duplicate movement
				}
				
				dataDLL->insertAfterLinkedNode(dTail, inputsVal); //inserts after tail of dataDLL
				TotalData = TotalData + TailHops; //Count total data hops
			}
			else if(HeadHops < TailHops) //If HeadHops more optimized
			{
				if(inputsVal == dHead->getValue()) //Duplicate value case
				{
					dataDLL->insertAfterLinkedNode(dHead, inputsVal); //inserts after head of dataDLL
					TotalData = TotalData + HeadHops + 1; //Count total data hops, account for duplicate movement
				}
				else
				{
					dataDLL->insertBeforeLinkedNode(dHead, inputsVal); //inserts before head of dataDLL
					TotalData = TotalData + HeadHops; //Count total data hops
				}
			}
			else
			{
				dataDLL->insertAfterLinkedNode(dTail, inputsVal); //Inserts after tail of dataDLL
				TotalData = TotalData + TailHops; //Count total data hops
			}
			
			dTail = dataDLL->getTail(); //Reset
			dHead = dataDLL->getHead(); //Reset
			
		}
		input.close(); //closes input file
		input.clear(); //clears input file
	}
	else //File not read
	{
		std::cout << "File does not exist!" << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	dataDLL->printList(); //prints list (test)
	std::cout << std::endl;
	sortedDLL->printList(); //prints list (test)
	
	PrintFile(dataDLL, "output.txt"); //helper function for output file
	PrintFile(sortedDLL, "sortedOutput.txt"); //helper function for output file
	
	std::ofstream Output;
	
	Output.open("README.txt"); //Opens output file
	Output << "Data - Total Number of Big Dawg Hops: " << TotalData << std::endl; //Outputs Hops for Data
	Output << "Sorted - Total Number of Big Dawg Hops: " << TotalSorted << std::endl; //Outputs Hops for Sorted
	
	std::cout <<"output.txt created" << std::endl;
	std::cout <<"sortedOutput.txt created" << std::endl;
	std::cout <<"README.txt created" << std::endl;
	
	Output.close(); //closes output file
	Output.clear(); //clears output file
	
	delete dataDLL; //deletes DLL
	delete sortedDLL; //deletes DLL
		
	return 0;
}
