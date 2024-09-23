#include <iostream>

const int MOD = 1000000007;
const long long PHI_MOD = MOD - 1; // For a prime MOD, phi(MOD) = MOD - 1

// Function to perform modular exponentiation
// It returns (base^exp) % mod
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod; // Handle base > mod

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1; // Equivalent to exp / 2
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long exp = 10000000000000000000LL; // 2 ^ (10^16)
    long long reduced_exp = exp % PHI_MOD; // Reduce exponent mod PHI_MOD

    long long result = mod_exp(2, reduced_exp, MOD);
    std::cout << "2^(" << exp << ") % " << MOD << " = " << result << std::endl;
    return 0;
}
