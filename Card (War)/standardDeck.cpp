// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "standardDeck.h"
#include <iostream>
#include <string>
#define DECK_SIZE 52

StandardDeck::StandardDeck() : Deck(DECK_SIZE) //Default Constructor
{
	
	
}

StandardDeck::StandardDeck(int size) : Deck(size) //Parameterized Constructor
{
	

}

StandardDeck::~StandardDeck() //Destructor
{
	
	
}

void StandardDeck::initializeDeck() //Fills a Standard Deck with cards
{
	for (int i=1; i < 5; i++)
	{
		for (int j=1; j < 14; j++)
		{
			Card newCard(i, j);
			addCard(newCard);	
		}
	}
}

bool StandardDeck::mergeDecks(StandardDeck & deck, bool toShuffle) // mergeDeck function implementation passing through deck of Standard deck and toShuffle bool
{
	if(numCards_ < DECK_SIZE) //If room in deck to merge
	{
		int mergeNum = 0;
		
		mergeNum =  DECK_SIZE - numCards_; //Checks room in deck
		
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
