#
# Author: Chadd Trudel (5010918)
#

FileDict : FileDict.o 
	g++ FileDict.o  -o FileDict


FileDict.o : FileDict.cpp
	g++ -c FileDict.cpp


clean : 
	rm *.o FileDict
