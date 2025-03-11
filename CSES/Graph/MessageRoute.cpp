    #include<bits/stdc++.h>
    using namespace std;
    
    using ll = long long;
    using pi = pair<int,int>;
    using pl = pair<ll,ll>;
    #define f first
    #define s second

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

        queue<int> nodes;
        vector<int> min_distance(n, 1e9);
        min_distance[0] = 1;
        vector<int> parents(n, -1);
        nodes.push(0);
        vector<bool> visited(n, 0);
        visited[0] = true;
        while(!nodes.empty()){
            int node = nodes.front();
            nodes.pop();
            //0, 
            for(int x : adj[node]){
                if(!visited[x]){
                    min_distance[x] = min_distance[node] + 1;
                    parents[x] = node;
                    visited[x] = 1;
                    nodes.push(x);
                }    
            }
        }
        // for(auto x : parents)cout << x << endl;
        if(min_distance[n-1] == 1e9){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        cout << min_distance[n-1] << endl;
        vector<int> ans;
        ans.push_back(n);
        int node = n-1;
        while(node != -1){
            node = parents[node];
            ans.push_back(1+node);
        }
        reverse(ans.begin(), ans.end());
        for(int i = 1; i < int(ans.size()); i++){
            if(i>1){
                cout << " ";
            }
            cout << ans[i];
        }


    }

