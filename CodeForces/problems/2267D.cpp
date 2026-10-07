#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> arr(n), a, b;
        for(auto &x : arr)cin >> x;
        ll l=1;
        ll r = n;
        // ll mx = *max_element(all(arr));
        // vector<ll> index(mx);
        for(ll i = 0; i < n; i++){
            // index[arr[i]] = i;
            if(i % 2)b.pb(arr[i]);
            if(i%2 == 0)a.pb(arr[i]);
        }
        sort(all(a)); sort(all(b));

        ll ans = 1;
        ll i = 0;
        ll j = 0;

        while(i < sz(a) && j < sz(b) && ans){
            ll parity = 0;
            if((j == sz(b)) || (i < sz(a) && a[i] < b[j])) {
                parity = 1;
                i++;
            } else{
                parity = 0; j++;
            }

            if(l % 2 == parity){
                l++;
            }
            else if(r % 2 == parity){
                r--;
            } else{
                ans = 0;
            }
        }
        cout << (ans == 1 ? "YES\n" : "NO\n");
    }
}