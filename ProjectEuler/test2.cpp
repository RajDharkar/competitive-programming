#include <iostream>
#include <vector>

using namespace std;

// Function to compute F(N, K) using an iterative approach
int compute_F(int N, int K) {
    int operations = 0;
    while (N > 0) {
        if (K == 1) {
            // If K is 1, we can only subtract 1
            operations += N;
            N = 0;
        } else if (N % K == 0) {
            // If N is divisible by K, perform division
            N /= K;
            operations++;
        } else {
            // If not divisible, subtract the remainder to make it divisible by K
            int remainder = N % K;
            N -= remainder;
            operations += remainder;
        }
    }
    return operations;
}

// Function to compute G(N)
long long compute_G(int N) {
    long long total_sum = 0;

    for (int K = 1; K <= N; ++K) {
        total_sum += compute_F(N, K);
        if (K % 1000 == 0) {
            cout << "K = " << K << ", current sum = " << total_sum << endl;
        }
    }

    return total_sum;
}

int main() {
    const int N = 13; // 10^7
    long long result = compute_G(N);
    cout << "G(" << N << ") = " << result << endl;
    return 0;
}
