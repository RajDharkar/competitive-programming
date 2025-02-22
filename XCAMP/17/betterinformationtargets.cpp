#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--; 
    }

    ll ans = 1e9;
    vector<bool> visited(n, false);

    for (int x = 0; x < n; x++) {
        if (visited[x]) continue;

        ll a = arr[x], b = arr[arr[x]];
        while (a != b) {
            a = arr[a];     
            b = arr[arr[b]]; 
        }

        a = x;
        while (a != b) {
            a = arr[a];
            b = arr[b];
        }

        ll first = a; 
        ll len = 1;
        b = arr[first];
        while (b != first) {
            b = arr[b];
            len++;
        }

        ans = min(ans, len);
        ll v = first;
        while (!visited[v]) {
            visited[v] =1;
            v = arr[v];
        }
    }
    cout << ans << endl;
}
