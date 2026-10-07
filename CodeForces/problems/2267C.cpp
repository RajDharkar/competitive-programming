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
        ll n, x;
        cin >> n >> x;
        vector<ll> arr(n);
        for(auto &j : arr)cin >> j;
        
        vector<ll> p; int x2 = x;
        for(ll i = 2; i * i <= x; i++){
            while(x2 % i == 0){
                p.pb(i);
                x2/=i;
            }
        }
        if(x2 > 1)p.pb(x2);
        p.erase(unique(all(p)), p.end());
        
        ll ans = 0;
        ll sum = 0;
        for(ll k : p){
            sum = 0;
            for(ll i= 0; i<n; i++){
                if(arr[i] % k == 0){
                    sum += arr[i];
                }
            }
            ans = max(ans, sum);
        }
        cout << ans << '\n';
        
    }
}