#include<iostream>
#include<string>
using namespace std;

string addBinaryUtil(string a, string b){
    string result = "";
    int s = 0;

    int i = a.size() - 1, j = b.size() - 1;
    while(i>= 1 || j>=1 || s==1){
        s += ((i >= 0) ? a[i] - '0' : 0);
        s += ((j >= 0) ? b[j] - '0' : 0);

        result = char(s % 2 + '0') + result;
        s /= 2;
        i--;
        j--;
    }
    return result;

}

string addBinary(string arr[], int n)
{
    string result = "";
    for (int i = 0; i < n; i++)
        result = addBinaryUtil(result, arr[i]);
    return result;
}

int main(){
    string arr[] = { "1", "10", "11" };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << addBinary(arr, n) << endl;
    return 0;
}