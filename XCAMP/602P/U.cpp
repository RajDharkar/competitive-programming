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

vector<vector<int>> adj;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x : arr)cin >> x;
    adj.resize(n);
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}