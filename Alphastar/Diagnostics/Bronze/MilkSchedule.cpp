#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

int main() {
    int n, m;
    cin >> n >> m;
    int psum[n+1];
    psum[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> psum[i];
        psum[i]+=psum[i-1];
    }
    // for(int i = 0; i < n+1; i++){
    //     cout << psum[i] << " ";
    // }
    cout << endl;
    while (m--) {
        ll t;
        cin >> t;

        // Binary search to find the cow being milked at time t
        int left = 0, right = n - 1, result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (psum[mid] <= t) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Output the cow index
        cout << result + 1 << endl;
    }
    // for(int i = 0; i < m; i++){
    //     int a;
    //     cin >> a;
    //     //cout << lower_bound(psum, psum + n, a);
    //     int ans = distance(psum, lower_bound(psum, psum + n, a));
    //     cout << ans << endl;
    // }

}
