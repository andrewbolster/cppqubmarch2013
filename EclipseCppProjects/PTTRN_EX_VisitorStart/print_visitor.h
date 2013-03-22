#ifndef PRINT_VISITOR_H
#define PRINT_VISITOR_H

#include "visitor.h"

namespace demo {

	//A sample visitor implementation
	class PrintVisitor : public Visitor {
	public:
		void visitLine(Line& line);
		void visitParagraph(Paragraph& paragraph);
		void visitDocument(Document& document);
	};

}

#endif //PRINT_VISITOR_H
