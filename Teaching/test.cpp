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

vi pos;
ll n, k;
bool check(ll r){
    ll mxseen = 0;
    ll used = 0;
    for(ll i = 0; i < sz(pos); i++){
        if(mxseen < pos[i]){
            used++;
            mxseen = pos[i] + r * 2;
        }
    }
    return used <= k;
}

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> n >> k;
    res(pos, n);
    for(auto &x : pos)cin >> x;
    sort(all(pos));
    ll lo = 0;
    ll hi = 1e9;
    while(lo < hi){
        ll mid = lo + (hi - lo) / 2;
        if(check(mid)){
            hi = mid;
        } else{
            lo = mid + 1;
        }
    }
    cout << lo << '\n';
}

