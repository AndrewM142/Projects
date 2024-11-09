// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "deck.h"
#define DECK_SIZE 52

Deck::Deck(): size_(DECK_SIZE), numCards_(0) //Default Constructor
{

	
}

Deck::Deck(int size) : deck_(new Card[size]), numCards_(0), size_(size) //Parameterized Constructor
{
	
}

Deck::~Deck() //Destructor
{
	delete [] deck_;
}

bool Deck::isEmpty() //Checks whether Deck is empty or not
{
	if(numCards_ == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Deck::getNumCards() //Getter
{
	return numCards_;
}
	
void Deck::displayCard(int i) //Displays given card
{
	
	std::cout << deck_[i].print() << std::endl;
	
}

void Deck::printDeck() //Prints all cards of deck
{
	for (int i = 0; i < numCards_; i++)
	{
		std::cout << deck_[i].print() << std::endl;
	}
}

bool Deck::addCard(Card c) //Adds new card to deck
{
	if(numCards_ < size_)
	{
		deck_[numCards_] = c; //Puts new card at index of deck
		numCards_++; //increases index of deck
		return true; //adds card 
	}
	else //Deck is full
	{
		return false; //card not added
	}	
}

void Deck::shuffle() //Shuffles Deck using random sort // Source: Jon(Tutor) helped me implement a better implementation of shuffle
{
	srand(time(NULL));
	int random_integer = 3 + rand() % 10; //randomized integer
	for(int x=0; x < random_integer; x++) //shuffling random int times
	{
		std::shuffle(deck_,deck_ + numCards_, std::default_random_engine(0)); //standard library shuffle method, shuffles both elements
	}
}

Card Deck::dealCard() //Deals card and removes from deck
{
	Card Ccard = getTopCard();
	numCards_--;
	return Ccard;
}

Card Deck::getTopCard() //returns top card of deck
{
	return deck_[numCards_ -1];
}
