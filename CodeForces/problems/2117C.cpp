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

void solve(){
    ll n;
    cin >> n;
    unordered_set<ll> c, a;
    ll v; ll ans = 0;
    for(ll i = 0; i < n; i++){
        cin >> v;
        a.insert(v); c.insert(v);
        ans += sz(a)==sz(c);
        if(sz(a) == sz(c)){
            // ans--;
            c.clear();
        }
    }
    cout << ans << '\n';
    // c.clear(); a.clear();
}

int main(){
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}

