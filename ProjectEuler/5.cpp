#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define MAX_N 1000

// Function to calculate the number of recursive calls to GCD
int gcdCallCount(int a, int b) {
    int count = 0;
    while (b != 0) {
        count++;
        int temp = b;
        b = a % b;
        a = temp;
    }
    return count;
}

int main() {
    // A hash map to store the number of GCD calls for each pair (i, j)
    unordered_map<long long, int> gcdCallTable;

    // Precompute GCD call counts for pairs (i, j) where 1 <= j < i <= 10^9
    for (int i = 2; i <= MAX_N; i++) {
        for (int j = 1; j < i; j++) {
            int callCount = gcdCallCount(i, j);
            gcdCallTable[static_cast<long long>(i) * MAX_N + j] = callCount;
        }
    }

    // Example query for GCD(11, 7)
    int a = 11, b = 7;
    long long key = static_cast<long long>(a) * MAX_N + b;
    cout << "Number of calls to GCD for (" << a << ", " << b << ") = " << 1 + gcdCallTable[key] << endl;

    return 0;
}
