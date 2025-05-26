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

const ll N = 1e6;

struct segt{
    vector<ll> tree;
    
    void upd(ll i, ll v, ll k=1, ll l=0, ll r=2*N){
        if(l == r){
            tree[k] += v;
            return;
        }
        ll mid = (l + r) / 2;
        if(i <= mid){
            upd(i, v, k*2, l, mid);
        } else{
            upd(i, v, k*2+1, mid+1, r);
        }
        tree[k] = tree[k*2] + tree[k*2+1];
    }
    ll query(ll ql, ll qr, ll k=1, ll l=0, ll r=2*N){
        if(r < ql || l > qr){
            return 0;
        }
        if(l >= ql && r <= qr){
            return tree[k];
        }
        ll mid = (l+r)/2;
        return query(ql, qr, k*2, l, mid) + query(ql, qr, k*2+1, mid+1, r);
    }
};

int main(){
    ll n;
    cin >> n;
    vector<array<ll, 4>> events;  //sorting by Y, (start of vert, horizontal, end of vert)
    for(ll i = 0; i < n; i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(y2 < y1) swap(y1, y2);
        if(x2 < x1) swap(x1, x2);
        if(y1 == y2){
            events.pb({y1, 1, x1, x2});
        } else {
            if(y2 < y1)swap(y1, y2);
            events.pb({y1, 0, x1, x2}); //bottom y 
            events.pb({y2, 2, x1, x2});
        }
    }
    sort(all(events));
    segt st;
    res(st.tree, 9*N);
    ll ans = 0;
    for(ll i = 0; i < sz(events); i++){
        ll t = events[i][1];
        if(t == 0){
            // cout << events[i][2] << '\n';
            st.upd(events[i][2]+N, 1);
        } else if(t == 2){
            st.upd(events[i][2]+N, -1);
        } else{
            ans += st.query(events[i][2]+N, events[i][3]+N);
        }
    }
    cout << ans << '\n';
}