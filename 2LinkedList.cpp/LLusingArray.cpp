#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// void createLinkedList(int arr[], int n, Node*& head){
//     if (n == 0) {
//         head = NULL;
//         return;
//     }
    
//     head = new Node(arr[0]);
//     Node* temp = head;

//     for(int i=1; i<n; i++){
//         Node* newNode = new Node(arr[i]);
//         newNode->next = NULL;
//         temp->next = newNode;
//         temp = newNode;
//     }
// }

void display(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

int main() {

    // int arr[5] = {1,2,3,4,5};
    // int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = NULL;

    createLinkedList(arr, n, head);
    display(head);

    return 0;
}