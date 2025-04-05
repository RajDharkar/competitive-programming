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

bool is_prime(ll n){
    if(n < 2)return 0;
    for(ll i = 2; i * i <= n; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

void solve(){
    ll n;
    cin >> n; vector<ll> ans;
    ll p=0;
    for(ll i = n/3; i <= (2*n + 3) / 3; i++){
        if(is_prime(i)){
            p = i;
        }
    }
    assert(p != 0);
    ll cnt = 0;
    set<ll> used;
    ans.pb(p);
    ll l = p, r = p;
    while(cnt < n){
        l--;r++;

        if(l >= 1 && l <= n){
            ans.pb(l);
            used.insert(l);
        }
        if(r <= n && r > 0) {
            ans.pb(r);
            used.insert(r);
        }
        cnt++;
    }

    for(ll i = 1; i <= n; i++){
        if(!used.count(i)){
            ans.pb(i);
        }
    }
    for(ll i = 0; i < n; i++){
        cout << ans[i] << " \n"[i == n-1];
    }

}

int main(){
    ll t;
    cin >> t;
    while(t--)solve();
}


