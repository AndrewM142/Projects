# Honor Pledge:
#
# I pledge that I have neither given nor
# received any help on this assignment.
#
# agminton

Cards.exe: driver.o standardDeck.o nonStandardDeck.o deck.o card.o
	g++ driver.o standardDeck.o nonStandardDeck.o deck.o card.o -o Cards.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
	
standardDeck.o: standardDeck.cpp
	g++ -c standardDeck.cpp -o standardDeck.o
	
nonStandardDeck.o: nonStandardDeck.cpp
	g++ -c nonStandardDeck.cpp -o nonStandardDeck.o
	
deck.o: deck.cpp
	g++ -c deck.cpp -o deck.o

card.o: card.cpp
	g++ -c card.cpp -o card.o
	
clean:
	rm -rf *.o Cards.exe
	
run:
	Cards.exe
