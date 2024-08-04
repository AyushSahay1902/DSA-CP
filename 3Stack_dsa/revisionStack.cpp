#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    int *arr;
    int top;
    int size;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int ele) {
        if (size - top > 1) {
            top++;
            arr[top] = ele;
        } else {
            cout << "Overflow" << endl;
        }
    }

    void pop() {
        if (top != -1) {
            top--;
        } else {
            cout << "Underflow" << endl;
        }
    }

    int peek() {
        if (top >= 0 && top < size) return arr[top];
        else {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st.pop();
    st.pop();

    cout << "Top element: " << st.peek() << endl;

    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
