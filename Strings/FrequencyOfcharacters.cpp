#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main() {
     //given string.
     string s = "geeksforgeeks";
     //map char-int pair.
     map<char,int>mp;
     //map over string.
     for(auto it:s)mp[it]++;
     //printing the char with there frequency.
     cout<<"All character in string with there frequency :"         ffffgg<<endl; 
     for(auto it:mp)cout<<it.first<<it.second;
    return 0;
}