#include<bits/stdc++.h>

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

    bool connected(ll p, ll q){
        return find(p) == find(q);
    }
};


bool cmp(pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b){
    return a.first < b.first;
}

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
   ll n; // n < 1000
   cin >> n;
   vector<pair<ll, ll>> pos(n);
//cout << 1 << endl; 
    for(ll i = 0; i < n; i++){
        cin >> pos[i].first >> pos[i].second;
    } 
    vector<pair<ll, pair<ll, ll>>> distances;
    for(ll i = 0; i < n; i++){
        for(ll j = i + 1; j < n; j++){
            ll distance = pow(pos[i].first-pos[j].first, 2) + pow(pos[i].second-pos[j].second, 2);
            distances.push_back({distance, {i, j}}); //sqrt not necessary and will prob mess up stuff cuz double
        }
    }

    sort(distances.begin(), distances.end(), cmp);
    DSU dsu;
    dsu.init(n);
    int cc = n;
    ll ans = 0;
    for(int i = 0; i < int(distances.size()); i++){
        if(dsu.unite(distances[i].second.first, distances[i].second.second)){
            cc--;
            ans = distances[i].first;
        }
        if(cc==0){
            break;
        }
    }
    cout << ans << endl;    
}

