A6.exe: driver.o Node.o LinkedNode.o LinkedList.o DoubleLinkedList.o HashEntry.o HashTableArray.o HashTableChaining.o HashTableCuckoo.o
	g++ driver.o Node.o LinkedNode.o LinkedList.o DoubleLinkedList.o HashEntry.o HashTableArray.o HashTableChaining.o HashTableCuckoo.o -o A6.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o
	
LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o
	
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o
	
DoubleLinkedList.o: DoubleLinkedList.cpp
	g++ -c DoubleLinkedList.cpp -o DoubleLinkedList.o
	
HashEntry.o: HashEntry.cpp
	g++ -c HashEntry.cpp -o HashEntry.o

HashTableArray.o: HashTableArray.cpp
	g++ -c HashTableArray.cpp -o HashTableArray.o
	
HashTableChaining.o: HashTableChaining.cpp
	g++ -c HashTableChaining.cpp -o HashTableChaining.o

HashTableCuckoo.o: HashTableCuckoo.cpp
	g++ -c HashTableCuckoo.cpp -o HashTableCuckoo.o

clean:
	rm -rf *.o A6.exe
	
run:
	A6.exe
	