demo : main.o
	g++  main.o -o demo
	
main.o : main.cpp
	g++ -c -I /usr/include/boost-1_33_1 main.cpp -o main.o
	
clean :
	rm *.o demo
	