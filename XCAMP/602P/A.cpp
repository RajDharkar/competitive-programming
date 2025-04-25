#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

vector<ll> tree;
ll n;

void update(ll i, ll p){
    i += n;
    tree[i] += p;
    i /= 2;
    for(; i >= 1; i/=2){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

ll query(ll ql, ll qr, ll k, ll l, ll r){
    if(qr < l || ql > r){
        return 0;
    }

    if(l >= ql && r <= qr){
        return tree[k];
    }

    ll mid = (l + r) / 2;
    return query(ql, qr, k*2, l, mid) + query(ql, qr, k*2+1, mid+1, r);
}

int main(){
    ll q, an;
    cin >> an >> q;

    n=1;
    while(n<an)n<<=1;

    tree.resize(2*n+1);

    for(ll i = 0; i < an; i++){
        ll x; cin >> x; update(i, x);
    }

    while(q--){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 0){
            update(b, c);
        } else {
            c--;
            cout << query(b, c, 1, 0, n-1) << '\n';
        }
    }
}

