#include<iostream>
#include<string>
using namespace std;

bool CanMakeALlSame(string str){
    int zeros = 0, ones = 0;
    for(char ch : str) (ch == '0') ? ++zeros : ++ones ;

    return(zeros == 1 || ones == 1);
}


int main(){
    CanMakeALlSame("101") ? printf("Yes\n") : printf("Nope\n") ;
    CanMakeALlSame("111") ? printf("Yes\n") : printf("Nope\n") ;
    CanMakeALlSame("0") ? printf("Yes\n") : printf("Nope\n") ;
    return 0;
}