#ifndef VISITOR_H
#define VISITOR_H

namespace demo {

	class Line;
	class Paragraph;
	class Document;

	class Visitor {
	public:
		virtual void visitLine(Line& line) = 0;
		virtual void visitParagraph(Paragraph& paragraph) = 0;
		virtual void visitDocument(Document& document) = 0;
	};

}

#endif //VISITOR_H
