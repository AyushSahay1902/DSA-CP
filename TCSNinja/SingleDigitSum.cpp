#include <iostream>
using namespace std;

int main() {
    int N, R;
    cin >> N >> R; 

    if(R == 0) {
        return 0;
    }

    int sum = 0;
    string N_str = to_string(N);
    for(int i=0; i<N_str.size(); i++) {
        sum += N_str[i] - '0';
    }
    int result = sum * R;

    while(result > 9) {
        int temp = result;
        sum = 0;
        while(temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        result = sum;
    }
    cout << result << endl;

    return 0;
}