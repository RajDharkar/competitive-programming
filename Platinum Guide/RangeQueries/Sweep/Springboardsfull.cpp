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

const ll N = 2e5+1;
struct segt{
    vector<ll> tree;
    void upd(ll i, ll v, ll k=1, ll l=0, ll r=N){
        if(l == r){
            tree[k] = min(tree[k], v);
            return;
        }
        ll mid = (l + r) / 2;
        if(i <= mid){
            upd(i, v, k*2, l, mid);
        } else{
            upd(i, v, k*2+1, mid+1, r);
        }
        tree[k] = min(tree[k*2], tree[k*2+1]);
    }
    ll query(ll ql, ll qr, ll k=1, ll l=0, ll r=N){
        if(r < ql || l > qr){
            return 2e18;
        }
        if(l >= ql && r <= qr){
            return tree[k];
        }
        ll mid = (l+r)/2;
        return min(query(ql, qr, k*2, l, mid), query(ql, qr, k*2+1, mid+1, r));
    }
};

ll dp[N+1];
int main(){
    fastio
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    ll n, p;
    cin >> n >> p;
    vector<array<ll, 4>> events, o;
    vector<ll> cc;
    for(ll i = 0; i < p; i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.pb({x1, y1, 1, i});
        events.pb({x2, y2, 0, i});
        o.pb({x1,y1,x2,y2});
        cc.pb(y1); cc.pb(y2);
    }
    sort(all(cc));
    cc.erase(unique(all(cc)), cc.end());
    sort(all(events));
    fill(dp, dp+N, 2e18);
    segt st;
    st.tree.resize(4*N, 2e18);
    st.upd(0,0);

    auto compress = [&](ll z) -> ll {
        return lower_bound(all(cc), z) - bg(cc);
    };
    for(ll i = 0; i < 2*p; i++){
        if(events[i][2]){
            dp[events[i][3]] = min(dp[events[i][3]], events[i][0] + events[i][1] + st.query(0, compress(events[i][1]))); 
        } else{
            st.upd(compress(events[i][1]), dp[events[i][3]] - events[i][0] - events[i][1]);
        }
    }
    ll ans = 2 * n;
    for (ll i = 0; i < p; ++i) {
        auto [x1, y1, x2, y2] = o[i];
        ans = min(ans, dp[i] + (n - x2) + (n - y2));
    } 
    cout << ans;
}

