#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

long long calculate_value(const vector<int>& x) {
    long long total = 0;
    for (int i = 0; i < x.size(); ++i) {
        total += x[i] * pow(26, x.size() - 1 - i);
    }
    return total;
}

int main() {
    int n;
    cin >> n;

    vector<char> input_string(n);
    for (int i = 0; i < n; ++i) {
        cin >> input_string[i];
    }

    vector<int> input_values(n);
    for (int i = 0; i < n; ++i) {
        input_values[i] = alphabet[input_string[i] - 'A'];
    }

    vector<int> score_list(n, 0);
    for (int len = 1; len <= n; ++len) {
        unordered_set<long long> seen;
        long long hash_val = 0;
        for (int i = 0; i < len; ++i) {
            hash_val = hash_val * 26 + input_values[i];
        }
        seen.insert(hash_val);
        ++score_list[seen.size() - 1];

        for (int i = len; i < n; ++i) {
            hash_val = (hash_val - input_values[i - len] * pow(26, len - 1)) * 26 + input_values[i];
            seen.insert(hash_val);
            ++score_list[seen.size() - 1];
        }
    }

    for (int i = 0; i < score_list.size(); ++i) {
        cout << score_list[i] << endl;
    }

    return 0;
}
