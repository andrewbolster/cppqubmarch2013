#include "document.h"
#include "visitor.h"

namespace demo {

	Line::Line(string txt) : text(txt) {}

	string& Line::getText() {
		return text;
	}

	//Accept a visitor
	void Line::accept(Visitor& visitor) {
		visitor.visitLine(*this);
	}

	Paragraph::Paragraph() {}

	void Paragraph::addLine(Line newLine) {
		lines.push_back(newLine);
	}

	LineVector& Paragraph::getLines() {
		return lines;
	}

	//Accept a visitor
	void Paragraph::accept(Visitor& visitor) {
		visitor.visitParagraph(*this);
	}

	Document::Document() {}

	void Document::addParagraph(Paragraph newParagraph) {
		paragraphs.push_back(newParagraph);
	}

	ParagraphVector& Document::getParagraphs() {
		return paragraphs;
	}

	//Accept a visitor
	void Document::accept(Visitor& visitor) {
		visitor.visitDocument(*this);
	}

}