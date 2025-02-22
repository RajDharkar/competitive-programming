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
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> arr(n);
    for(auto& x : arr){
        cin >> x;
    }

    vector<vector<int>> times(n);
    for(int i=0; i<n; i++){
        times[arr[i]].push_back(i);
    }

    vector<pi> person(m);
    vector<pi> ans(m);
    

     


}

