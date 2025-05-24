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
ll dp[MAX_BITS + 1][2][2][2][2][2][2];
const ll MOD = 998244353;
ll L, R, V;
ll calc(ll bitStart, ll l0, ll l1, ll r0, ll r1, ll x0, ll x1) {
    memset(dp, 0, sizeof(dp));

    // Base case: if all bounds are free at the end
    for (int lf0 = 0; lf0 < 2; ++lf0)
    for (int lf1 = 0; lf1 < 2; ++lf1)
    for (int rf0 = 0; rf0 < 2; ++rf0)
    for (int rf1 = 0; rf1 < 2; ++rf1)
        dp[MAX_BITS][lf0][lf1][rf0][rf1][x0][x1] = (lf0 && lf1 && rf0 && rf1);

    for (ll b = MAX_BITS - 1; b >= bitStart; --b) {
        ll vBit = (V >> b) & 1;
        ll lBit = (L >> b) & 1;
        ll rBit = (R >> b) & 1;

        for (ll lf0 = 0; lf0 < 2; ++lf0)
        for (ll lf1 = 0; lf1 < 2; ++lf1)
        for (ll rf0 = 0; rf0 < 2; ++rf0)
        for (ll rf1 = 0; rf1 < 2; ++rf1) {
            ll &cur = dp[b][lf0][lf1][rf0][rf1][x0][x1];
            cur = 0;

            for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j) {
                if (((i * x0) ^ (j * x1)) != vBit) continue;

                ll nlf0 = lf0, nlf1 = lf1, nrf0 = rf0, nrf1 = rf1;

                if (!lf0 && lBit > i) continue;
                if (!lf1 && lBit > j) continue;
                if (!rf0 && rBit < i) continue;
                if (!rf1 && rBit < j) continue;

                if (!lf0 && lBit < i) nlf0 = 1;
                if (!lf1 && lBit < j) nlf1 = 1;
                if (!rf0 && rBit > i) nrf0 = 1;
                if (!rf1 && rBit > j) nrf1 = 1;

                cur = (cur + dp[b + 1][nlf0][nlf1][nrf0][nrf1][x0][x1]);
            }
        }
    }

    return dp[bitStart][l0][l1][r0][r1][x0][x1];
}



int main(){
    cin >> L >> R >> V;
    L--;
    // ans %= MOD;
    ll ans = 0;
    for(ll i = 0; i < 4; i++){
        for(int j=0;j<4;++j){
            int t = 0;
            for(int k = 0; k <= i; ++k) t ^= k;
            for(int k = 0; k <= j; ++k) t ^= k; 
            if(t != (V & 3)) continue;

            int r0 = (i <= (R & 3));
            int l0 = (i >= (L & 3));
            int r1 = (j <= (R & 3));
            int l1 = (j >= (L & 3));

            int x0 = (i % 2 == 0);
            int x1 = (j % 2 == 0);

            int x = calc(2,l0,l1,r0,r1,x0,x1);
            cout << x << '\n';
            ans += x;
            if(ans >= MOD) ans -= MOD;
        }
    }
        if(V==0){   
            ans = (ans - (R - L + 2) + MOD) % MOD;  
        }
        ans = ans * ((MOD + 1) / 2) % MOD; 
    // ans = ans * ((MOD + 1) / 2) % MOD; 
    // ans = (ans + MOD) % MOD;
    cout << ans << '\n';
}