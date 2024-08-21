#include <bits/stdc++.h>
using namespace std;

vector<int> findNextSmaller(vector<int> &arr, int n){
    stack<int> st;

    st.push(-1);
    vector<int> ans;

    for(int i = 0; i<n; i++){
        while(st.top() != -1 && (st.top() >= arr[i])){
            st.pop();
        }

        ans[i] = st.top();
        st.push(arr[i]);
    }
}

vector<int> findSmallestOfAll(vector<int> &arr, int n) {
    stack<int> st;
    vector<int> result(n);

    st.push(INT_MIN);

    for (int i = 0; i < n; i++) {
        while (st.top() != INT_MIN && st.top() >= arr[i]) {
            st.pop();
        }

        result[i] = st.top();
        st.push(arr[i]);
    }

    return result;
}

int largestRectangularArea(vector<int> &heights){
    int n  = heights.size();
    int area = INT_MIN;
    vector<int> next;
    next = findNextSmaller(heights, n);
    vector<int> prev;
    prev = findNextSmaller(heights, n);

    for(int i = 0; i<n; i++){
        int l = heights[i];
        if(next[i] == -1){
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;

        int newArea = l*b;

        area = max(area, newArea);
    }
    return area;
}

int main() {
    vector<int> arr = {2, 3, 1, 4};
    int size = arr.size();
    //Next larget element

    vector<int> nextSmaller = findNextSmaller(arr, size);

  return 0;

}