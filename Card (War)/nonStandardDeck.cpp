// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "nonStandardDeck.h"
#include <fstream>

NonStandardDeck::NonStandardDeck() //Default Constructor
{
	
	
}
NonStandardDeck::NonStandardDeck(int size) : Deck(size) //Parameterized Constructor
{
	
	
}
NonStandardDeck::~NonStandardDeck() //Destructor
{
	
}
void NonStandardDeck::initializeDeck() //Initializes Deck using input file
{	
	//Temporary Variables
	int suit = 0;
	int face = 0;
	int size = 0;
	
	std::string ifile = "deck.txt"; //name of input file
		
	std::ifstream input; //initializes my input file stream
		
	input.open(ifile); //input file will be opened
	
	if (input.is_open()) //while input file is open
	{
		input >> size; //takes in size from file
		
		deck_ = new Card[size]; //Creates a card deck of given size
		
		numCards_ = size; 
				
		for(int k = 0; k < size; k++) //For size of deck
		{				
			input >> suit >> face; //takes in suit and face from file
			
			Card newCard(suit, face); //Creates new Card with given suit and face
			
			deck_[k] = newCard; //adds card to deck 
			
		}	
		
		input.close(); //closes input file
	}
	else //File not read
	{
		std::cout << "File does not exist!" << std::endl;
		std::cout << std::endl;
	}	
	
}

bool NonStandardDeck::mergeDecks(NonStandardDeck & deck, bool toShuffle = false)
{
	if(numCards_ < size_) //If room in deck to merge
	{
		int mergeNum = 0;
		mergeNum = size_ - numCards_; //Checks room in deck
		
		if(mergeNum > deck.getNumCards()) //if mergeNum greater than amount of cards in deck
		{
			mergeNum = deck.getNumCards(); //set mergeNum to amount of cards in deck
		}
		for(int i=0; i < mergeNum; i++)
		{
			deck_[i + numCards_] = deck.deck_[i]; //Merging Cards with deck you pass in
		}
		
		numCards_ += mergeNum; //Updating numCards for addition of merged Cards
		
		deck.numCards_ = 0; //Resets for next usage
		
		if(toShuffle) //Cards shuffled if necessary
		{
			shuffle();
		}
		return true; //Merge needed and completed
	}
	else
	{
		return false; //Merge unneccesary and not done
	}
}
	
