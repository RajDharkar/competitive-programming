#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second
const ll MAX_BITS = 60;
const ll MOD = 998244353;
ll L, R, V;
ll dp[MAX_BITS][2][2][2][2][2][2];
bool vis[MAX_BITS][2][2][2][2][2][2];

//after 5 hours of attempting to do iterative(not a joke) -> i caved and just found a recursive solution.
ll calc(ll b,ll lf0,ll lf1,ll rf0,ll rf1,ll xf0,ll xf1){
	if(b==60){
		return (lf0&&lf1&&rf0&&rf1);
	}

	if(vis[b][lf0][lf1][rf0][rf1][xf0][xf1])return dp[b][lf0][lf1][rf0][rf1][xf0][xf1];
	
    vis[b][lf0][lf1][rf0][rf1][xf0][xf1] = 1LL;
	
    ll ret = 0;
	for(ll i = 0;i < 2; i++){
		for(ll j = 0; j < 2; j++){
			ll t = 0;
			t ^= (i*xf0);
			t ^= (j*xf1);
			if(t != ((V>>b)&1))continue;
			ll nlf0 = lf0,nlf1 = lf1,nrf0 = rf0,nrf1 = rf1;
			if(((L>>b)&1)>i) nlf0 = 0;
			if(((L>>b)&1)<i) nlf0 = 1;
			if(((L>>b)&1)>j) nlf1 = 0;
			if(((L>>b)&1)<j) nlf1 = 1;
			if(((R>>b)&1)<i) nrf0 = 0;
			if(((R>>b)&1)>i) nrf0 = 1;
			if(((R>>b)&1)<j) nrf1 = 0;
			if(((R>>b)&1)>j) nrf1 = 1;
			ret += calc(b+1, nlf0, nlf1, nrf0, nrf1, xf0, xf1);
            if(ret >= MOD) ret -= MOD;
		}
	}
	dp[b][lf0][lf1][rf0][rf1][xf0][xf1] = ret;
	return ret;
}

int main(){
    // int t; cin >> t; while(t--){
    cin >> L >> R >> V;
    L--;
    // ans %= MOD;
    ll ans = 0;
    for(ll i = 0; i < 4; i++){
        for(ll j=0;j<4;++j){
            ll t = 0;
            for(ll k = 0; k <= i; ++k) t ^= k;
            for(ll k = 0; k <= j; ++k) t ^= k; 
            if(t != (V & 3)) continue;

            ll r0 = (i <= (R & 3));
            ll l0 = (i >= (L & 3));
            ll r1 = (j <= (R & 3));
            ll l1 = (j >= (L & 3));

            ll x0 = i % 2 == 0;
            ll x1 = j % 2 == 0;

            ll x = calc(2,l0,l1,r0,r1,x0,x1);
            // cout << x << '\n';
            ans += x;
            if(ans >= MOD) ans -= MOD;
        }
    }
    if(V==0){   
        // if(L != 10 && R != 20)assert(1 != 0);
        ans = (ans + MOD - ((R - L + 1) % MOD)) % MOD;

    }
    ans = ans * ((MOD + 1LL) / 2LL) % MOD; 
    // ans = ans * ((MOD + 1) / 2) % MOD; 
    // ans = (ans + MOD) % MOD;
    cout << ans << '\n';
    // }
}