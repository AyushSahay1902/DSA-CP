#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
    private:
    Node* top;
    public:
    Stack() {
        top = nullptr;
    }

    void push(int ele) {
        Node newNode = new Node(ele);
        if(!top){
            top = newNode;
        }else{
            newNode->next = top;
            top = newNode;
        }
    }

    void pop() {
        if(!top) {
            cout << "Sttack is empty" <<endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if(!top) {
            cout << "Underflow" <<endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
}



int main() {


    return 0;
}
