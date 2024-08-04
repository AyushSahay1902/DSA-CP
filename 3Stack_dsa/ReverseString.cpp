#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &st, int num){
    //base case
    if(st.empty() ||(!st.empty() && st.top < num)){
        st.push(num);
        return;
    }

    int n = st.top();
    st.pop();

    sortedInsert(st, n);

    st.push(n);
}

void sortStack(stack<int> &st){
    //base case
    if(st.empty()){
        return;
    }

    int num = st.top();
    st.pop();

    sortStack(st);

    sortedInsert(st, num);
}

void insertAtBottom(stack<int>& st, int n) {
    if (st.empty()) {
        st.push(n);
        return;
    }

    int num = st.top();
    st.pop();
    insertAtBottom(st, n);
    st.push(num);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    int n;
    cin >> n;
    insertAtBottom(st, n);

    // Printing the stack elements
    stack<int> tempStack;
    while (!st.empty()) {
        tempStack.push(st.top());
        st.pop();
    }

    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        st.push(tempStack.top());
        tempStack.pop();
    }

    cout << endl;
    return 0;
}
