#include <iostream>
#include <vector>
using namespace std;

void solve(string str, string output, int index, vector<string>& ans) {
    if (index >= str.length()) {
        if (!output.empty()) {
            ans.push_back(output);
        }
        return;
    }

    // Exclude the current character
    solve(str, output, index + 1, ans);

    // Include the current character
    output.push_back(str[index]);
    solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";
    int index = 0;

    solve(str, output, index, ans);
    return ans;
}

void printVector(const vector<string>& vec) {
    for (const string& s : vec) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    string str;
    cin >> str;
    vector<string> ans = subsequences(str);
    printVector(ans);
    return 0;
}
