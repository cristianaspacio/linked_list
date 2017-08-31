
Version2.0: userinterface.o llist.o
	g++ -o Version2.0 userinterface.o llist.o 
userinterface.o: userinterface.cpp
	g++ -c userinterface.cpp 
llist.o: llist.cpp
	g++ -c llist.cpp 
Version1.0: project1interface.o recordFunctions.o
	gcc -o Version1.0 project1interface.o recordFunctions.o
project1interface.o: project1interface.c
	gcc -c project1interface.c
recordFunctions.o: recordFunctions.c
	gcc -c recordFunctions.c
clean: 
	rm -rf *o Version2.0
	rm -rf *o Version1.0
