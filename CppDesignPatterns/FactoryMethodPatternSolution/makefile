demo : main.o shopping_cart.o
	g++ shopping_cart.o main.o -o demo

main.o : main.cpp shopping_cart.h
	g++ -c main.cpp -o main.o

shopping_cart.o : shopping_cart.cpp shopping_cart.h list.h array.h interface.h
	g++ -c shopping_cart.cpp -o shopping_cart.o

clean :
	rm *.o demo

