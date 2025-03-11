#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> start;
vector<ll> en;
vector<vector<ll>> adj;

vector<ll> tree;
ll n;
void build(){
    // iota(tree.begin(), tree.end(), 0);
    for(ll i = n-1; i > 0; i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

void update(ll p, ll k){
    tree[p+n] = k;
    p+=n;
    for(; p > 1; p /= 2){
        tree[p/2] = tree[p] + tree[p^1];
    }
}

ll query(ll l, ll r){
    l+=n;r+=n;
    ll ans =0;
    while(l<=r){
        if(l%2==1)ans+=tree[l++];
        if(r%2==0)ans+=tree[r--];
        l/=2;r/=2;
    }
    return ans;
}
ll elem = 0;
void dfs(ll node, ll parent){
    start[node]=elem;
    elem++;
    for(auto x : adj[node]){
        if(x!=parent){
            dfs(x, node);
        }
    }
    en[node]=elem;
}

int main(){
    ll q;
    cin >> n >> q;
    start.resize(n);
    en.resize(n);
    adj.resize(n);
    tree.resize(2*n);
    build();
    vector<ll> nodes(n);
    int i=0;
    for(auto &a : nodes){
        cin >> a;
        update(i++, a);
    }
    for(ll i = 0; i < n-1; i++){
        ll a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    for(int i = 0; i < q; i++){
        ll t;
        cin >> t;
        if(t==1){
            int node, va;
            cin >> node >> va;
            node--;
            update(start[node], va);
        }
        else{
            int node;
            cin >> node;
            node--;
            cout << query(start[node]-1, en[node]-1) << endl;
        }
    }

}