#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    int starCount = 0, hashCount = 0;
    for(int i=0; i<S.size(); i++) {
        if(S[i] == '*') {
            starCount++;
        } else if(S[i] == '#') {
            hashCount++;
        } else {
            cout << "Invalid String" << endl;
            return 1;
        }
    }

    if(starCount == hashCount) cout << 0;
    else if(starCount > hashCount) cout << 1;
    else cout << -1;

    return 0;
}