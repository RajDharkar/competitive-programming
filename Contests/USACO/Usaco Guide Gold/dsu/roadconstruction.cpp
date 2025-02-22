#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct DSU{
    vector<ll> tree;
    void init(ll n){
        tree = vector<ll>(n, -1); //all nodes with a size of 1(if its -x its not a "father" and it has a size of x)
    }
    ll find(ll node){
        return tree[node] < 0 ? node : tree[node] = find(tree[node]); //flattening the tree(path compression)
    }
    bool unite(ll p, ll q){
        p = find(p);
        q = find(q);
        if(p == q){ 
            return false; //nodes are already united
        }

        if(tree[p] < tree[q]){
            swap(p, q); //weird way to do this but now we know that the size of p is greater than the size of q
        }
        tree[p] += tree[q]; //append to the bottom of the node p
        tree[q] = p; //p is now the father of q 
        return true;
    }
    ll size(ll x){
        return -tree[find(x)];
    }
};

int main(){
    ll n, m;
    cin >> n >> m;
    DSU dsu;
    dsu.init(n);
    ll ans = n;
    ll size = 1;
    for(ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        if(dsu.unite(a-1, b-1)){
            ans--;
            size = max(dsu.size(a-1), size);
        }
        cout << ans << ' ' << size << '\n';
    }
}