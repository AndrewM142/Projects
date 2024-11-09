// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton
#ifndef NON_STANDARD_H
#define NON_STANDARD_H
#include "deck.h"

class NonStandardDeck : public Deck
{
	public:
		NonStandardDeck(); //Constructor
		NonStandardDeck(int size); //Parameterized Constructor
		~NonStandardDeck(); //Destructor
		
		virtual void initializeDeck(); //initializes NonStandard Deck
		bool mergeDecks(NonStandardDeck &, bool); //maybe virtual?	
	
};

#endif
