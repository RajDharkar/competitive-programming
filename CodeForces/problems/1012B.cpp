#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(2*n+1), b(2*n+1);
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    for(ll i = 1; i <= n; i++){
        ll x;
        cin >> x;
        a[i] = a[i+n] = a[i] - x;
    }

    for(ll i = 1; i <= 2*n; i++){
        a[i] += a[i-1];
    }

    ll t = 0;
    ll ans = 0;

    for(ll i = 2 * n; i >= 1; i--){
        while(t && a[b[t]] > a[i]){
            t--;
        }
        if(i <= n) ans = max(ans, b[t]-i);
        b[++t]=i;
    }

    cout << ans << '\n';
}

int main(){

    ll t;
    cin >> t;
    while(t--)solve();
}


