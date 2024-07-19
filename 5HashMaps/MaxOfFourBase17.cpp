#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

double solve(string &str) {
    unordered_map<char, int> map;
    map['A'] = 10;
    map['B'] = 11;
    map['C'] = 12;
    map['D'] = 13;
    map['E'] = 14;
    map['F'] = 15;
    map['G'] = 16;
    map['a'] = 10;
    map['b'] = 11;
    map['c'] = 12;
    map['d'] = 13;
    map['e'] = 14;
    map['f'] = 15;
    map['g'] = 16;

    int k = 0;
    double num = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
        char ch = str[i];
        if ((ch >= 'a' && ch <= 'g') || (ch >= 'A' && ch <= 'G')) {
            num += map[ch] * pow(17, k++);
        } else if (isdigit(ch)) {
            num += (ch - '0') * pow(17, k++);
        } else {
            cout << "Invalid Input";
            return 0;
        }
    }
    return num;
}

int main() {
    // cout << "Hello, World!\n";

    string str;
    getline(cin, str);

    double result = solve(str);
    cout << result << endl;

    return 0;
}
