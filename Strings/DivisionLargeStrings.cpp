#include<iostream>
#include<string>
using namespace std;

string longDivision(string number, int divisor){
    string ans;
    int idx = 0; 
    int x = number[idx] - '0';
    
    while(idx < (number.size() - 1) && x < divisor){
        x = x * 10 + (number[++idx] - '0');
    }
    
    while ((number.size() - 1) > idx) {
        // Store result in answer i.e. temp / divisor
        ans += (x / divisor) + '0';
 
        // Take next digit of number
        x = (x % divisor) * 10 + number[++idx] - '0';
    }
 
    // If divisor is greater than number
    if (ans.length() == 0)
        return "0";
 
    // else return ans
    return ans;
}

int main(){
    string number = "1234432223221212334253";
    int divisor = 121;
    cout << longDivision(number, divisor);
    return 0;
}
