#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);
    s.insert(10);

    cout << "The size of the set id: " <<s.size() << endl;

    set<int>::iterator it;
    for(it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}