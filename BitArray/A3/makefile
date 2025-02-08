Bit.exe: driver.o bitarray.o set.o dictionary.o
	g++ driver.o dictionary.o bitarray.o set.o -o Bit.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

dictionary.o: dictionary.cpp
	g++ -c dictionary.cpp -o dictionary.o

set.o: set.cpp
	g++ -c set.cpp -o set.o

bitarray.o: bitarray.cpp
	g++ -c bitarray.cpp -o bitarray.o
	
clean:
	rm -rf *.o Bit.exe
	
run:
	Bit.exe
