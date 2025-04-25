#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll brute_force(vector<ll> arr) {
    sort(arr.begin(), arr.end());
    ll n = arr.size();
    ll best = LLONG_MAX;
    for(ll i = 1; i < n; i++) {
        ll diff = arr[i] - arr[i-1];
        vector<ll> temp = arr;
        temp.erase(temp.begin() + i);
        temp.erase(temp.begin() + i - 1);
        ll min2 = LLONG_MAX;
        for(ll j = 1; j < temp.size(); j++) {
            min2 = min(min2, temp[j] - temp[j - 1]);
        }
        best = min(best, diff + min2);
    }
    return best;
}

ll optimized(vector<ll> arr) {
    sort(arr.begin(), arr.end());
    ll n = arr.size();
    ll min1 = 2e9, ind = 0;
    for(ll i=1; i < n; i++) {
        if(arr[i] - arr[i-1] < min1) {
            min1 = arr[i] - arr[i-1];
            ind = i;
        }
    }
    arr.erase(arr.begin() + ind);
    arr.erase(arr.begin() + ind - 1);
    ll min2 = 2e9;
    for(ll i = 1; i < arr.size(); i++) {
        min2 = min(min2, arr[i] - arr[i-1]);
    }
    return min1 + min2;
}

int main() {
    srand(time(0));
    int T = 10000;
    while (T--) {
        int n = rand() % 10 + 4; // Keep it small for brute-force
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1         00;
        }

        ll b = brute_force(arr);
        ll o = optimized(arr);

        if (b != o) {
            cout << "Discrepancy found!\n";
            cout << "Input array: ";
            for (ll x : arr) cout << x << " ";
            cout << "\nBrute-force: " << b << "\nOptimized: " << o << endl;
            break;
        }
    }
    return 0;
}
