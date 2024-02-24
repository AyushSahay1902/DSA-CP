#include<iostream>
#include<string>
#include<cstring> // Include the cstring header for strlen
using namespace std;

void substring(char str[], int n){
    for(int len = 1; len <= n; len++){
        for(int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            for(int k = i; k <= j; k++){
                cout << str[k];
            }
            cout << endl;
        }
    }
}

int main() {
    char str[] = "AyushGeeks";
    int length = strlen(str); // Use strlen to get the length of the character array
    substring(str, length);
    return 0;
}
