#include<bits/stdc++.h>
#include<string>
using namespace std;

void leftRotation(string &str, int d){
    reverse(str.begin(), str.begin()+d);
    //skeeG
    reverse(str.begin()+d, str.end());
    //skeeGroF
    reverse(str.begin(), str.end());
    //skeeGskeeGroF -> ForGeeksGeeks
}
void rightRotation(string &str, int d){
    leftRotation(str, str.length()-d);
}


int main() {
    string str = "GeeksForGeeks";
    rightRotation(str, 2);
    cout << str << endl;

    string str2 = "Ayush_Sahay";
    leftRotation(str2, 2);
    cout << str2 << endl;
}