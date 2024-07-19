#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue() {
        if (front == NULL) {
            return -1;
        } else {
            Node* temp = front;
            int data = front->data;
            front = front->next;
            if (front == NULL) {
                rear = NULL;
            }
            delete temp;
            size--;
            return data;
        }
    }

    int getFront() {
        if (front == NULL) {
            return -1;
        } else {
            return front->data;
        }
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    Queue q;
    int queries;
    cin >> queries;

    while (queries--) {
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cin >> data;
                q.enqueue(data);
                break;
            }
            case 2: {
                int dequeued = q.dequeue();
                if (dequeued == -1) {
                    cout << "Queue is empty\n";
                } else {
                    cout << dequeued << endl;
                }
                break;
            }
            case 3: {
                int front = q.getFront();
                if (front == -1) {
                    cout << "Queue is empty\n";
                } else {
                    cout << front << endl;
                }
                break;
            }
            case 4: {
                cout << q.getSize() << endl;
                break;
            }
            case 5: {
                if (q.isEmpty()) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
                break;
            }
            default: {
                cout << "Invalid choice\n";
                break;
            }
        }
    }

    return 0;
}
