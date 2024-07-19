//Find the first and last element in an sorted array.
#include<iostream>
#include<vector>
using namespace std;

int firstoccr(vector<int>& arr, int n, int key) {
    int s = 0, e = n - 1;
    int mid;

    while (s <= e) {
        mid = s + (e - s) / 2;
        if (arr[mid] == key) {
            if (mid > 0 && arr[mid - 1] == key) {
                e = mid - 1;
            }
            else {
                return mid;
            }
        }
        else if (arr[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    return -1; // Return an appropriate value if key is not found
}

int LastOccr(vector<int>& arr, int n, int key) {
    int s = 0, e = n - 1;
    int mid;

    while (s <= e) {
        mid = s + (e - s) / 2;
        if (arr[mid] == key) {
            if (mid < n - 1 && arr[mid + 1] == key) {
                s = mid + 1;
            }
            else {
                return mid;
            }
        }
        else if (arr[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    return -1; // Return an appropriate value if key is not found
}

pair<int, int> FirstAndLastIndices(vector<int>& arr, int n, int key) {
    pair<int, int> p;
    p.first = firstoccr(arr, n, key);
    p.second = LastOccr(arr, n, key);

    return p;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 5, 7, 8, 9, 9};
    pair<int, int> result = FirstAndLastIndices(arr, 10, 5);

    if (result.first != -1 && result.second != -1) {
        cout << "First and Last Occurrence of 5 is: " << result.first << " and " << result.second << endl;
    } else {
        cout << "Key not found in the array." << endl;
    }

    return 0;
}
