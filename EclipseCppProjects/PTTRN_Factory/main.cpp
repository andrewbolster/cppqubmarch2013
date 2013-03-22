#include<iostream>
#include<string>

using namespace std;

class Widget {
public:
	virtual void display() = 0;
};

class Win32Widget : public Widget {
public:
	void display();
};

class MotifWidget : public Widget {
public:
	void display();
};

class Factory {
public:
	virtual Widget* buildWidget() = 0;
};

class Win32Factory : public Factory {
public:
	Widget* buildWidget();
};

void Win32Widget::display() {
	cout << "Win32Widget::display" << endl;
}

void MotifWidget::display() {
	cout << "MotifWidget::display" << endl;
}

Widget* Win32Factory::buildWidget() {
	//In a real factory we would pick an inactive Widget from a object pool
	// or initialise a new Widget with platfrom specific data
	return new Win32Widget();
}

void runGUI(Factory * factory) {
	Widget* w = factory->buildWidget();
	w->display();
}

int main() {
	Win32Factory factory;
	runGUI(&factory);
}

