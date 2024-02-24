// #include <iostream>
// #include <string> 
// using namespace std;

// int main() {
//     string str = "Ayush_Sahay is GeeksforGeeks is a computer science portal";
//     for(int i=str.length()-1; i>=0; i--){
//         cout << str[i];
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
 
// int main()
// {
//     string str = "geeksforgeeks"; // Input string
//     reverse(str.begin(),str.end()); // Reverse the string
//     cout << str << std::endl;
//     return 0;
// }    

void recursiveReverse(string &str, int i=0){
    int n = str.length();
    if(i == n/2){
        return;
    }
    swap(str[i], str[n-i-1]);
    recursiveReverse(str, i+1);
}
int main() {
    string str = "Ayush_Sahay is GeeksforGeeks is a computer science portal";
    recursiveReverse(str);
    cout << str;
    return 0;
}
//We can also reverse using two-pointers approach and stack data structure.