#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define MOD 998244353LL

const ll mx = 1e6 + 10;

ll fac[mx+1];
ll inv[mx+1];

ll binexp(ll a, ll b){
    if(a==0)return 0;
    ll ret = 1;
    while(b>0){
        if(b%2 == 1){
            ret *= a;
            ret %= MOD;
        }
        b/=2;
        a*=a;
        a %= MOD;
    }
    return ret;
}

ll choose(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

void solve(){
    ll a,b, c, d;
    cin >> a >> b >> c >> d;

    if (a < 2 || a + d != b + c + 1) {
        cout << 0 << '\n';
        return;
    }
    if(b + c - 1 < 0 || a - 2 < 0 || a - 2 > b + c - 1){
        cout << 0 << '\n';
        return;
    }
    ll x = choose(b + c - 1, a - 2);
    ll y = choose(b + c, b);
    
    cout << (x % MOD) * (y % MOD) % MOD << '\n';
}

int main(){
	fac[0] = 1;

	for(ll i = 1; i <= mx; i++) {
        fac[i] = fac[i - 1] * i % MOD; 
    }
    
    inv[mx] = binexp(fac[mx], MOD - 2);

	for (ll i = mx; i >= 1; i--) {
        inv[i - 1] = inv[i] * i % MOD;
    }

    int t;cin >> t;
    while(t--){
        solve();
    }
}

