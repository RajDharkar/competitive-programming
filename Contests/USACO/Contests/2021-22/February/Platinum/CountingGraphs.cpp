#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

#define MOD 1000000007

vector<ll> depths;
vector<vector<ll>> adj;
// vector<ll> precomp;

ll binexp(ll a, ll b){
    if(a==0)return 0;

    ll ret = 1;
    while(b > 0){
        if(b % 2 == 1){
            ret = (ret * a) % MOD;
        }
        a*=a;
        a%=MOD;
        b /= 2;
    }   
    return ret;
}

void dfs(ll node, ll parent, ll depth){
    depths[depth++]++;
    // cout << depth++ << endl;
    for(auto x : adj[node]){
        if(x!=parent){
            dfs(x, node, depth);
        }
    }
}

void solve(){
    adj.clear();
    depths.clear();
    ll n, m;
    cin >> n >> m;
    // cout << 1 << endl;
    depths.resize(n+2);
    adj.resize(n);
    vector<pair<ll, ll>> edges(m);
    for(ll i = 0; i < m; i++){
        cin >> edges[i].first >> edges[i].second;
        adj[--edges[i].first].pb(--edges[i].second);
        adj[edges[i].second].pb(edges[i].first);
            // cout << 1 << endl;
    }

    dfs(0, -1, 0);

    // for(ll i = 0; i <= n+1; i++){
    //     cout << i << " " << depths[i] << endl;
    // }
    ll ans = 1;
    for(ll i = 1; i <= n + 1; i++){
        ll p = binexp(2, depths[i-1]) - 1;
        p *= depths[i];
        if(p==0)p=1;
        // ans *= (binexp(2, depths[i-1]) - 1);
        ans *= (p % MOD);
        ans %= MOD;
    }
    cout << ans << endl;
    // cout << binexp(2, 5) << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}

