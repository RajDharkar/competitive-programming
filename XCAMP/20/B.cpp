#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
// ll mod = 50033;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (auto& x : arr) { 
            cin >> x; 
        }
        vector<ll> dp(25005, 0);
        dp[0] = 1;
        for (ll i = 1; i < 25005; i++) {
            for (ll j = 0; j < n; j++) {
                if (i - arr[j] >= 0) {
                    dp[i] += dp[(i - arr[j])];
                }
            }
        }

        ll ans = 0;
        for(ll i = 0; i < n; i++){
            if(dp[arr[i]] == 1){
                ans++;
            }
        }
        cout << ans << endl;
    }
}
