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
    for(auto coin : coins){
        for(int i = 0; i <= x; i++){
            if(i - coin >= 0)dp[i] += dp[i - coin];
            dp[i] %= mod;
        }
    }
    // for(int i = 0; i <= x; i++)cout << dp[i] << " \n"[i == x];
    cout << (dp[x]%mod);
}

