/*
Amount calculation
A doctor has a clinic where he serves his patients. The doctor’s consultation fees are different for different groups of patients, depending on their age. If the patient’s age is below 17, fees is 200 INR. If the patient’s age is between 17 and 40, fees is 400 INR. If the patient's age is above 40, the fee is 300 INR. Write a code to calculate earnings in a day for which one array/List of values representing the age of patients visited on that day is passed as input.

Note:
1. Age should not be zero or less than zero or above 120
Doctor consults a maximum of 20 patients a day
2. Input and Output Format should be same as given in the example.
For any wrong input display INVALID INPUT
Input
A line consists of the “age” (0<age<120) of the patient separated by white space
Output
Print the total amount
Example
Input:

15 22 45 0
Output:

INVALID INPUT
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> age(20);
    int total = 0;
    for (int i = 0; i < 20; i++) {
        cin >> age[i];
        if (age[i] <= 0 || age[i] >= 120) {
            cout << "INVALID INPUT" << endl;
            return 0;
        }
        if (age[i] < 17) {
            total += 200;
        } else if (age[i] >= 17 && age[i] <= 40) {
            total += 400;
        } else {
            total += 300;
        }
    }
    cout << total << endl;
    return 0;
}