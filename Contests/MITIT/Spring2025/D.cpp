#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> cities(k);
        for(auto &x : cities)cin >> x;
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            a--;b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
}

