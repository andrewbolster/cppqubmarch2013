#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<map>

using namespace std;

void printMap(map<int,string> container) {

    map<int,string>::iterator iterator;

    for(iterator = container.begin(); iterator != container.end(); iterator++) {
        pair<int,string> p = *iterator;
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;
}

void populateMap(map<int,string>& m) {
    typedef map<int,string>::value_type entry;

    string sarray[] = {"abc","def","ghi","jkl","mno","pqr","stu","vwx","yza"};
    int keys[] = {1,2,3,4,5,6,7,8,9};

    for(int i=0; i<9; i++) {
        m.insert(entry(keys[i], sarray[i]));
    }
}

int main() {
    map<int,string> tst_map;

    populateMap(tst_map);

    printMap(tst_map);

    map<int,string>::iterator iterator = tst_map.find(5);
    cout << "Key 5 associated with string: " << iterator->second << endl;
    cout << "Key 8 associated with string: " << tst_map[8] << endl << endl;

    tst_map.erase(3);
    tst_map.erase(6);
    printMap(tst_map);
}
