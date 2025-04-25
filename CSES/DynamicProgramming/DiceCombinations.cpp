#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define MOD 1000000007

ll dp[1000001];
int main(){
    ll n; cin >> n;
    
    dp[0] = 1;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= 6; j++){
            if(i - j < 0)break;
            (dp[i] += dp[i-j]) %= MOD;
        }
        dp[i] %= MOD;
        // dp[i]++;
    }
    cout << dp[n];
}
