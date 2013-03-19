#include "print_visitor.h"
#include "document.h"

#include<iostream>
#include<vector>
#include<string>

using namespace std;

namespace demo {

	//To visit a Paragraph just print its contents
	void PrintVisitor::visitLine(Line& line) {
		cout << "\t" << line.getText() << endl;
	}

	//To visit a Paragraph visit all its Lines
	void PrintVisitor::visitParagraph(Paragraph& paragraph) {
		LineVector& vector = paragraph.getLines();
		LineVector::iterator iter;

		cout << "\nNew Paragraph\n";
		for(iter = vector.begin(); iter != vector.end(); iter++) {
			iter->accept(*this);
		}
	}

	//To visit a Document visit all its Paragraphs
	void PrintVisitor::visitDocument(Document& document) {
		ParagraphVector& vector = document.getParagraphs();
		ParagraphVector::iterator iter;

		cout << "\nNew Document\n";
		for(iter = vector.begin(); iter != vector.end(); iter++) {
			iter->accept(*this);
		}
	}

}