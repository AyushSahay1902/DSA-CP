#include<iostream>
#include<string>
using namespace std;

char flip(char ch) {return (ch == '0') ? '1' : '0';}

int getFlipStartingChar(string str, char expected){
    int flipCount = 0;
    for(int i =0; i< str.length(); i++){
        if(str[i] != expected){
            flipCount++;
        }
        expected = flip(expected);
    }
    return flipCount;
}

int minNoOfFlips(string str){
    //Two cases starting with 1 and starting with 0
    return min(getFlipStartingChar(str, '0'),getFlipStartingChar(str, '1'));
}

int main() {
    string str = "00000101011" ;
    cout << minNoOfFlips(str);
    return 0;
}