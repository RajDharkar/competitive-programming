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

const ll MOD = 1e9+7;
ll bexp(ll a, ll b){
    ll ret = 1;
    while(b > 0){
        if(b & 1)ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1; 
    }
    return ret;
}

int main(){
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    ll n;
    cin >> n;
    vi diff(2*n+1);
    vector<pii> q;
    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        q.pb({a, b});
        diff[a]++;
        diff[b]--;
    }
    for(ll i = 1; i <= 2*n; i++)diff[i] += diff[i-1];
    ll ret = 0;
    for(auto &[a, b] : q){
        ret += (bexp(2, (n-diff[a])));
        // cout << 2 << " " << n-diff[a] << '\n';
        ret %= MOD;
    }

    cout << ret << '\n';
}