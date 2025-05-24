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
vector<vector<ll>> adj; ll ret = 0;
bool dfs(ll n, ll p){
    ll child = 2;
    for(auto &v : adj[n]){
        if(v == p)continue;
        if(dfs(v, n) && child > 0){
            ret++; child--;
        }
    }
    return child > 0;
}
int main(){
    ll n, x, y;
    cin >> n >> x >> y;
    adj.resize(n);
    for(ll i = 0; i < n-1; i++){
        ll a, b; cin >> a >> b;
        a--;b--;adj[a].pb(b); adj[b].pb(a);
    }
    if(x>y){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += sz(adj[i])==1;
        }
        if(cnt >= n-1){
            cout << y*(n-2)+x << '\n';
        } else{
            cout << y*(n-1) << '\n';
        }
    } else{
        dfs(0, -1);
        cout << (ret * x) + (n - ret - 1) * y << '\n';
    }
}