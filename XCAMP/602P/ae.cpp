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

ll MOD;
vvi adj;
vi dp;
vi bdp;
void dfs(ll n, ll p){  
    ll ret = 1;
    ll cnt = 0;
    for(auto &x : adj[n]){
        if(x == p)continue;
        dfs(x, n);
        ret = (ret * dp[x]) % MOD;
        cnt++;
    }
    dp[n] = !cnt ? 2LL : (ret + 1) % MOD;
}

void dfs2(ll n, ll p){
    ll ret = 0;
    ll i = 0;
    ll s = 0;
    for(auto &x : adj[n]){
        if(x == p)continue;
        s++;
    }
    vi pref((s+1), 1);
    vi suff((s+1), 1);
    for(auto &x : adj[n]){
        if(x == p)continue;
        pref[i+1] = pref[i] * dp[x] % MOD;
        i++;
    }

    i = 0;
    for(ll id = sz(adj[n])-1; id>=0; id--){
        ll x = adj[n][id];
        if(x == p)continue;
        suff[s-i-1] = (suff[s-i] * dp[x]) % MOD;
        i++;
    }

    i = 0;
    for(auto &x : adj[n]){
        if(x == p)continue;
        i++;
        bdp[x] = 1 + bdp[n] * ((pref[i - 1] * suff[i]) % MOD) % MOD;
    }
    for(auto &x : adj[n]){
        if(x != p){
            dfs2(x, n);
        }
    }
}

int main(){
    fastio
    ll n;
    cin >> n >> MOD;
    res(adj, n);    
    res(dp, n+1);
    res(bdp, n+1);
    bdp[0]=1;
    for(ll i = 0; i < n - 1; i++){
        ll a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0, -1);
    dfs2(0, -1);
    for(ll i = 0; i < n; i++){
        cout << (bdp[i] * ((dp[i] - 1 + MOD) % MOD)) % MOD << '\n';
    }
}