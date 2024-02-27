#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string str){
    int l = 0;
    int h = str.size() - 1;

    while(h > l){
        if(str[l++] != str[h--]){
            return false;
        }
    }
    return true;
}

bool isRotativePalindrome(string str){
    if(isPalindrome(str)){
        return true;
    }
    int n = str.length();
    for(int i=0; i<n-1; i++){
        string str1 = str.substr(i+1, n-i-1);
        string str2 = str.substr(0, i+1);

        if(isPalindrome(str1.append(str2))){
            return true;
        }
    }
    return false;
}

int main(){
    cout << isRotativePalindrome("aab") << endl;
    cout << isRotativePalindrome("abcde") << endl;
    cout << isRotativePalindrome("aaaad") << endl;
    return 0;
}

//Optimizatio possible using Manchester Algorithm