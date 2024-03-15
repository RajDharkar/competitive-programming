#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n; 

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> sorted(arr); // Copy arr to sorted
    sort(sorted.begin(), sorted.end());

    ll t = 0;
    for(int i = 0; i < n; i++) {
        t += (i + 1) * sorted[i];
    }

    vector<int> prefix(n + 1);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + sorted[i-1];
    }

    int q;
    cin >> q;
    cout << t << endl;

    vector<int> pos(n); // Store positions of elements in sorted array
    for(int i = 0; i < n; i++) {
        pos[i] = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
    }

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        a = pos[a];

        ll ans = t - (a + 1) * arr[a];

        int newPos = lower_bound(sorted.begin(), sorted.end(), b) - sorted.begin();

        if (newPos >= a) {
            ans -= prefix[newPos + 1] - prefix[a + 1];
        } else {
            ans += prefix[a] - prefix[newPos];
        }

        ans += (newPos + 1) * b;

        cout << ans << '\n';
    }

    return 0;
}
