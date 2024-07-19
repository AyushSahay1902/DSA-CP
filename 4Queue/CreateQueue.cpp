#include <iostream>
#include <queue>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int size;
    public:
    Queue() {
        size = 1000001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty(){
        return (rear == front);
    }
    void enqueue(int data){
        if(rear == size){
            cout << "Queue is full!" << endl;
        }else{
            arr[rear] = data;
            rear++;
        }
    }
    void dequeue() {
        if(front == rear){
            return;
        }else{
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
        }
    }
    int frontElement(){
        if(front == rear){
            return -1;
        }else{
            return arr[front];
        }
    }
};


int main() {
    //Array Implementation of Queue
    int arr[5] = {11,121,131,141,151};
    Queue q;
    
    //Enqueue
    for(int i = 0; i < 5; i++){
        q.enqueue(arr[i]);
    }
    
    //Dequeue
    q.dequeue();
    
    //Front
    cout << "Front element: " << q.frontElement() << endl;

    return 0;
}