// Given M books and N students. Each book has a number of pages. Allocate books to N students so that maximum number of pages allocated to a student is minimum. Each student has to be allocated atleast one book.
// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see explanation for better understanding).
// time complexity: O(nlogn)
// space complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> arr, int n, int m, int mid) {
    int student = 1, sum = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > mid) return false;
        if(sum + arr[i] > mid) {
            student++;
            sum = arr[i];
            if(student > m) return false;
        }
        else sum += arr[i];
    }
    return true;
}

int allocateBook(vector<int> arr, int n, int m) {
    if(n < m) return -1;
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    int start = 0, end = sum, res = -1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(isValid(arr, n, m, mid)) {
            res = mid;
            end = mid - 1;
        }
        else start = mid + 1;
        mid = start + (end - start) / 2;
    }
    return res;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << allocateBook(arr, n, m) << endl;
    return 0;
}