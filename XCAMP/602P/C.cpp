#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

vector<ll> tree;
vector<ll> lazy;

ll n;

void push(ll l, ll r, ll k){
    if(l==r || lazy[k] == 0)return;
    ll mid = (l + r) / 2;

    lazy[2*k] += lazy[k];
    lazy[2*k+1] += lazy[k];

    tree[2*k] += (mid - l + 1) * lazy[k];
    tree[2*k+1] += (r - mid) * lazy[k];    

    lazy[k] = 0;
}

void range_add(ll ql, ll qr, ll k, ll l, ll r, ll val){
    if(ql > r || qr < l){
        return;
    }

    if(ql <= l && qr >= r){
        tree[k] += (r - l + 1) * val;
        lazy[k] += val;
        return;
    }

    push(l, r, k);

    range_add(ql, qr, k*2, l, (l+r)/2, val);
    range_add(ql, qr, k*2+1, 1 + (l+r)/2, r, val);

    tree[k] = tree[2*k] + tree[2*k+1];
}

ll query(ll ql, ll qr, ll k, ll l, ll r){
    if(qr < l || ql > r){
        return 0;
    }

    if(l >= ql && r <= qr){
        return tree[k];
    }

    push(l, r, k);

    ll mid = (l + r) / 2;
    return query(ql, qr, k*2, l, mid) + query(ql, qr, k*2+1, mid+1, r);
}

void solve(){
    ll q;
    cin >> n >> q;
    tree.resize(5*n);
    lazy.resize(5*n);

    while(q--){
        ll a, b, c;
        cin >> a >> b >> c;
        b--;c--;
        if(a == 0){
            ll d;
            cin >> d;
            range_add(b, c, 1, 0, n - 1, d);
        } else {
            cout << query(b, c, 1, 0, n-1) << '\n';
        }
    }
    lazy.clear();
    tree.clear();
}

int main(){
    ios::sync_with_stdio(false); //makes streams have independant buffers or smth 
    cin.tie(nullptr); //unties stream, doesn't automatically flush output

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

//CLEAR ARRAYS U BUFFOON