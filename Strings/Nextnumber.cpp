#include<iostream>
#include<string>
using namespace std;


string Nextnumber(string str){
    int l = str.length();
    int i;
    for(i=l-1; i >=0; i--){
        if(str[i] == '0'){
            str[i] = '1';
            break;
        }else{
            str[i] == '0';
        }
    }
    if(i < 0){
        str = "1" + str ;
    }
    return str;
}

int main(){
    string str = "10011";
    cout << Nextnumber(str) ;
    return 0;
}