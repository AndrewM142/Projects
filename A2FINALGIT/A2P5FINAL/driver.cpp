// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "deck.h"
#include "card.h"
#include "standardDeck.h"
#include "nonStandardDeck.h"
#include <iostream>
#include <fstream>
#include <string>
#define DECK_SIZE 52
#define ROUND_AMOUNT 50

void War(int x, bool Standard); //Function Declaration

int main()
{
	int rounds = ROUND_AMOUNT; //50 total rounds in game
	
	War(rounds, true); //Calls War game, passes rounds through 
	
	War(rounds, false); //Calls War game
		
	return 0;
}

void War(int rounds, bool Standard)
{
	//Variables
	
	int i = 0;
	int player1 = 0;
	int player2 = 0;
	int p1Total = 0;
	int p2Total = 0;
	double p1Avg = 0;
	double p2Avg = 0;		
	
	while(i < rounds) //While 50 rounds have not yet been played
	{		
	
		if(!Standard) //If bool equal to not standard
		{
			NonStandardDeck WarDeck; //Game Deck
			
			WarDeck.initializeDeck(); //initializes Game Deck
			
			NonStandardDeck p1(WarDeck.getNumCards()); //Initializes with game deck cards
			NonStandardDeck p2(WarDeck.getNumCards()); //Initializes with game deck cards
			NonStandardDeck PlayField(WarDeck.getNumCards()); //Initializes with game deck cards
			
			WarDeck.shuffle(); //Shuffle to ensure shuffle occurs
				
			//Shuffles WarDeck each round
			for(int j = 0; j < i; j++)
			{
					
				WarDeck.shuffle();
					
			}
				
			//Deals WarDeck to both players using temp card
				
			while(!WarDeck.isEmpty()) //Stop when WarDeck is empty
			{
				Card temp = WarDeck.dealCard();
				p1.addCard(temp);
					
				if(!WarDeck.isEmpty())
				{
					temp = WarDeck.dealCard(); //Define temp as being card if error
					p2.addCard(temp);
				}		
			}
				
			while(!p1.isEmpty() && !p2.isEmpty()) //While player 1 deck and player 2 deck not empty
			{			
					
				if(!PlayField.isEmpty() && PlayField.getTopCard().getFace() == p1.getTopCard().getFace()) //War condition for player 1
				{				
					p1.mergeDecks(PlayField, true); //Player 1 takes cards from playfield
								
					PlayField.addCard(p1.dealCard()); //Player 1 deals card to playfield
				}
				else //No war condition
				{
							
					PlayField.addCard(p1.dealCard()); //Player 1 deals card to playfield
						
				}
					
				if(!PlayField.isEmpty() && PlayField.getTopCard().getFace() == p2.getTopCard().getFace()) //War condition for player 2, see above 
				{
					p2.mergeDecks(PlayField, true); //Player 2 takes cards from playfield
						
					PlayField.addCard(p2.dealCard()); //Player 2 takes card from playfield
				}
				else
				{
							
					PlayField.addCard(p2.dealCard()); //Player 2 takes card from playfield
						
				}	
			}	
				
			if(p2.isEmpty()) //Player 1 wins
			{
				player1++; //Adds win to player 1
				p1Total += p1.getNumCards(); //Player 1 total points
						
			}
			else //Player 2 wins, see above
			{
				player2++; //Add win to player 2
				p2Total += p2.getNumCards(); //Player 2 total points
			}
			
		}
		else
		{
			
			StandardDeck WarDeck; //Creates Game Deck
			
			WarDeck.initializeDeck(); //initializes Game Deck
						
			StandardDeck p1; //Creates Player 1 deck
			StandardDeck p2; //Creates Player 2 deck
			StandardDeck PlayField; // Creates PlayField
			
			WarDeck.shuffle(); //makes sure to shuffle WarDeck each round
			
			//Shuffles WarDeck well each round 
			for(int j = 0; j < i; j++)
			{
				for(int k =0; k < 3; k++)
				{
					WarDeck.shuffle();
				}
			}
					
			while(!WarDeck.isEmpty())
			{
				//Deals WarDeck to both players using temp card
				
				Card temp = WarDeck.dealCard(); //Stop when WarDeck is empty
				p1.addCard(temp);
				
				if(!WarDeck.isEmpty())
				{
					temp = WarDeck.dealCard(); //Define temp as being card if error
					p2.addCard(temp);
				}		
			}
					
			while(!p1.isEmpty() && !p2.isEmpty()) //While nobody has won yet
			{				
				
				if(!PlayField.isEmpty() && PlayField.getTopCard().getFace() == p1.getTopCard().getFace()) //War condition for player 1
				{				
					p1.mergeDecks(PlayField, true); //Player 1 takes cards from playfield
								
					PlayField.addCard(p1.dealCard()); //Player 1 deals card to playfield
				}
				else //No war condition
				{
							
					PlayField.addCard(p1.dealCard()); //Player 1 deals card to playfield
						
				}
					
				if(!PlayField.isEmpty() && PlayField.getTopCard().getFace() == p2.getTopCard().getFace()) //War condition for player 2, see above 
				{
					p2.mergeDecks(PlayField, true); //Player 2 takes cards from playfield
						
					PlayField.addCard(p2.dealCard()); //Player 2 deals card to playfield
				}
				else //No war condition
				{
							
					PlayField.addCard(p2.dealCard()); //Player 2 deals card to playfield
						
				}	
				
			}	
			
			if(p2.isEmpty()) //Player 2 wins
			{
				player1++; //Adds win to player 1
				p1Total += p1.getNumCards(); //Player 1 total points
					
			}
			else //Player 2 wins
			{
				player2++; //Adds win to player 2
				p2Total += p2.getNumCards(); //Player 2 total points
			}
			
		}
			i++; //Next round	
	}
	
	if( player1 > player2 ) //Player 1 has more victories
	{
		std::cout << "Player 1 was the champion with " << player1 << " victories versus Player 2" << std::endl;
	}
	else if( player1 < player2 ) //Player 2 has more victories
	{
		std::cout << "Player 2 was the champion with " << player2 << " victories versus Player 1" << std::endl;	
	}
	else //Tie
	{
		std::cout << "Player 1 has tied with Player 2" << std::endl;
	}
		
	//Computes average points
	p1Avg = p1Total / rounds; 
	p2Avg = p2Total / rounds;
	
	std::cout << "Player 1 Average Score: " << p1Avg << std::endl;
	std::cout << "Player 2 Average Score: " << p2Avg << std::endl;
	
}
