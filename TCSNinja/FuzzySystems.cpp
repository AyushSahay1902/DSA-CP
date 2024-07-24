/*
Fuzzy System
A washing machine works on the principle of a Fuzzy System, where the weight of clothes put inside it for washing is uncertain. Based on the weight measured by sensors, the machine decides the time and water level required, which can be changed using the menus on the machine control area.

For low level water, the time estimate is 25 minutes if the weight is between 1 and 2000 grams.
For medium level water, the time estimate is 35 minutes if the weight is between 2001 and 4000 grams.
For high level water, the time estimate is 45 minutes if the weight is above 4000 grams.
The capacity of the machine is a maximum of 7000 grams.
If the weight is 0, the time estimate is 0 minutes.
If the weight is above 7000 grams, the output should be "OVERLOADED".
For any other inputs (negative values, non-integer values), the output should be "INVALID INPUT".
Input
The input should be a single integer value representing the weight of the clothes.
Output
The output should be one of the following:
"Time Estimated: <Integer> Minutes"
"OVERLOADED"
"INVALID INPUT"
Example
Input:

2000
Output:

Time Estimated: 25 minutes
*/
#include <iostream>
using namespace std;

int main() {
    int weight;
    cin >> weight;
    if(weight == 0) {
        cout << "Time Estimated: 0 minutes";
    } else if(weight > 0 && weight <= 2000) {
        cout << "Time Estimated: 25 minutes";
    } else if(weight > 2000 && weight <= 4000) {
        cout << "Time Estimated: 35 minutes";
    } else if(weight > 4000 && weight <= 7000) {
        cout << "Time Estimated: 45 minutes";
    } else if(weight > 7000) {
        cout << "OVERLOADED";
    } else {
        cout << "INVALID INPUT";
    }
    return 0;
}