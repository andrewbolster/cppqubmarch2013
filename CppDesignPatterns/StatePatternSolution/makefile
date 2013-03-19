demo : main.o seating.o flight.o
	g++ seating.o main.o flight.o -o demo

main.o : main.cpp flight.h
	g++ -c main.cpp -o main.o

flight.o : flight.cpp flight.h seating.h
	g++ -c flight.cpp -o flight.o

seating.o : seating.cpp seating.h
	g++ -c seating.cpp -o seating.o

clean :
	rm *.o demo

