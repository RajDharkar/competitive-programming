    #include <bits/stdc++.h>
    using namespace std;

    using ll = long long;

    ll MOD = 10007;

    vector<vector<int>> adj;
    vector<ll> weights;
    ll secondans = 0;

    ll dfs(int node, int depth, int parent, int root) {
        if (depth == 0) {  
            secondans = max(secondans, (weights[root] * weights[node]) % MOD);
            return weights[node];  
        }

        ll ans = 0;
        for (auto adjnode : adj[node]) {
            if (adjnode != parent) {  
                ans += dfs(adjnode, depth - 1, node, root);  
                ans %= MOD;
            }
        }
        return ans;
    }

    int main() {
        ll n;
        cin >> n;
        adj.resize(n);
        for(int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        weights.resize(n);
        for(int i = 0; i < n; i++){
            cin >> weights[i];
        }

        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll num = (dfs(i, 2, i, i) * weights[i]) % MOD;
            ans = (ans + num) % MOD;
        }
        
        cout << secondans << " " << ans << endl;
    }
