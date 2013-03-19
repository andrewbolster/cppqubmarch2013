#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<map>

using namespace std;

void printUsingAccess(vector<string> vec) {
    for(unsigned int i=0; i<vec.size(); i++) {
        cout << "Element at index " << i << " is " << vec[i] << endl;
    }
    cout << endl;
}

void printUsingIterators(vector<string> vec) {
    vector<string>::iterator iter = vec.begin();
    cout << "Contents are: ";
    for(iter;iter != vec.end();iter++) {
        cout << *iter << " ";
    }
    cout << endl << endl;
}

int main() {
    vector<string> vec;

    string sarray[] = {"abc","def","ghi","jkl","mno","pqr","stu","vwx","yza"};
    for(int i=0; i<9; i++) {
        vec.push_back(sarray[i]);
    }

    printUsingAccess(vec);
    printUsingIterators(vec);

    vector<string>::iterator iter = vec.begin() += 2;
    vec.insert(iter,2,"XXXXXXX");

    printUsingIterators(vec);
}