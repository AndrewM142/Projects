// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "RedBlackTree.h"
#include <fstream>

int main()
{
	//PHASE I & II
	
	/*
	BinarySearchTree * myTree = new BinarySearchTree(); //Creates new BST
	
	int dataValue(0); //Creates integer to store input values
	
	std::ifstream input; //initializes my input file stream
		
	input.open("data.txt"); //opens file
		
	if (input.is_open()) //while input file is open
	{
		while (!input.eof()) //while the file has not reached end
		{	
			input >> dataValue; //inputs integers from text file
			myTree->insert(dataValue); //inserts data into BST
		}
	}
	else //File not read
	{
		std::cout << "File does not exist!" << std::endl;
		std::cout << std::endl;
	}
	input.close(); //closes input file
	input.clear(); //clears input file
	
	
	myTree->print(myTree->getRoot()); //Prints BST
	
	std::cout << std::endl;
	std::cout<< "Root: " <<myTree->getRoot()->getValue() << std::endl; //Retrieves root of BST
	
	delete myTree; //Deletes BST
	*/
	
	//Phase III
	
	/*
	RedBlackTree * myRedBlackTree = new RedBlackTree(); //Creates RBT
	
	int dataValueP3(0); //creates integer to store input values
	
	std::ifstream input2; //initializes my input file stream
		
	input2.open("data.txt"); //opens file
		
	if (input2.is_open()) //while input file is open
	{
		while (!input2.eof()) //while the file has not reached end
		{	
			input2 >> dataValueP3; //inputs integers from text file
			myRedBlackTree->insert(dataValueP3); //Inserts data into RBT
		}
	}
	else //File not read
	{
		std::cout << "File does not exist!" << std::endl;
		std::cout << std::endl;
	}
	input2.close(); //closes input file
	input2.clear(); //clears input file
	
	
	myRedBlackTree->print(myRedBlackTree->getRoot()); //prints RBT
	
	std::cout << std::endl;
	
	std::cout<< "Root: " <<myRedBlackTree->getRoot()->getValue() << std::endl; //Retrieves root of RBT
	
	std::cout<< "Color: " <<myRedBlackTree->getRoot()->getColor() << std::endl; //Retrives color of root of RBT
		
	delete myRedBlackTree; //Deletes RBT
	*/
	
	//Phase IV
	
	/*
	RedBlackTree * myRedBlackTreeIV = new RedBlackTree(); //Creates RBT
	
	int dataValueP4(0); //creates integer to store input values
	
	std::ifstream input3; //initializes my input file stream
		
	input3.open("data.txt"); //opens file
		
	if (input3.is_open()) //while input file is open
	{
		while (!input3.eof()) //while the file has not reached end
		{	
			input3 >> dataValueP4; //inputs integers from text file
			myRedBlackTreeIV->insert(dataValueP4); //Inserts data into RBT
		}
	}
	else //File not read
	{
		std::cout << "File does not exist!" << std::endl;
		std::cout << std::endl;
	}
	input3.close(); //closes input file
	input3.clear(); //clears input file
	
	
	myRedBlackTreeIV->print(myRedBlackTreeIV->getRoot()); //Prints RBT
	
	std::cout << std::endl;
	
	std::cout<< "Root: " <<myRedBlackTreeIV->getRoot()->getValue() << std::endl; //Retrieves root of RBT
	
	//std::cout<< "Color: " <<myRedBlackTreeIV->getRoot()->getColor() << std::endl; //Retrieves color of root of RBT
	
	delete myRedBlackTreeIV; //Deletes RBT
	*/
	
	//PHASE V
	
	RedBlackTree * myRedBlackTreeV = new RedBlackTree(); //Creates new RBT
	
	int dataValueP5(0); //Creates integer to store input value
	
	std::ifstream input4; //initializes my input file stream
		
	input4.open("data.txt"); //opens file
		
	if (input4.is_open()) //while input file is open
	{
		while (!input4.eof()) //while the file has not reached end
		{	
			input4 >> dataValueP5; //inputs integers from text file
			myRedBlackTreeV->insert(dataValueP5); //Inserts data into RBT
		}
	}
	else //File not read
	{
		std::cout << "File does not exist!" << std::endl;
		std::cout << std::endl;
	}
	input4.close(); //closes input file
	input4.clear(); //clears input file
	
	
	myRedBlackTreeV->print(myRedBlackTreeV->getRoot()); //Prints RBT
	
	std::cout << std::endl;
	
	//std::cout<< "Color: " <<myRedBlackTreeV->getRoot()->getColor() << std::endl; //Retrieves color of root of RBT
	
	std::cout<<"Red Nodes: ";
	myRedBlackTreeV->printRedNodes(myRedBlackTreeV->getRoot()); //Prints out Red Nodes of RBT
	std::cout << std::endl;
	
	std::cout<<"Black Nodes: ";
	myRedBlackTreeV->printBlackNodes(myRedBlackTreeV->getRoot()); //Prints out Black Nodes of RBT
	std::cout << std::endl;
	
	std::cout<< "Root: " <<myRedBlackTreeV->getRoot()->getValue() << std::endl; //Retrieves root of RBT
	
	delete myRedBlackTreeV; //Deletes RBT
	
	return 0;
}

