/*
Caesar cipher.
Caesar cipher took its name from Julius Caesar who used it while writing letters to Cicero. Interesting thing is that this code was still used in 1915 by the Russian army because only such a simple cipher seemed understandable for staff officers.

The cipher works as follows:
Each letter from an decrypted text is changed to another letter from the Latin alphabet. According to the rule it has to be the third letter on the right from the one we want to encrypt. Thus the letter A is encrypted as D, letter B as E, etc. The letter Z is changed to C. In order to decrypt the text we repeat the operation by moving letters by three positions to the left.

Input
As an input you get a text that contains only uppercase letters of the Latin alphabet, spaces and newline characters. The length of input does not exceed 200 characters.

Output
Output should contain text encrypted with the Caesar cipher.

Example
Input:
ABC DEF
TERA EST ROTUNDA

Output:
DEF GHI
WHUD HVW URWXQGD
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            cout << " ";
        } else {
            cout << char((s[i] - 'A' + 3) % 26 + 'A');
        }
    }
    return 0;
}