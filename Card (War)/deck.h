// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#ifndef DECK_H
#define DECK_H

#include <bits/stdc++.h>
#include "card.h"

class Deck
{
	public:
		//Class management
		Deck(); //Default Constructor
		Deck(int size); //Parameterized Constructor
		~Deck(); //Destructor
		
		//Phase II & Phase V
		virtual void initializeDeck() = 0; //Pure virtual initialization of Deck
		
		//Phase II
		bool isEmpty(); //Checks if given deck is empty
		int getNumCards(); //gets NumCards of given deck
		void displayCard(int i); // displays a given card in a deck
		void printDeck(); // prints a deck
		
		// Phase III & Phase V
		bool addCard(Card c); //Adds new Card to Deck
		void shuffle(); //Randomly Shuffles Deck
		
		//Phase IV
		Card dealCard(); //Deals Card from a given deck and removes it from deck
		Card getTopCard(); //Gets the top card of a given deck
		
	protected:
		Card * deck_; // Pointer to record the location of the array of Cards in memory.
		int numCards_; // Stores the number of Cards currently in the deck.
		int size_; //Stores max size of deck
};

#endif
