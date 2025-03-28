// Source: https://usaco.guide/general/io


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
vector<ll> values;
vector<ll> sum;
vector<vector<ll>> adj;
vector<ll> parents;
vector<ll> start;
vector<ll> finish;
ll timer = 0;
void dfs(ll node, ll parent){
    start[node] = timer;
    timer++;
    parents[node]=parent;
    for(ll k : adj[node]){
        if(k!=parent){
            dfs(k, node);
        }
    }
    finish[node] = timer;
}

vector<ll> tree;

void build(){
    for(ll i = 0; i < n; i++){
        tree[i+n] = values[i];
    }
    for(ll i = n-1; i; i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

void modify(ll i, ll value){
    for(tree[i += n] = value; i > 1; i>>=1){
        tree[i>>1] = tree[i] + tree[i^1];
    }
}

ll query(ll l, ll r){
    ll ret = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1) ret += tree[l++];
        if(r&1) ret += tree[--r];
    }
    return ret;
}


int main() {
    cin >> n >> m;
    values.resize(n);
    sum.resize(n);
    adj.resize(n);
    parents.resize(n);
    start.resize(n);
    finish.resize(n);
    for(ll i = 0; i < n; i++){
        cin >> values[i];
    }
    for(ll i = 0; i < n-1; i++){
        ll a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    // for(ll i = 0; i < n; i++){
    //     cout << i+1 << " " << parents[i]+1 << "\n";
    // }
    // for(ll i = 0; i < n; i++){
    //     cout << start[i] << " ";
    // }
    // cout << endl;
    // for(ll i = 0; i < n; i++){
    //     cout << finish[i] << " ";
    // }
    // cout << endl;
    tree.resize(2*n);
    build();
    while(m--){
        ll type;
        cin >> type;
        if(type-1){
            ll nodesum;
            cin >> nodesum;
            cout << query(start[nodesum], finish[nodesum-1]) << endl;
        }
        else{
            ll node, update;
            cin >> node >> update;
            modify(node-1, update);
        }
    }
}
