#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    string vowels = "AEIOUaeiou";

    int len1 = a.length();
    int len2 = b.length();
    int len3 = c.length();

    for(int i = 0; i < len1; i++){
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || 
           a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U') {
            a[i] = '%';
        }
    }

    for(int j = 0; j < len2; j++){
        if(b[j] != 'a' && b[j] != 'e' && b[j] != 'i' && b[j] != 'o' && b[j] != 'u' && 
           b[j] != 'A' && b[j] != 'E' && b[j] != 'I' && b[j] != 'O' && b[j] != 'U') {
            b[j] = '#';
        }
    }

    for(int k = 0; k < len3; k++){
        c[k] = toupper(c[k]);
    }

    // Print a, b, c separated by spaces
    cout << a << "" << b << "" << c;

    return 0;
}
