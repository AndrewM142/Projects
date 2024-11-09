// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H
#include "deck.h"
#define DECK_SIZE 52

/**
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class StandardDeck : public Deck
{
	public:
		/// Default constructor.
		StandardDeck();
		
		/// Parameterized constructor
		StandardDeck(int size);
		
		/// Default destructor.
		~StandardDeck();

		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */ 
		//bool isEmpty();	

		/**
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */ 
		//int getNumCards();

		/**
	     * Displays the i'th card in the Deck.
	     *
		 * @param[in]      Index
	    */
		//void displayCard(int i);

		/**
	     * Prints the contents of the Deck. This method should call the 
		 * print() method on each Card.
	    */
		//void printDeck(); //prints deck of cards
		
		virtual void initializeDeck(); //fills a standard deck with cards
		
		//bool addCard(Card c); //adds card to deck
		
		//void shuffle(); //randomly shuffles deck
		
		bool mergeDecks(StandardDeck &, bool); //merges two given decks // maybe virtual 
		
		//Card dealCard(); //Deals card from given deck and removes from deck
		
		//Card getTopCard(); //returns top card from deck
		
	
};

#endif
