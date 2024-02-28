#include<iostream>
#include<string>
#include<vector> // Include the vector header for using std::vector
using namespace std;

string longestCommonPrefix(const vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }

    string result = strs[0];

    for (const string& str : strs) {
        while (str.find(result) != 0) {
            result = result.substr(0, result.size() - 1);

            if (result.empty()) {
                return "";
            }
        }
    }
    return result;
}

int main() {
    vector<string> input = { "geeksforgeeks", "geeks", "geek", "geezer" };
    cout << "The longest Common Prefix is : "
         << longestCommonPrefix(input);
    return 0;
}
