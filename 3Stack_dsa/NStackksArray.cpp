#include <bits/stdc++.h>
using namespace std;

//Approach-1: devide the array into N size staacks
//Approach-2: Optimised Space Management

#include <iostream>
using namespace std;

class NStack {
    int *arr;
    int *top;
    int *next;

    int n, s;
    int freespot;

public:
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Initialize top array
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // Initialize next array
        for (int i = 0; i < s; i++) {
            next[i] = i + 1;
        }
        // Last index of next array should be -1
        next[s - 1] = -1;

        // Initialize freespot
        freespot = 0;
    }

    bool push(int ele, int m) {
        // Check for overflow
        if (freespot == -1) {
            cout << "Stack Overflow" << endl;
            return false;
        }

        // Find index
        int index = freespot;

        // Update freespot
        freespot = next[index];

        // Insert element into array
        arr[index] = ele;

        // Update next
        next[index] = top[m - 1];

        // Update top
        top[m - 1] = index;

        return true;
    }

    int pop(int m) {
        // Check for underflow
        if (top[m - 1] == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

int main() {
    NStack ns(3, 10);  // 3 stacks in an array of size 10

    ns.push(10, 1);
    ns.push(20, 1);
    ns.push(30, 2);
    ns.push(40, 2);

    cout << "Popped from stack 1: " << ns.pop(1) << endl;  // 20
    cout << "Popped from stack 1: " << ns.pop(1) << endl;  // 10
    cout << "Popped from stack 2: " << ns.pop(2) << endl;  // 40
    cout << "Popped from stack 2: " << ns.pop(2) << endl;  // 30

    return 0;
}
