/*
vechicle finding
An automobile company manufactures both a two wheeler (TW) and a four wheeler (FW). A company manager wants to make the production of both types of vehicle according to the given data below:

1st data, Total number of vehicle (two-wheeler + four-wheeler)=v 2nd data, 
Total number of wheels = W The task is to find how many two-wheelers as well as four-wheelers
need to manufacture as per the given data.

Constraints :

2<=W W%2=0 V<W Print “INVALID INPUT” , if inputs did not meet the constraints.

The input format for testing The candidate has to write the code to accept two positive numbers separated by a new line.

First Input line – Accept value of V. Second Input line- Accept value for W. The output format for testing
Example
Input:

200 -> Value of V 540 -> Value of W
Output:

130 
70

*/
#include <iostream>
using namespace std;

int main() {
    int v, w;
    cin >> v >> w;

    // Check for invalid input conditions
    if (w % 2 != 0 || v < 0 || w < 0) {
        cout << "INVALID INPUT" << endl;
        return 0;
    }

    int tw = 0, fw = 0;
    
    // Using the equations:
    // v = tw + fw
    // w = 2*tw + 4*fw

    // Solve the equations:
    // w = 2*tw + 4*fw
    // => fw = (w - 2*tw) / 4
    // v = tw + fw
    // => fw = v - tw
    // => (w - 2*tw) / 4 = v - tw
    // => w - 2*tw = 4*(v - tw)
    // => w - 2*tw = 4*v - 4*tw
    // => w = 4*v - 2*tw
    // => 2*tw = 4*v - w
    // => tw = (4*v - w) / 2
    // => fw = v - tw

    tw = (4 * v - w) / 2;
    fw = v - tw;

    // Check if the computed values are valid
    if (tw < 0 || fw < 0 || (2 * tw + 4 * fw != w)) {
        cout << "INVALID INPUT" << endl;
    } else {
        cout << tw << endl << fw << endl;
    }

    return 0;
}


// ----------------------------------------------------------
// #include <iostream>
// #include <cmath>
// using namespace std;

// int main(){
//     int N;
//     cin >> N;
//     int arr[N];
//     for(int i = 0; i < N; i++){
//         cin >> arr[i];
//     }

//     int max = arr[0];
//     int cnt = 1;
//     for(int i = 1; i < N; i++){
//         if(arr[i] > max){
//             max = arr[i];
//             cnt++;
//         }
//     }
//     cout << cnt;

//     return 0;
// }