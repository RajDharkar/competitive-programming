#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

vector<ll> arr;
vector<vector<ll>> adj;
vector<ll> lef, rih, euler;
ll timer = 0;
void dfs(ll n, ll p){
    euler[timer] = n;
    lef[n] = timer++;
    for(auto x : adj[n]){
        if(x != p){
            dfs(x, n);
        }
    }
    rih[n] = timer;
}

vector<ll> tree;

void update(ll i, ll val, ll k, ll l, ll r){ 
    if(l == r){
        tree[k] = val;
        return;
    }
    ll mid = (l + r) / 2;
    if(i <= mid){update(i, val, k*2, l, mid);}
    else{update(i, val, k*2+1, mid+1, r);};
    tree[k] = tree[k*2] + tree[k*2+1];  
}

ll query(ll l, ll r, ll k, ll cl, ll cr){ 
    if(cr < l || cl > r){
        return 0;
    }

    if(cl >= l && cr <= r){
        return tree[k];
    }

    ll mid = (cl + cr) / 2;
    return query(l, r, k*2, cl, mid) + query(l, r, k*2 + 1, mid+1, cr);
}

int main(){
    ll n;
    cin >> n;
    arr.resize(n); adj.resize(n);
    lef.resize(n); rih.resize(n); euler.resize(n);
    for(auto &x : arr)cin >> x;
    for(ll i = 0; i < n-1; i++){
        ll x, y; cin >> x >> y;
        adj[--x].pb(--y);
        adj[y].pb(x);
    }

    vector<ll> st=arr;
    sort(all(st));
    st.erase(unique(all(st)), st.end());
    for(ll i = 0; i < n; i++){
        arr[i] = lower_bound(all(st), arr[i]) - st.begin();
    }
    dfs(0,-1);
    tree.resize(5*n+1);

    // vector<ll> p(sz(st),-1);
    // for(ll i = 0; i < n; i++){
    //     if(p[(arr[euler[i]])] != -1)update(p[arr[euler[i]]], 0, 1, 0, n-1);
    //     update(i, 1, 1, 0, n-1);
    //     p[arr[euler[i]]] = i;
    // }

    // for(ll i = 0; i < n; i++){
    //     cout << query(lef[i],rih[i]-1,1,0,n-1) << " \n"[i==n-1];
    // }

    vector<ll> p(sz(st),-1);
    vector<ll> ans(n);
    vector<vector<ll>> qr(n);
    for(ll u = 0; u < n; u++)qr[rih[u]-1].push_back(u);
    for(ll i = 0; i < n; i++){
        ll u = euler[i], v = arr[u];
        if(p[v] != -1) update(p[v], 0, 1, 0, n-1);
        update(i, 1, 1, 0, n-1);
        p[v] = i;
        for(ll u2 : qr[i]){
            ans[u2] = query(lef[u2], rih[u2]-1, 1, 0, n-1);
        }
    }

    for(ll i = 0; i < n; i++)cout << ans[i] << " \n"[i==n-1];

}

