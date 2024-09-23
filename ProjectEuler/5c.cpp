#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ll n = 1e8;

    vector<bool> visited(n, false);
    ll tot = 0;
    
    for (int i = 2; i <= n; i++) {
        cout << i << endl;
        if (visited[i - 2]) {
            continue;
        }

        if (2 * i > n) {
            tot += 3;
            visited[i - 2] = true;
        } else {
            ll cur = 2;
            while (i * cur <= n) {
                if (cur > 2) {
                    if (visited[i * cur - 2]) {
                        cur++;
                        continue;
                    } else {
                        tot += 2;
                        visited[i * cur - 2] = true;
                        cur++;
                    }
                } else {
                    tot += 2;
                    visited[i * cur - 2] = true;
                    cur++;
                }
            }
        }
    }
    
    cout << tot << endl;
    return 0;
}
