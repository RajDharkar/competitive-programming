#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define f first
#define s second

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> money(n);
    for(auto &x : money){
        cin >> x;
    }
    cout << 0 << endl;
    vector<pi> roads(m);
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        cin >> roads[i].f >> roads[i].s;
        adj[roads[i].f-1].push_back(roads[i].s-1);
    }
    cout << 0 << endl;
    int dp[1002][1002];
    memset(dp, 0, sizeof(dp));  // Initialize to a very negative value (negative infinity)
    dp[0][0]=0;
    // int node = 0;
    for(int i = 0; i < 1000; i++){
        for(int node = 0; node < n; node++){
            // dp[i+1][]
            if(dp[i][node]==0)continue;
            for(int x : adj[node]){
                dp[i+1][x] = max(dp[i+1][x], dp[i][node]+money[x]);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<1000;i++){
        ans = max(ans, dp[i][0] - c*i*i);
    }
    cout << ans << endl;
}   

