#ifndef DOCUMENT_H
#define DOCUMENT_H

#include<vector>
#include<string>

using std::vector;
using std::string;

namespace demo {
	class Line;
	class Paragraph;
	class Visitor;

	//Typedefs for clarity
	typedef vector<Line> LineVector;
	typedef vector<Paragraph> ParagraphVector;

	//Base class for our Document and its contents
	class Component {
	public:
		virtual void accept(Visitor& visitor) = 0;
	};

	//A class representing a Line
	class Line : public Component {
	public:
		Line(string txt);
		string& getText();
		void accept(Visitor& visitor);
	private:
		string text;
	};

	//A class representing a Paragraph
	class Paragraph : public Component {
	public:
		Paragraph();
		void addLine(Line newLine);
		LineVector& getLines();
		void accept(Visitor& visitor);
	private:
		LineVector lines;
	};

	//A class representing a Document
	class Document : public Component {
	public:
		Document();
		void addParagraph(Paragraph newParagraph);
		ParagraphVector& getParagraphs();
		void accept(Visitor& visitor);
	private:
		ParagraphVector paragraphs;
	};

}
#endif //DOCUMENT_H

