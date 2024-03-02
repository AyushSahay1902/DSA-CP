#include<iostream>
#include<string>
using namespace std;

pair<string, string> MinMaxLengthWords(string s) {
    int len = s.length();
    int startIndex = 0, endIndex = 0;

    int minLength = len, minStartIndx = 0, maxLength = 0, maxStartIndx = 0;
    while (endIndex <= len) {
        if (endIndex < len && s[endIndex] != ' ') {
            endIndex++;
        } else {
            int currLength = endIndex - startIndex;
            if (currLength < minLength) {
                minLength = currLength;
                minStartIndx = startIndex;
            }

            if (currLength > maxLength) {
                maxLength = currLength;
                maxStartIndx = startIndex;
            }
            endIndex++;
            startIndex = endIndex;
        }
    }
    string minWord = s.substr(minStartIndx, minLength);
    string maxWord = s.substr(maxStartIndx, maxLength);

    return make_pair(minWord, maxWord);
}

int main() {
    string str = "This is a test string";
    pair<string, string> result = MinMaxLengthWords(str);
    cout << "Minimum Length Word: " << endl;
    cout << result.first << endl;
    cout << "Maximum Length Word: " << endl;
    cout << result.second << endl;

    return 0;
}
