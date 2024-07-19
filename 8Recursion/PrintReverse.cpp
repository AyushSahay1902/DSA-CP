#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int first = -1;
    int last = -1;

    void firstAndLast(string str, int idx, char ele) {
        if (idx >= str.size()) {
            cout<< first << " " << last << endl;
            return;
        }
        if (str[idx] == ele) {
            if (first == -1) {
                first = idx;
            } else {
                last = idx;
            }
        }
        firstAndLast(str, idx + 1, ele);
    }

    void reverseString(string str, int len) {
        // base case
        if (len < 0) {
            return;
        }
        cout << str[len] << " ";
        reverseString(str, len - 1);
    }
};

int main() {
    string str;
    cin >> str;
    int len = str.size();

    Solution sol;
    sol.reverseString(str, len - 1);
    cout << endl;
    sol.firstAndLast(str, 0, 'a');
    
    return 0;
}
