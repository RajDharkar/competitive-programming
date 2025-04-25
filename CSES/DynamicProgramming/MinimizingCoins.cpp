#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

ll dp[1000001];

int main(){
    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for(auto &k : coins)cin >> k;
    fill(dp, dp + 1000001, 1000000000LL);
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(auto coin : coins){
            if(i - coin < 0)continue;
            if(dp[i - coin] != 1000000000LL){
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
    }
    // for(int i = 0; i <= x; i++)cout << dp[i] << " \n"[i == x];
    cout << (dp[x] == 1000000000LL ? -1 : dp[x]);
}

