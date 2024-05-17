#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string encode(char c, vector<int>& arr) {
    string ans = "{";
    ans += c;
    ans += ":";
    for (int i = 0; i < arr.size(); i++) {
        ans += to_string(arr[i]);
        if (i < arr.size() - 1) {
            ans += ",";
        }
    }
    ans += "}";
    return ans;
}

string solve(vector<double>& arr) {
    int N = arr.size();
    vector<string> alg;
    vector<int> cV;
    char current_type = 'd';

    // Check if sequence contains only zeros
    bool all_zeros = true;
    for (int i = 0; i < N; ++i) {
        if (arr[i] != 0.0) {
            all_zeros = false;
            break;
        }
    }
    if (all_zeros) {
        cV.reserve(N);
        for (int i = 1; i <= N; ++i) {
            cV.push_back(i);
        }
        return encode('d', cV);
    }

    // Process non-zero elements
    for (int i = 0; i < N; ++i) {
        cV.push_back(i + 1); // Convert to 1-indexing
        if (current_type == 'd') {
            if (arr[i] == INFINITY) {
                alg.push_back(encode('d', cV));
                cV.clear();
                continue;
            } else if (abs(arr[i]) <= pow(2, -14) * pow(2, -1022)) {  // Check for underflow
                current_type = 'h';  // Switch to half precision
            }
        } else if (current_type == 'h') {
            if (arr[i] == INFINITY || abs(arr[i]) > pow(2, 16)) {  // Check for overflow
                alg.push_back(encode('h', cV));
                cV.clear();
                current_type = 'd';  // Switch back to double precision
            }
        }
    }

    // Append the last algorithm if there are remaining values
    if (!cV.empty()) {
        alg.push_back(encode(current_type, cV));
    }

    return "" + alg[0]; // Joining with '+' to represent summation
}

int main() {
    int N;
    cin >> N;
    vector<double> sequence(N);
    for (int i = 0; i < N; ++i) {
        cin >> sequence[i]; 
    }
    string sol = solve(sequence);
    cout << sol << endl;
    return 0;
}
