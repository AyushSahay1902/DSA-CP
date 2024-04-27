#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Linkedlist {
    public:
    struct Node{
        int data;
        Node* next;
        // Node() : data(0), next(nullptr) {} //Constructor
        Node(int data) : data(data), next(nullptr) {}
    };

    Node* head;
    Linkedlist() : head(nullptr) {}
    
}


int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArrtoLL(arr);
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}