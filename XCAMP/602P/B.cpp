#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

struct Node{
    ll max_sum, pref_sum, suffix_sum, total_sum;

    void set(ll val){
        max_sum = val;
        pref_sum = val;
        suffix_sum = val;
        total_sum = val;
    }
};

Node combine(Node a, Node b){
    if(a.max_sum == LLONG_MIN)return b;
    if(b.max_sum == LLONG_MIN)return a;

    ll max_sum, pref_sum, suffix_sum, total_sum;
    max_sum = max(max(a.max_sum, b.max_sum), (a.suffix_sum + b.pref_sum));
    suffix_sum = max(b.suffix_sum, b.total_sum + a.suffix_sum);
    pref_sum = max(a.pref_sum, a.total_sum + b.pref_sum);
    total_sum = a.total_sum + b.total_sum;

    return {max_sum, pref_sum, suffix_sum, total_sum};
}

vector<Node> tree;
ll n;

void update(int l, int r, int k, int i, int val){
    if(l == r){
        tree[k].set(val);
    }
    else{
        int m = (l + r) / 2;
        if(i <= m){
            update(l, m, k*2, i, val);
        } else{
            update(m+1, r, k*2+1, i, val);
        }
        tree[k] = combine(tree[k*2], tree[k*2+1]);
    }
}

void update(int pos, int val){
    update(0, n-1, 1, pos, val);
}


Node query(ll ql, ll qr, ll k, ll l, ll r){
    if(qr < l || ql > r){
        return {LLONG_MIN, 0, 0, 0};
    }

    if(l >= ql && r <= qr){
        return tree[k];
    }

    ll mid = (l + r) / 2;
    return combine(query(ql, qr, k*2, l, mid), (query(ql, qr, k*2+1, mid+1, r)));
}

int main(){
    cin >> n;
    tree.resize(5*n+1);

    for(ll i = 0; i < n; i++){
        ll x; cin >> x; update(i, x);
    }

    ll q; cin >> q;
    while(q--){
        ll a, b, c;
        cin >> a >> b >> c;
        b--;
        if(a == 0){
            update(b, c);
        } else {
            c--;
            cout << query(b, c, 1, 0, n-1).max_sum << '\n';
        }
    }
}

