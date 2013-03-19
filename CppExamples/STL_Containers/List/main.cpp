#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<map>

using namespace std;

void printUsingIterators(list<string> t) {
    list<string>::iterator iter = t.begin();
    cout << "Contents are: ";
    for(iter;iter != t.end();iter++) {
        cout << *iter << " ";
    }
    cout << endl << endl;
}

int main() {
    list<string> myList;

    string sarrayOne[] = {"abc","def","ghi","jkl"};
    for(int i=0; i<4; i++) {
        myList.push_back(sarrayOne[i]);
    }
    string sarrayTwo[] = {"www","xxx","yyy","zzz"};
    for(int i=0; i<4; i++) {
        myList.push_front(sarrayTwo[i]);
    }

    printUsingIterators(myList);

    list<string>::iterator iter = myList.begin();
    iter++;
    myList.insert(iter,2,"XXXXXXX");

    printUsingIterators(myList);
}