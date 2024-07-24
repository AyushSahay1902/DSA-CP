#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N < 1 || N > 100) {
        cout << "Invalid input. Please enter a number between 1 and 100." << endl;
        return 1;
    }

    // Convert the number to binary using bitset
    bitset<7> binary(N); // bitset<7> to handle up to 100 (which is within 7 bits)

    // Find the position of the most significant bit
    int msbIndex = 6; // Since we are using 7 bits, start from the highest index
    while (msbIndex >= 0 && !binary[msbIndex]) {
        msbIndex--;
    }

    // Toggle all bits from the most significant bit to the least significant bit
    for (int i = msbIndex; i >= 0; i--) {
        binary.flip(i);
    }

    // Convert the toggled binary back to an integer
    int toggledNumber = binary.to_ulong();

    // Output the result
    cout << toggledNumber << endl;

    return 0;
}
