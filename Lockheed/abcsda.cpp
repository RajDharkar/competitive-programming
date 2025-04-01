#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

map<char, int> coords; // Maps ADFGVX to grid indices

int main() {
    int t;
    cin >> t;
    while(t--) {
        coords = {{'A', 0}, {'D', 1}, {'F', 2}, {'G', 3}, {'V', 4}, {'X', 5}};
                vector<string> grid(6);
        for(auto &x : grid) cin >> x;

        string key, code;
        cin >> key >> code;

        int n = key.size(); 
        int m = code.size(); // Length of ciphertext

        // Step 1: Determine column order
        string sorted_key = key;
        sort(sorted_key.begin(), sorted_key.end());

        map<char, vector<char>> table;
        int col_sizes[n]; // Size of each column
        int base_size = m / n, extra = m % n;

        for (int i = 0; i < n; i++)
            col_sizes[i] = base_size + (i < extra); // Distribute extra chars

        // Step 2: Fill columns in sorted order
        int idx = 0;
        for (char c : sorted_key) {
            for (int j = 0; j < col_sizes[idx]; j++)
                table[c].push_back(code[j]);
            code = code.substr(col_sizes[idx]); // Remove added chars
            idx++;
        }

        // Step 3: Reconstruct original order
        string reordered_code = "";
        for (int i = 0; i < col_sizes[0]; i++) {
            for (char c : key) {
                if (!table[c].empty()) {
                    reordered_code += table[c].front();
                    table[c].erase(table[c].begin()); // Remove used char
                }
            }
        }

        // Step 4: Convert letter pairs to plaintext
        string plaintext = "";
        for (int i = 0; i < reordered_code.size(); i += 2) {
            int r = coords[reordered_code[i]];
            int c = coords[reordered_code[i + 1]];
            plaintext += grid[r][c];
        }

        cout << plaintext << endl;
    }
}
