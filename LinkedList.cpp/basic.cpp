#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class LinkedList {
private:
    node *head, *tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertNode(int n) {
        node *temp = new node;
        temp->data = n;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = tail->next;
        }
    }

    void deleteNode(int n) {
        node *temp = head;
        node *prev = NULL;
        while (temp != NULL) {
            if (temp->data == n) {
                if (prev == NULL) {
                    head = temp->next;
                    delete temp;
                    return;
                } else {
                    prev->next = temp->next;
                    delete temp;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        }
    }
    void deleteLastNode(){
        node *temp= head;
        node *prev = NULL;
        while(temp->next != NULL){
            temp = temp->next;
        }
        tail = temp;
        temp = temp->next;
        delete temp;
    }

    void displayList() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(5);

    cout << "Original List: ";
    list.displayList();

    list.deleteNode(3);
    cout << "List after deleting node with value 3: ";
    list.displayList();

    return 0;
}
