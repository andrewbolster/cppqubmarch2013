#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

void showFindAlgorithm(vector<string>& vec);
void showFindIfAlgorithm(vector<string>& vec);
void showFindEndAlgorithm(vector<string>& vec);
void showFindFirstOfAlgorithm(vector<string>& vec);
void showAdjacentFindAlgorithm(vector<string>& vec);

int main() {
	vector<string> vec;
	vec.push_back("abc");
	vec.push_back("aaa");
	vec.push_back("def");
	vec.push_back("def");
	vec.push_back("ghi");
	vec.push_back("aaa");
	vec.push_back("jkl");
	vec.push_back("mno");
	vec.push_back("pqr");
	vec.push_back("aaa");
	vec.push_back("stu");
	vec.push_back("vwx");
	vec.push_back("vwx");
	vec.push_back("yza");
	vec.push_back("aaa");
	vec.push_back("abc");

	showFindAlgorithm(vec);
	showFindIfAlgorithm(vec);
	showFindEndAlgorithm(vec);
	showFindFirstOfAlgorithm(vec);
	showAdjacentFindAlgorithm(vec);


}
void showFindAlgorithm(vector<string>& vec) {
	cout << endl << endl << "showFindAlgorithm" << endl;

	vector<string>::iterator end = vec.end();
	vector<string>::iterator start = vec.begin();
	vector<string>::iterator current = start;

	while(1) {
		current = find(start,end,"aaa");
		if(current != end) {
			cout << "Found search string at position: " << current - vec.begin() << endl;
			start = ++current;
		} else {
			break;
		}
	}
}

class StartsWithFunctor {
public:
	bool operator()(string& value) {
		return value[0] == 'a';
	}
};

void showFindIfAlgorithm(vector<string>& vec) {
	cout << endl << endl << "showFindIfAlgorithm" << endl;

	vector<string>::iterator end = vec.end();
	vector<string>::iterator start = vec.begin();
	vector<string>::iterator current = start;
	StartsWithFunctor sf;


	while(1) {
		current = find_if(start,end,sf);
		if(current != end) {
			cout << "String: " << *current
				 << " at " << current - vec.begin()
				 << " starts with a" << endl;
			start = ++current;
		} else {
			break;
		}
	}
}

void showFindEndAlgorithm(vector<string>& vec) {
	cout << endl << endl << "showFindEndAlgorithm" << endl;

	vector<string> target;
	target.push_back("ghi");
	target.push_back("aaa");
	target.push_back("jkl");
	target.push_back("mno");

	vector<string>::iterator position;

	position = find_end(vec.begin(),vec.end(),target.begin(),target.end());

	if(position == vec.end()) {
		cout << "The sub-sequence cannot be found" << endl;
	} else {
		cout << "The sub-sequence begins at position " << position - vec.begin() << endl;
	}
}
void showFindFirstOfAlgorithm(vector<string>& vec) {
	cout << endl << endl << "showFindFirstOfAlgorithm" << endl;

	vector<string> target;
	target.push_back("ghi");
	target.push_back("aaa");
	target.push_back("jkl");
	target.push_back("mno");

	vector<string>::iterator position;

	position = find_first_of(vec.begin(),vec.end(),target.begin(),target.end());

	if(position == vec.end()) {
		cout << "None of the sub-sequence elements are present in the main sequence" << endl;
	} else {
		cout << "The first member of the sub-sequence to be found in the main sequence is "
			 << *position << " at position " << position - vec.begin() << endl;
	}
}
class StartsNotWithFunctor {
public:
	bool operator()(string& value1,string& value2) {
		return (value1 == value2) && (value1[0] != 'd');
	}
};

void showAdjacentFindAlgorithm(vector<string>& vec) {
	cout << endl << endl << "showFindFirstOfAlgorithm" << endl;

	vector<string>::iterator position;

	position = adjacent_find(vec.begin(),vec.end());

	if(position != vec.end()) {
		cout << "First pair of adjacent and equal elements begins at "
			 << position - vec.begin() << endl;
	}

	StartsNotWithFunctor sf;
	position = adjacent_find(vec.begin(),vec.end(),sf);

	if(position != vec.end()) {
		cout << "First pair of adjacent and equal elements not starting with d begins at "
			 << position - vec.begin() << endl;
	}
}
