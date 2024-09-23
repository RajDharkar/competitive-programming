#include <iostream>
#include <vector>

const int MOD = 1000000007;

// Function to perform modular exponentiation
int mod_pow(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (1LL * result * base) % mod;
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Precompute factorials and their modular inverses
void precompute_factorials(int max_n, std::vector<int>& fact, std::vector<int>& inv_fact) {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= max_n; ++i) {
        fact[i] = (1LL * fact[i-1] * i) % MOD;
    }
    inv_fact[max_n] = mod_pow(fact[max_n], MOD - 2, MOD); // Fermat's little theorem
    for (int i = max_n - 1; i >= 1; --i) {
        inv_fact[i] = (1LL * inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

// Function to calculate nCr % MOD
int nCr(int n, int r, const std::vector<int>& fact, const std::vector<int>& inv_fact) {
    if (r > n || r < 0) return 0;
    return (1LL * fact[n] * inv_fact[r] % MOD) * inv_fact[n - r] % MOD;
}

// Function to calculate F(N, X) using Inclusion-Exclusion Principle
int calculate_F(int N, int X) {
    std::vector<int> fact(N + 1), inv_fact(N + 1);
    
    // Precompute factorials and their inverses
    precompute_factorials(N, fact, inv_fact);
    
    // Number of valid assignments using Inclusion-Exclusion Principle
    int valid_ways = 0;
    for (int i = 0; i <= X; ++i) {
        int sign = (i % 2 == 0) ? 1 : -1;
        int term = (1LL * nCr(X, i, fact, inv_fact) * mod_pow(X - i, N, MOD)) % MOD;
        valid_ways = (valid_ways + sign * term + MOD) % MOD;
    }
    
    // Total number of subsets (2^N)
    int total_subsets = mod_pow(2, N, MOD);
    
    // The probability is the ratio of valid_ways to total_subsets
    int P = valid_ways;
    int Q = total_subsets;
    int Q_inv = mod_pow(Q, MOD - 2, MOD); // Modular inverse of Q
    
    int result = (1LL * P * Q_inv) % MOD;
    
    return result;
}

int main() {
    int N = 101;
    int X = 101;
    
    std::cout << "Starting calculation for F(" << N << ", " << X << ")." << std::endl;
    int result = calculate_F(N, X);
    std::cout << "The result is: " << result << std::endl;

    return 0;
}
