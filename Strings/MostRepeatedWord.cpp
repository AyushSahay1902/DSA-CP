#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string MostRepeatedWord(string arr[], int n){
    //Set, hash Map, key value pair likhenge kyya karenge
    unordered_map<string, int> map;
    for(int i=0; i<n; i++){
        if(map.find(arr[i]) != map.end()){
            map[arr[i]]++;
        }else{
            map[arr[i]] = 1;
        }
    }//entry le li bhaiyo map me
    //Finding the maximum repeated word.
    int max_count = 0;
    string res;
    for(auto i: map){
        if(i.second > max_count){
            res = i.first;
            max_count = i.second;
        }
    }
    return res;
}

int main(){
    string arr[] = { "ccc", "aaa", "ccc", "ddd", "aaa", "aaa" };
    int n = sizeof(arr)/ sizeof(arr[0]); //sizeof() - return the total bytes required by the array in memory that why we divide by size of one element to get the length of the array.
    string ans = MostRepeatedWord(arr,n);
    cout << ans << endl;
    return 0;
}