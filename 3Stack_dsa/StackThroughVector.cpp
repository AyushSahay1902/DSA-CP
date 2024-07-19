#include <iostream>
using namespace std;

class Stack {
    public:
        Stack();
        bool empty() {return my_vec.empty();}
        void push(int item) {my_vec.push_back(item);}
        void pop() {my_vec.pop_back();}
        void top() {return my_vec.back();}
    private:
        vector<int> my_vec;
}


int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}