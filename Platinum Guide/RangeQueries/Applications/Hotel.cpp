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

vi tree;
ll n, m;
void upd(ll i, ll val, ll k=1, ll l=0, ll r=n-1){
    if(l == r){
        tree[k] += val;
        return;
    }
    ll mid = (l + r) / 2;
    if(i <= mid){
        upd(i, val, k*2, l, mid);
    } else{
        upd(i, val, k*2+1, mid+1, r);
    }
    tree[k] = max(tree[k*2], tree[k*2+1]);
}

ll ans = 0;
void query(ll x, ll k=1, ll l=0, ll r=n-1){
    if(l == r){
        ans = l;
    } else{
        ll mid = (l + r) / 2;
        if(tree[k * 2] >= x){
            //go left
            query(x, k*2, l, mid);
        } else{
            query(x, k*2+1, mid+1, r);
        }
    }
}

int main(){
    fastio
    cin >> n >> m;
    res(tree, n * 5);
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        upd(i, x);
    }

    for(ll i = 0; i < m; i++){
        ll x; cin >> x;
        if(x > tree[1]){
            cout << 0 << " ";
            continue;
        }
        ans = 0;
        query(x);
        upd(ans,-x);
        cout << ans+1 << " ";
    }
}