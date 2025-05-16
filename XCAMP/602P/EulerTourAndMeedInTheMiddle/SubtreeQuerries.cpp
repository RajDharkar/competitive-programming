#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

vector<ll> lft;
vector<ll> rgt;
vector<vector<ll>> adj;

struct Node{
    vector<ll> arr;
};

vector<ll> me(const Node &a, const Node &b){
    ll p1 = 0;
    ll p2 = 0;
    ll p3 = 0;
    vector<ll> ret(sz(a.arr)+sz(b.arr));
    while(p1 < sz(a.arr) && p2 < sz(b.arr)){
        if(a.arr[p1] < b.arr[p2]){
            ret[p3] = a.arr[p1];
            p1++;
        } else{
            ret[p3] = b.arr[p2];
            p2++;
        }
        p3++;
    }
    while (p1 < sz(a.arr)) 
        ret[p3++] = (a.arr[p1++]);
    while (p2 < sz(b.arr)) 
        ret[p3++] = (b.arr[p2++]);
    return ret;
}

vector<Node> tree;
void build(vector<ll> &a, ll l, ll r, ll k){
    if(r < l)return;
    if(l==r){
        tree[k].arr = {a[l]};
        return;
    }
    ll m = (l+r)/2;
    build(a, l, m, k*2);
    build(a, m+1, r, k*2+1);
    tree[k].arr = me(tree[k*2], tree[k*2+1]);
}

ll query(ll ql, ll qr, ll val, ll k, ll l, ll r){
    if(r < ql || l > qr){
        return 0;
    }

    if(l >= ql && r <= qr){
        auto it = upper_bound(all(tree[k].arr), val);
        return sz(tree[k].arr) - (it-tree[k].arr.begin());
    }

    ll mid = (l+r)/2;
    return query(ql, qr, val, k*2, l, mid) + query(ql, qr, val, k*2+1, mid+1, r);
} 

//merge sort tree
// ll main(){

//     ll q; 
//     cin >> q;
//     while(q--){
//         ll a, b, c;
//         cin >> a >> b >> c;
//         a--;b--;
//         cout << query(a, b, c, 1, 0, n - 1) << '\n';
//     }
// }

ll timer = 0;
void dfs(ll node, ll parent){
    lft[node] = timer++;
    for(auto x : adj[node]){
        if(x != parent){
            dfs(x, node);
        }
    }
    rgt[node] = timer;  
}

int main(){
    ios::sync_with_stdio(false); //makes streams have independant buffers or smth 
    cin.tie(nullptr); //unties stream, doesn't automatically flush output

    ll n;
    cin >> n;
    lft.resize(n);
    rgt.resize(n);
    adj.resize(n);
    vector<ll> arr(n);
    for(auto &x : arr)cin >> x;
    for(ll i = 0; i < n - 1; i++){
        ll a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0,-1);
    for(ll i = 0; i < n; i++){
        cout << lft[i] << " " << rgt[i] << endl; 
    }

    tree.resize(4*n+4);
    build(arr, 0, n-1, 1);
}

