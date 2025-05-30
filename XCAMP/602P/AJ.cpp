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

vvi adj;

int main(){
    int n, m; cin >> n >> m;
    adj.resize(n);
    for(int i = 0; i < m; i++){
        int u, v, b;
        cin >> u >> v >> b;
        if(b == 0){
            adj[v].pb(u);
        } else{
            adj[u].pb(v);
        }
    }

    queue<int> q;
    vi visited(n,0);
    visited[0] = 1;
    q.push(0);
    while(!q.empty()){
        int node = q.front(); q.pop();
        
        for(auto &x : adj[node]){
            if(!visited[x]) q.push(x);
        }
    }
}

