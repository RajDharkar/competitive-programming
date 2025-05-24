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
vector<vector<ll>> adj;
vector<ll> depth;
void dfs(ll n, ll p){
    for(auto &x : adj[n]){
        if(x == p)continue;
        depth[x] = depth[n]+1;
        dfs(x, n);
    }
}
int main(){
    ll n;
    cin >> n;
    adj.resize(n);
    depth.resize(n);
    depth[0]=0;
    for(ll i = 0; i < n-1; i++){
        ll a,b; cin >> a >> b;
        a--;b--;
        adj[a].pb(b); adj[b].pb(a);
    }
    dfs(0,-1);
    double ans = 0;
    for(auto &x : depth)ans += (!x?1:(1.0/(x+1)));
    cout << setprecision(20) << ans << '\n';
}