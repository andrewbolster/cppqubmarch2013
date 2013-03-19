demo : main.o document.o print_visitor.o html_visitor.o
	g++ main.o document.o print_visitor.o html_visitor.o -o demo

main.o : main.cpp document.h visitor.h print_visitor.h html_visitor.h
	g++ -c main.cpp -o main.o

html_visitor.o : html_visitor.cpp visitor.h document.h
	g++ -c html_visitor.cpp -o html_visitor.o

print_visitor.o : print_visitor.cpp visitor.h document.h
	g++ -c print_visitor.cpp -o print_visitor.o

document.o : document.cpp document.h visitor.h
	g++ -c document.cpp -o document.o

clean :
	rm *.o demo

