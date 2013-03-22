#ifndef HTML_VISITOR_H
#define HTML_VISITOR_H

#include "visitor.h"

#include<sstream>

using std::ostringstream;

namespace demo {
	//A sample visitor implementation
	class HTMLVisitor : public Visitor {
	private:
		ostringstream result;
	public:
		void visitLine(Line& line);
		void visitParagraph(Paragraph& paragraph);
		void visitDocument(Document& document);
		void print();
	};
}

#endif //HTML_VISITOR_H
