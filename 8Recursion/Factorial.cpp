#include <iostream>
#include <vector>
using namespace std;

//Smallest Number with at least n trailing zeroes in factorial

// int main() {
//     int n;
//     cin >> n;
//     int low = 0, high = 5*n;
//     while(low < high) {
//         int mid = low + (high - low) / 2;
//         int count = 0;
//         for(int i = 5; mid / i >= 1; i *= 5) {
//             count += mid / i;
//         }
//         if(count < n) {
//             low = mid + 1;
//         } else {
//             high = mid;
//         }
//     }
//     cout << low;
//     return 0;
// }



//Approach 2
int countTrailingZeros(int n) {
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int low = 0, high = 5 * n;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int numOfZeros = countTrailingZeros(mid);

        if (numOfZeros >= n) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}
