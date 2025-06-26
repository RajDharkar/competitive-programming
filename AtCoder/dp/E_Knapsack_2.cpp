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
    vector<pii> items(n);
    for(auto &[a, b] : items)cin >> a >> b;
    vi dp(1e5+1, 1e18);
    dp[0] = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 1e5; j >= 0; j--){
            if(dp[j] + items[i].f <= w){
                // cout << "heioawpr";
                dp[j + items[i].s] = min(dp[j + items[i].s], dp[j] + items[i].f);
            }
        }
    }

    ll ans = 0;
    for(ll i = 1e5; i >= 0; i--){
        if(dp[i] != 1e18){
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}

int main(){
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}

