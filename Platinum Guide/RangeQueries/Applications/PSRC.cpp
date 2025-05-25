#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);  

typedef long long ll;
typedef pair<ll, ll> pii;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second
#define vi vector<ll>
#define vvi vector<vi>
#define res(x, n) (x).resize(n)
const ll MOD = 998244353;
struct Node{
    ll x, b;  
};

Node combine(Node u, Node v){
    return {(u.x * v.x) % MOD, (u.x * v.b % MOD + u.b) % MOD}; 
}
ll n;
vector<Node> tree;
void upd(ll i, Node v, ll k=1, ll l=0, ll r=n-1){
    if(l == r){
        tree[k] = v;
        return;
    }
    ll mid = (l + r) / 2;
    if(i <= mid){
        upd(i, v, k*2, l, mid);
    } else{
        upd(i, v, k*2+1, mid+1, r);
    }
    tree[k] = combine(tree[k*2+1], tree[k*2]);
}

Node query(ll ql, ll qr, ll k=1, ll l=0, ll r=n-1){
    if(r < ql || l > qr){
        return {1,0};
    }
    if(ql <= l && r <= qr){
        return tree[k];
    }
    ll mid = (l+r)/2;
    return combine(query(ql, qr, k*2+1, mid+1, r), query(ql, qr, k*2, l, mid));
}

int main(){
    ll q;
    cin >> n >> q;
    res(tree, n*4);
    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        upd(i, {a, b});
    }
    while(q--){
        ll t; cin >> t;
        if(t == 0){
            ll p, c, d; cin >> p >> c >> d;
            upd(p, {c, d});
        } else{
            ll l, r, z; cin >> l >> r >> z;
            Node ret = query(l, r-1); 
            cout << (ret.x * z % MOD + ret.b) % MOD << '\n';
        }
    }
}