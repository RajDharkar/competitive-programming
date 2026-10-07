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
       ll n;
       cin >> n;
       vector<ll> a(n);
       vector<ll> b(n);
       for(auto &x : a)cin >> x;
       for(auto &x : b)cin >> x;

        // vector<int> pref(i + 1);
        // for(int i = 0; i < n; i++){
        //     pref[i + 1] = pref[i] + a[i] + b[i];
        // }

        ll current = 0;
        ll ans = 0;

        for(ll i = n - 2; i >= 0; i--){
            current += (a[i] == b[i + 1]) - (a[i] == b[i]);
            ans = max(ans, current);
        }

       for(ll i = 0; i < n; i++){
            ans += (a[i] == b[i]) + 1;
            if(i + 1 < n){
                ans += (a[i + 1] == b[i]) + 1;
            }
       }

       cout << ans << '\n';
    }
}