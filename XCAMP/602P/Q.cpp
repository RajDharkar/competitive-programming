#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second


int n, q;
vector<int> el, er;
vector<int> euler;
vector<int> depth;
vector<int> first;
int cnt = 0;
vector<vector<int>> adj;
void dfs(int node, int p, int dep){
    el[node] = cnt++;
    depth[node] = dep;
    euler.pb(node);
    first[node] = sz(euler)-1;
    for(auto x : adj[node]){
        if(x != p){
            dfs(x, node, dep+1);
            euler.pb(node);
        }
    }
    er[node] = cnt-1;
}

const int TABLE_SIZE = 25;
const int MAXN = 4e5+2;
int ST[TABLE_SIZE+1][MAXN];
void build_table(){
    int tbsz = sz(euler);
    for(int i = 0; i < tbsz; i++){
        ST[0][i] = i;
    }
    for(int i = 1; i <= TABLE_SIZE; i++){
        for(int j = 0; j + (1 << i) <= tbsz; j++){
            int x = ST[i-1][j];
            int y = ST[i-1][j + (1 << (i-1))];
            bool ret = depth[euler[x]] < depth[euler[y]];
            if(ret){
                ST[i][j] = x;
            } else{
                ST[i][j] = y;
            }
        }
    }
}

int min_range(int l, int r){
    if(r < l)swap(l, r);
    int range = (r-l)+1;
    int lg = log2(range);
    int x = ST[lg][l];
    int y = ST[lg][r - (1 << lg) + 1];
    bool ret = depth[euler[x]] < depth[euler[y]];
    if(ret){
        return euler[x];
    } else{
        return euler[y];
    }
}

int lca(int a, int b){
    int l = min(first[a], first[b]);
    int r = max(first[a], first[b]);
    // int mn = 1e9;
    // int ret = -1;
    // for(int i = l; i <= r; i++){
    //     if(depth[euler[i]] < mn){
    //         ret = euler[i];
    //         mn = depth[euler[i]];
    //     }
    // }
    return min_range(l, r);
}

struct Node{
    int val, quant;
};

struct SegTree{
    vector<int> tree, lazy;
    int size;

    SegTree(int n){
        tree.resize(4*n,0);
        tree.resize(4*n,0);
    }

    void push(int v) {
        tree[v*2] += lazy[v];
        lazy[v*2] += lazy[v];
        tree[v*2+1] += lazy[v];
        lazy[v*2+1] += lazy[v];
        lazy[v] = 0;
    }
    
    void update(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            tree[v] += addend;
            lazy[v] += addend;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v*2, tl, tm, l, min(r, tm), addend);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            tree[v] = min(tree[v*2], tree[v*2+1]);
        }
    }
    
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return -1e9;
        if (l == tl && tr == r)
            return tree[v];
        push(v);
        int tm = (tl + tr) / 2;
        return min(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
};

int main(){
    ios::sync_with_stdio(false); //makes streams have independant buffers or smth 
    cin.tie(nullptr); //unties stream, doesn't automatically flush output

    cin >> n >> q;
    adj.resize(n); el.resize(n); er.resize(n); depth.resize(n); first.resize(n, 1e9);
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }

    dfs(0, -1, 0);
    build_table();

    // for(auto &x : euler){
    //     cout << x << " ";
    // }
    // cout << '\n';
    // for(int i = 0; i < n; i++){
    //     cout << i << " " << el[i] << " " << er[i] << " " << first[i] << " " << depth[i] << '\n';
    // }   
    // cout << '\n';
    set<pii> ex; //edges that exist in the tree
    vector<int> arr(n); //fake segment tree
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b; --a;--b;
        cout << a << " " << b << '\n';
        if(first[a] > first[b])swap(a, b);
        cout << lca(a, b) << '\n';

        // //if a and b exist in the graph, then we can add 1 to all the nodes that now dont work
        // //we need to add the path between a and b
        if(ex.count({a, b})){
            //add
        } else{
            //subtract
        }
    }
}

