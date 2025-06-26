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

void solve(){
    ll n, w;
    cin >> n >> w;
    vector<pii> sack(n);
    for(auto &[a, b] : sack)cin >> a >> b;
    vvi dp(n + 1, vi(w+1));

    for(ll i = 0; i <= n - 1; i++){
        for(ll j = 0; j <= w; j++){
            if (j + sack[i].f > w){
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);   
                continue;
            }
            dp[i + 1][j + sack[i].f] = max(dp[i + 1][j + sack[i].f], dp[i][j] + sack[i].s);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    // // cout << dp[1][] << endl;
    // for(ll i = 0; i <= n; i++){
    //     for(ll j = 0; j <= w; j++){
    //         cout << dp[i][j] << " "
    //     ;}
    //     cout << '\n';
    // }
    cout << dp[n][w];
}
//0 off case :smh:

int main(){
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}

