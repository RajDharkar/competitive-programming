#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

vector<ll> tree;
vector<ll> lazy;
vector<ll> y_coords, prefix;

struct Line{
    ll i, y1, y2, x;
    bool isLeft;
};

bool cmp(Line a, Line b){
    return a.x < b.x;
}

void range_add(ll ql, ll qr, ll k, ll l, ll r, ll val){
    if(ql > r || qr < l){
        return;
    }

    if(ql <= l && r <= qr){
        lazy[k] += val;
    }
    else{
        ll mid = (l + r) / 2;
        range_add(ql, qr, k*2, l, mid, val);
        range_add(ql, qr, k*2+1, mid+1, r, val);
    }

    if(lazy[k] > 0){
        tree[k] = prefix[r+1] - prefix[l]; //easier updates 
    }
    else if(l == r){
        tree[k] = 0;
    }
    else{
        tree[k] = tree[2*k] + tree[2*k+1];
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
    return query(ql, qr, k*2, l, mid)+ query(ql, qr, k*2+1, mid+1, r);
}

void solve(){
    ll n;
    cin >> n;

    vector<Line> lines;
    set<ll> y;
    for(ll i = 0; i < n; i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y.insert(y1);
        y.insert(y2);
        lines.pb({i, y1, y2, x1, true});
        lines.pb({i, y1, y2, x2, false});
    }
    sort(all(lines), cmp);

    y_coords.assign(all(y));
    ll m = sz(y_coords);
    prefix.resize(m+1, 0);

    for(ll i = 0; i < m; i++){
        if(i+1 < m){
            prefix[i+1] = prefix[i] + (y_coords[i+1] - y_coords[i]);
        }
        else{
            prefix[i+1] = prefix[i];
        }
    }

    ll dist = m - 1;
    tree.resize(4*dist, 0);
    lazy.resize(4*dist, 0);

    map<ll, ll> cc;
    ll idx = 0;
    for(auto v : y){
        cc[v] = idx++;
    }

    ll area = 0;
    for(ll i = 0; i < 2 * n - 1; i++){
        Line &k = lines[i];
        ll add = k.isLeft ? 1 : -1;
        ll l = cc[k.y1];
        ll r = cc[k.y2] - 1;
        if(l <= r){
            range_add(l, r, 1, 0, dist - 1, add);
        }
        ll next = lines[i+1].x - k.x;
        area += tree[1] * next;
    }
    cout << area;

    lazy.clear();
    tree.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    t = 1;
    while(t--){
        solve();
    }
}
