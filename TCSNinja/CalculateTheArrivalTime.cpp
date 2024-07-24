/*
Calculate the arrival time
You are given an array RS that represents the sequence of railway stations and an array T that represents the travel time in minutes between consecutive stations. RS[0] is the starting station, and RS[d-1] is the final station.

There are n trains starting at RS[0] at different timestamps, represented by a float value indicating the hour value before the decimal point and the minute value after the decimal point (e.g., 11.30 represents 11 hours and 30 minutes).

Given the starting time of a train and a destination station, write a program to calculate the arrival time at the destination station.

Note: The list of valid station names (in order) are: 
StartTime = {7.30f, 8.2f, 12.45f, 13.30f, 14.44f, 15.50f, 9.15f, 10.20f, 23.59f, 17.33f, 19.20f}
JourneyTime = {0,4,5,3,4,5,3}
Place = {"PANVEL", "KHANDESHWAR", "MANSAROVAR", "KHARGHAR", "BELAR", "SEAWOOD", "NERUL"}
Input
The first line of input is a float value representing the starting time of the train.
The second line of input is a string representing the destination station name.
Output
An integer value representing the hour part of the arrival time at the destination station.
Example
Input:

11.20
KHARGHAR
Output:

11
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    float t;
    cin >> t;
    if(t < 0 || t > 24) {
        cout << "Invalid Input";
        return 0;
    }
    vector<float> StartTime = {7.30f, 8.2f, 12.45f, 13.30f, 14.44f, 15.50f, 9.15f, 10.20f, 23.59f, 17.33f, 19.20f};
    vector<int> JourneyTime = {0,4,5,3,4,5,3};
    vector<string> Place = {"PANVEL", "KHANDESHWAR", "MANSAROVAR", "KHARGHAR", "BELAR", "SEAWOOD", "NERUL"};
    string dest;
    cin >> dest;
    int destIndex = -1;
    for(int i = 0; i < Place.size(); i++) {
        if(Place[i] == dest) {
            destIndex = i;
            break;
        }
    }
    if(destIndex == -1) {
        cout << "Invalid Input";
        return 0;
    }
    float arrivalTime = t;
    for(int i = 0; i <= destIndex; i++) {
        arrivalTime += JourneyTime[i];
    }
    cout << (int)arrivalTime;
    return 0;
}