// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "card.h"

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"}; //All card suits

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"}; //All card faces

Card::Card() // Default Constructor
{
	suitVal_ = 0;
	faceVal_ = 0;
}

Card::Card(int suitVal, int faceVal) //Parameterized Constructor
{
	suitVal_ = suitVal;
	faceVal_ = faceVal;	
}

Card::~Card() //Destructor
{
	
	
}

//Getters
std::string Card::getSuit()
{
	return SUIT[suitVal_];
}
std::string Card::getFace()
{
	return FACE[faceVal_];
}

//Prints Card
std::string Card::print()
{
	return FACE[faceVal_] + " of " + SUIT[suitVal_];
}

//Initializes suitVal and faceVal
void Card::initialize(int suitVal, int faceVal)
{
	suitVal_ = suitVal;
	faceVal_ = faceVal;
}
