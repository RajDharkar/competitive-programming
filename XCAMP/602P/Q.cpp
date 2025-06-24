#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x),end(x)
#define pb push_back
#define f first
#define s second

ll n,q;
vector<ll> el,er,euler,depth,first;

ll cnt=0;
vector<vector<ll>> adj;
void dfs(ll node,ll p,ll dep){
    el[node]=cnt++;
    depth[node]=dep;
    euler.pb(node);
    first[node]=sz(euler)-1;
    for(auto x:adj[node]){
        if(x!=p){
            dfs(x,node,dep+1);
            euler.pb(node);
        }
    }
    er[node]=cnt-1;
}

const ll TABLE_SIZE=25;
const ll MAXN=4e5+2;
ll ST[TABLE_SIZE+1][MAXN];
void build_table(){
    ll tbsz=sz(euler);
    for(ll i=0;i<tbsz;i++) ST[0][i]=i;
    for(ll i=1;i<=TABLE_SIZE;i++) {
        for(ll j=0;j+(1<<i)<=tbsz;j++){
            ll x=ST[i-1][j];
            ll y=ST[i-1][j+(1<<(i-1))];
            ST[i][j]=(depth[euler[x]]<depth[euler[y]]?x:y);
        }
}
}

ll min_range(ll l,ll r){
    if(r<l) swap(l,r);
    ll range=r-l+1;
    ll lg=log2(range);
    ll x=ST[lg][l];
    ll y=ST[lg][r-(1<<lg)+1];
    return depth[euler[x]]<depth[euler[y]]?euler[x]:euler[y];
}

ll lca(ll a,ll b){
    ll l=min(first[a],first[b]);
    ll r=max(first[a],first[b]);
    return min_range(l,r);
}
const ll high = 1e9;
struct Node{
    ll val, count;
};

struct SegTree{
    vector<Node> tree;
    vector<ll> lazy;
    ll size;

    SegTree(ll n){
        tree.assign(4*n,{0,1});lazy.assign(4*n,0);
        build();
    }

    void build(ll v = 1, ll l = 0, ll r = n-1){
        if(l == r)tree[v] = {0,1};
        else {
            ll m = (l + r) / 2;
            build(v*2, l, m);
            build(v*2+1, m+1, r);
            combine(v);
        }
    }

    void push(ll v){
        tree[v*2].val+=lazy[v];
        lazy[v*2]+=lazy[v];
        tree[v*2+1].val+=lazy[v];
        lazy[v*2+1]+=lazy[v];
        lazy[v]=0;
    }

    void combine(ll v){
        if(tree[v*2].val==tree[v*2+1].val){
            tree[v].val=tree[v*2].val;
            tree[v].count=tree[v*2].count+tree[v*2+1].count;
        }else if(tree[v*2].val<tree[v*2+1].val){
            tree[v]=tree[v*2];
        }else{
            tree[v]=tree[v*2+1];
        }
    }

    void update(ll v,ll tl,ll tr,ll l,ll r,ll addend){
        if(l>r) return;
        if(l==tl&&tr==r){
            tree[v].val+=addend;
            lazy[v]+=addend;
        }else{
            push(v);
            ll tm=(tl+tr)/2;
            update(v*2,tl,tm,l,min(r,tm),addend);
            update(v*2+1,tm+1,tr,max(l,tm+1),r,addend);
            combine(v);
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>q;
    adj.resize(n);
    el.resize(n);
    er.resize(n);
    depth.resize(n);
    first.resize(n,1e9);
    for(ll i=1;i<n;i++){
        ll a,b;cin>>a>>b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0,-1,0);
    build_table();
    set<pii> ex;

    SegTree seg(n);
    ll ans = 0;
    for(ll i=0;i<q;i++){
        ll a, b;
        cin >> a >> b;
        --a;--b;
        if(a > b) swap(a,b);

        ll d= -(ex.count({a, b}) * 2 - 1);
        ll p = lca(a,b);
        if(p != a && p != b){
            seg.update(1, 0, n-1, 0, n-1, d);
            seg.update(1, 0, n-1, el[a], er[a], -d);
            seg.update(1, 0, n-1, el[b], er[b], -d);
        }else{
            ll anc= p == a ? a : b;
            ll desc = anc == a ? b : a;
            // seg.update(1, 0 , n-1, el[anc], er[anc], d);
            // seg.update(1, 0, n-1, el[desc], er[desc], d);

            ll i = -1;
            for(ll v: adj[anc]) {
                if(el[v] <= el[desc] && el[desc] <= er[v] && depth[v] > depth[anc]){
                    i = v; break;
                }
            }
            seg.update(1, 0, n-1, el[i], er[i], d);
            seg.update(1, 0, n-1, el[desc], er[desc], -d);
        }
        if(d==1) {
            ex.insert({a,b});
        } 
        else{
            ex.erase({a,b});
        }
        cout << (seg.tree[1].val == 0 ? seg.tree[1].count : 0)<< '\n';
    }
}
