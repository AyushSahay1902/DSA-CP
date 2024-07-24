/*
Train Timings Calculation
Train A starts from the source station at time T[0], halts at each station for h units of time until it reaches the last 
station at time T[N-1], where N is the total number of stations. The timings of Train A at each station are given as 
T[] = {10.00, 10.04, 10.09, 10.15, 10.19, 10.22}.

Railway Admin wants to add Train B with the same station timings but starting at a different time t. The task is to 
compute the timings for Train B at each station. The program should return a string array S (timestamps in float)
for Train B at each station from the first to the last station like Train A.
Input
A single float value representing the start time t for Train B.
Output
A string representing the timings of Train B at each station, separated by spaces.
If the input time is invalid, print "Invalid Input".
Example
Input:

11.00
Output:

11.00 11.04 11.09 11.15 11.19 11.22
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
    float t;
    cin >> t;
    if(t < 0 || t > 24) {
        cout << "Invalid Input";
        return 0;
    }
    vector<float> T = {10.00, 10.04, 10.09, 10.15, 10.19, 10.22};
    vector<float> B;
    for(int i = 0; i < T.size(); i++) {
        B.push_back(T[i] + t - T[0]);
    }
    for(int i = 0; i < B.size(); i++) {
        cout << fixed << setprecision(2) << B[i] << " ";
    }
    return 0;
}