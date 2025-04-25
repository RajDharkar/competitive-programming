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
    ll n, z;
    cin >> n >> z;
    vector<ll> arr(n);
    for(auto &x : arr)cin >> x;
    sort(all(arr), greater<ll>());

    ll curmin = 1e9;
    ll ans = 0;
    ll sz = 0;
    for(auto x : arr){
        sz++;
        curmin = min(curmin, x);
        if(curmin * sz >= z){
            ans++;
            sz = 0;
            x = 1e9;
        }
    }
    cout << ans << endl;
}

int main(){

    ll t;
    cin >> t;
    while(t--)solve();
}


