demo : main.o flight.o
	g++ main.o flight.o -o demo

main.o : main.cpp flight.h
	g++ -c main.cpp -o main.o

flight.o : flight.cpp flight.h
	g++ -c flight.cpp -o flight.o

clean :
	rm *.o demo

