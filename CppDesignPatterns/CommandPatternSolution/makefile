demo : main.o commands.o
	g++ commands.o main.o -o demo

main.o : main.cpp list.h commands.h
	g++ -c main.cpp -o main.o

commands.o : commands.cpp commands.h list.h
	g++ -c commands.cpp -o commands.o

clean :
	rm *.o demo

