#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans = 0;
    for(int k = 0; k < n; k++){
        vector<bool> visited(n, 0);
        queue<pii> nodes;
        nodes.push({k, 0});
        visited[k] = true;
        while(!nodes.empty()){
            int front = nodes.front().first;
            int depth = nodes.front().second;
            nodes.pop();
            if(depth==1)continue;
            for(int a : adj[front]){
                if(!visited[a]){
                    visited[a]=1;
                    nodes.push(make_pair(a, depth+1));
                }   
            }
        }
        for(int i = 0; i < n; i++){
            cout << visited[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++){
            ans += !visited[i];
            if(!visited[i]){
                adj[i].push_back(k);
                adj[k].push_back(i);
            }    
        }
    }
    cout << ans << endl;
}
