#include <iostream>
#include <string>

using namespace std;

void printString(const string &str);
void printLetters(string& s);
void printWords(std::string& s);

int main() {

    string str1("abc");

    str1 += "def";

    printString(str1);

    string str2 = "ghijklmnop";

    str1.swap(str2);

    printString(str1);

    str1.erase(str1.begin(),str1.end());

    printString(str1);

    str1 = str2.substr(3,3);

    printString(str1);

    str1.insert(0,"zzzxxxzzzz");

    printString(str1);

    cout << "Index of first non-z char is: " << str1.find_first_not_of('z') << endl;

    cout << "Index of first instance of 'zd' is: " << str1.find("zd") << endl << endl;

    const char* str_ptr = str1.c_str();

    cout << "Value of str_ptr is: " << str_ptr << endl << endl;

    std::string test("abc def ghi jkl mno");
    printLetters(test);
    printWords(test);
}

void printString(const string &str) {

    if(str.empty()) {
        cout << "String is empty!" << endl << endl;
    } else {
        cout << "String contents now: " << str << " with length " 
             << str.length() << endl << endl;
    }
}
//print out all characters followed by '#'
void printLetters(string& s) {
    string::iterator i = s.begin();
    for(i; i != s.end(); i++) {
        cout<<*i <<'#';
    }
    cout<<endl<<endl;
}
//print out each word on a new line
void printWords(std::string& s) {
    int i = 0;
    int i2 = 0;
    while(string::npos != (i2 = s.find_first_of(" ",i))) {
        cout<< s.substr(i,(i2-i)) <<endl;
        i = ++i2;
    }
    cout<< s.substr(i,string::npos) << endl;
}