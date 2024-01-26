#include<bits/stdc++.h>
using namespace std;
// void print_hello(){
//     cout<< "Hello world";

// }
// int digit_sum(int n){
//     int digit_sum = 0;
//     while(n){
//         digit_sum = digit_sum + n%10;
//         n = n/10;
//     }
//     return digit_sum;
// }

// int sum(int a,int b){
//     int result = a+b;
//     return result;
// }


// int main(){
//     print_hello();
//     cout<< sum(3,6);
//     // cout<< digit_sum(25);
//     int a,b;
//     cin>> a >> b;
//     cout << digit_sum(44)+digit_sum(55);
//     return 0;

// }
// c++ refrences &a

void func(int a[]){
    a[0]= 5;
}
int main(){
    int a[10];
    cout<< a[0] << endl;
    func(a);
    cout<< a[0] << endl;
}