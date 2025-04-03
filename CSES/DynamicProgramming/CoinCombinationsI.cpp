#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

ll dp[1000001];

int main(){
    ll mod = 1e9+7;
    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for(auto &k : coins)cin >> k;
    fill(dp, dp + 1000001, 0LL);
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(auto coin : coins){
            if(i - coin < 0)continue;
            if(dp[i - coin] != 0LL){
                (++dp[i]) %= mod;
            }
        }
    }
    // for(int i = 0; i <= x; i++)cout << dp[i] << " \n"[i == x];
    cout << (dp[x] == 0LL ? 0 : dp[x]%mod);
}

