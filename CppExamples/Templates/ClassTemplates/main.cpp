#include "list.hpp"
#include<string>

using std::string;

int main() {
	List<string> list;
	cout << "----- Empty list -----" << endl;
	list.print();

	list.add("abc");
	list.add("def");
	list.add("ghi");
	list.add("jkl");
	list.add("mno");
	list.add("pqr");
	list.add("stu");

	cout << "----- Full list -----" << endl;
	list.print();

	list.remove(0);
	cout << "----- List with 0 removed -----" << endl;
	list.print();

	list.remove(5);
	cout << "----- List with 5 removed -----" << endl;
	list.print();

	list.remove(2);
	cout << "----- List with 2 removed -----" << endl;
	list.print();

	cout << "----- Final list contents -----" << endl;
	cout << "\t" << list.get(0) << endl;
	cout << "\t" << list.get(1) << endl;
	cout << "\t" << list.get(2) << endl;
	cout << "\t" << list.get(3) << endl;

	cout << "----- End of Program -----" << endl;
}