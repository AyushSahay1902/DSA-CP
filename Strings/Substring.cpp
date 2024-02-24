#include<iostream>
#include<string>
#include<cstring> // Include the cstring header for strlen
using namespace std;

// void substring(char str[], int n){
//     for(int len = 1; len <= n; len++){
//         for(int i = 0; i <= n - len; i++){   This function uses O(n^3) -tc and O(1) - sc
//             int j = i + len - 1;
//             for(int k = i; k <= j; k++){
//                 cout << str[k];
//             }
//             cout << endl;
//         }
//     }
// }

void substring(string &str, int n){
    for(int i=0; i< n; i++){
        for(int j = 1; j<= n-i; j++){
            cout << str.substr(i, j) << endl;
        }
    }
}

int main() {
    string str = "Ayush";
    // int length = strlen(str); // Use strlen to get the length of the character array
    substring(str, str.length());
    return 0;
}
