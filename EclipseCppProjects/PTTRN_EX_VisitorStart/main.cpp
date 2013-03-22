#include "document.h"
#include "visitor.h"
#include "print_visitor.h"

#include <iostream>

using namespace demo;
using std::cout;
using std::endl;

//Create a Document and visit it
int main() {
	Line line1("More than prince of cats, I I can tell you. O, he is");
	Line line2("the courageous captain of compliments. He fights");
	Line line3("as you sing prick-song, keeps time, distance, and");
	Line line4("proportion; rests me his minim rest, one, two, and the ");
	Line line5("third in your bosom: the very butcher of a silk button,");
	Line line6("a duellist, a duellist; a gentleman of the very first");
	Line line7("house, of the first and second cause: ah, the");
	Line line8("immortal passado! the punto reverso! the hay!");

	Paragraph p1;
	p1.addLine(line1);
	p1.addLine(line2);
	p1.addLine(line3);

	Paragraph p2;
	p2.addLine(line4);
	p2.addLine(line5);
	p2.addLine(line6);

	Paragraph p3;
	p3.addLine(line7);
	p3.addLine(line8);

	Document doc;
	doc.addParagraph(p1);
	doc.addParagraph(p2);
	doc.addParagraph(p3);

	cout << endl << endl << "----- PRINT VISITOR OUTPUT ------" << endl;

	PrintVisitor pv;
	doc.accept(pv);

	cout << endl << endl << "----- HTML VISITOR OUTPUT ------" << endl;

}

