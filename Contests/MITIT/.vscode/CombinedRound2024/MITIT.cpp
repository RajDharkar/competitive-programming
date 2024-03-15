#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    int m;
    cin >> n >> m;

    ll t[n];
    ll a[n];

    for(int i = 0; i < n; i++){
        cin >> t[i] >> a[i]; // Fix: use index i for array a
    }

    ll maxMeet = 0;

    for(int i = 0; i < n; i++){
        ll time = m - a[i];
        time = (time + t[i] - 1) / t[i];
        cout << time << '\n';
        maxMeet = max(maxMeet, time);
    }

    cout << maxMeet;
}
