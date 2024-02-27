#include<iostream>
#include<string>
using namespace std;

void searchPattern(string pat, string txt){
    int m = pat.size();
    int n = txt.size();

    //Brute force approach 
    for(int i=0; i<=n-m; i++){
        int j;
        for(j=0; j<m; j++){
            if(txt[i + j] != pat[j]) break;
        }
        if(j == m)
        cout << "Pattern found at index: " << i << endl;
    }
}

int main(){
    string txt = "AABAACAADAABAAABAA";
    string pat = "AABA";

    searchPattern(pat, txt);
    return 0;
}

//Time Complexiety - O(N^2)
//Space - Complex - O(1)
//KMP Algorithm - O(n+m)