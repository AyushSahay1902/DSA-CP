/*
count the number of rock samples
John is a geologist, and he needs to count rock samples in order to send them to a chemical laboratory. 
The laboratory only accepts rock samples within specified size ranges in ppm (parts per million). John needs 
your help to determine the number of rock samples within each specified range.

Given an array samples[] representing the sizes of rock samples and a 2D array ranges[] where each sub-array contains
two integers representing the start and end of a range, your task is to count the number of rock samples that fall
within each range.
Input
The first line contains two space-separated integers:
S: the number of rock samples.
R: the number of ranges.
The second line contains S space-separated integers representing the sizes of the rock samples.
The subsequent R lines contain two space-separated integers each, representing the start and end of a range.
Output
R lines where the ith line contains a single non-negative integer indicating the number of samples that lie in the ith range.
Example
Input:

5 3
10 20 30 40 50
15 35
20 50
10 60
Output:

2
4
5   
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int S, R;
    cin >> S >> R;
    vector<int> samples(S);
    for(int i = 0; i < S; i++) {
        cin >> samples[i];
    }
    vector<vector<int>> ranges(R, vector<int>(2));
    for(int i = 0; i < R; i++) {
        cin >> ranges[i][0] >> ranges[i][1];
    }
    vector<int> count(R, 0);
    for(int i = 0; i < S; i++) {
        for(int j = 0; j < R; j++) {
            if(samples[i] >= ranges[j][0] && samples[i] <= ranges[j][1]) {
                count[j]++;
            }
        }
    }
    for(int i = 0; i < R; i++) {
        cout << count[i] << endl;
    }
    return 0;
}