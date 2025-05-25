#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);  

typedef long long ll;
typedef pair<ll, ll> pii;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second
#define vi vector<ll>
#define vvi vector<vi>
#define res(x, n) (x).resize(n)

const ll MOD = 1e9+7;
vi fact;
vi inv;
ll bexp(ll a, ll b){
    ll ret = 1;
    while(b > 0){
        if(b & 1)ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1; 
    }
    return ret;
}

ll comb(ll a, ll b){
    return fact[a] * inv[b] % MOD * inv[a - b] % MOD;
}

int main(){
    ll n, k;
    ll t = n;
    cin >> n >> k;
    vi arr(k);
    res(fact, n+1);
    res(inv, n+1);
    fact[0] = 1;
    for(ll i = 1; i <= n; i++){
        fact[i] = fact[i-1] * i % MOD;
    }
    inv[n] = bexp(fact[n], MOD - 2);
	for (ll i = n; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD;}
    for(auto &x : arr)cin >> x;

    vector<vi> dp(k+1, vi(n+1));
    dp[0][0] = 1;
    for(ll i = 1; i <= k; i++){
        ll x = arr[i-1];
        for(ll j = 0; j <= n; j++){
            if(dp[i-1][j] == 0) continue;
            for(ll h = 0; h <= min(x, n - j); h++){
                if(x - h > n - h) continue;
                ll ways = comb(n - h, x - h);
                ways = ways * inv[h] % MOD;
                dp[i][j + h] = (dp[i][j + h] + dp[i-1][j] * ways) % MOD;
            }
        }
    }

    cout << dp[k][n] * fact[n] % MOD;
}