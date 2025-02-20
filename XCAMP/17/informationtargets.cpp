#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> adj;

int main() {
    ll n;
    cin >> n;
    adj.resize(n);
    vector<ll> in_degree(n);
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        adj[i] = (a-1);
        in_degree[adj[i]]++;
    }

    queue<ll> nodes;
    for(ll i = 0; i < n; i++){
        if(in_degree[i] == 0){
            nodes.push(i);
        }
    }

    while(!nodes.empty()){
        ll curr = nodes.front();
        nodes.pop();
        in_degree[adj[curr]]--;
        if((in_degree[adj[curr]]) == 0){
            nodes.push(adj[curr]);
        }
    }

    ll ans = 1e9; 
    vector<bool> visited(n);
    for(ll i = 0; i < n; i++){
        if(!in_degree[i] || visited[i]){
            continue;
        }
        ll node = i;
        ll count = 0;
        while(!visited[node]){
            count++;
            visited[node] = true;
            node = adj[node];
        }

        ans = min(count, ans);
    }

    cout << ans;

}
