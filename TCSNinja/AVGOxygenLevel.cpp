/*
AVG OXYGEN LEVEL
A batch of three trainees is set to appear for a running test on a track, completing three rounds.
After each round, their oxygen levels are recorded. Once the trainees have finished all three rounds,
calculate the average oxygen level for each trainee over the three rounds. The trainee with the 
highest average oxygen level is considered the most fit. If multiple trainees have the same highest 
average level, all of them are selected as the most fit. Display the most fit trainee(s) and their 
highest average oxygen level.
Conditions:
The oxygen value entered should be between 1 and 100.
If the highest average oxygen level among trainees is below 70,
declare all trainees unfit with the message: "All trainees are unfit".
Average oxygen values should be rounded to the nearest integer.
Input
Three lines of input, each containing three integers separated by spaces.
Each integer represents the oxygen level for a trainee after a round.
Output
If there are trainees with the highest average oxygen level, print "Trainee no:" followed by their numbers.

If all trainees are unfit (average oxygen level below 70), print "All trainees are unfit".
Example
Input:

95
92
95
92
90
92
90
92
90
Output:

1
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a1, a2, a3, b1, b2, b3, c1, c2, c3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> c1 >> c2 >> c3;
    int avg1 = round((a1 + a2 + a3) / 3);
    int avg2 = round((b1 + b2 + b3) / 3);
    int avg3 = round((c1 + c2 + c3) / 3);
    if (avg1 >= 70 && avg2 >= 70 && avg3 >= 70) {
        if (avg1 == avg2 && avg2 == avg3) {
            cout << "1\n2\n3";
        } else if (avg1 == avg2) {
            cout << "1\n2";
        } else if (avg2 == avg3) {
            cout << "2\n3";
        } else if (avg1 == avg3) {
            cout << "1\n3";
        } else if (avg1 > avg2 && avg1 > avg3) {
            cout << "1";
        } else if (avg2 > avg1 && avg2 > avg3) {
            cout << "2";
        } else {
            cout << "3";
        }
    } else {
        cout << "All trainees are unfit";
    }
    return 0;
}