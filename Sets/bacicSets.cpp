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

    s.erase(5);

    // Deleting the elements using iterator.
    set<int>::iterator it;
    auto itr = s.begin();
    advance(itr, 3);
    s.erase(itr);
    
    auto start_itr = s.begin();
    start_itr++;

    auto end_itr = s.begin();
    advance(end_itr, 3);

    s.erase(start_itr, end_itr);

    //Member Function of a Set Container
    //size(), maxSixe(), empty(), clear(), find(), 


    cout << "The size of the set id: " <<s.size() << endl;
    for(it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;


}