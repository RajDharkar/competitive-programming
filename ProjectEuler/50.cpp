#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to generate primes using the Sieve of Eratosthenes
vector<int> generatePrimes(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Function to check if a number is prime (for larger numbers)
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int max_limit = 1000000;
    vector<int> primes = generatePrimes(max_limit);

    int max_length = 0;
    int prime_with_max_length = 0;

    // Sliding window to find the sum of consecutive primes
    for (size_t i = 0; i < primes.size(); ++i) {
        int current_sum = 0;
        for (size_t j = i; j < primes.size(); ++j) {
            current_sum += primes[j];

            // If the sum exceeds the max limit, break the loop
            if (current_sum >= max_limit) {
                break;
            }

            // Check if the sum is prime and update max_length and prime_with_max_length
            if (isPrime(current_sum) && (j - i + 1) > max_length) {
                max_length = j - i + 1;
                prime_with_max_length = current_sum;
            }
        }
    }

    cout << "Prime below one million with the most consecutive prime sum: " 
         << prime_with_max_length << "\n";
    cout << "Number of consecutive primes: " << max_length << "\n";

    return 0;
}
