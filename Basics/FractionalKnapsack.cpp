#include <bits/stdc++.h>
using namespace std;

struct Item {
    int profit, weight;

    Item(int profit, int weight) {
        this->profit = profit;
        this->weight = weight;
    }
};

// Comparison function to sort items by profit/weight ratio
static bool cmp(Item a, Item b) {
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int N) {
    // Using greedy approach
    sort(arr, arr + N, cmp);
    double finalResult = 0.0;

    for (int i = 0; i < N; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalResult += arr[i].profit;
        } else {
            finalResult += arr[i].profit * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    return finalResult;
}

int main() {
    // Define the maximum weight capacity of the knapsack
    int W = 50;
    Item arr[] = { {60, 10}, {100, 20}, {120, 30} };
    int N = sizeof(arr) / sizeof(arr[0]);

    // Calculate and display the maximum profit
    cout << "Maximum profit: " << fractionalKnapsack(W, arr, N) << endl;
    return 0;
}