#include "html_visitor.h"
#include "document.h"

#include<iostream>
#include<vector>
#include<string>

using namespace std;

namespace demo {

	//To visit a Paragraph just print its contents
	void HTMLVisitor::visitLine(Line& line) {
		result << "\t\t" << line.getText() << "<br/>" << endl;
	}

	//To visit a Paragraph visit all its Lines
	void HTMLVisitor::visitParagraph(Paragraph& paragraph) {
		LineVector& vector = paragraph.getLines();
		LineVector::iterator iter;

		result << "\t<p>" << endl;
		for(iter = vector.begin(); iter != vector.end(); iter++) {
			iter->accept(*this);
		}
		result << "\t</p>" << endl;
	}

	//To visit a Document visit all its Paragraphs
	void HTMLVisitor::visitDocument(Document& document) {
		ParagraphVector& vector = document.getParagraphs();
		ParagraphVector::iterator iter;

		result << "<html>" << endl;
		for(iter = vector.begin(); iter != vector.end(); iter++) {
			iter->accept(*this);
		}
		result << "</html>" << endl;
	}

	void HTMLVisitor::print() {
		cout << result.str();
	}

}