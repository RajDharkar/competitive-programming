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
    ll n;
    cin >> n;
    vector<ll> ans(n);
    ll p = n-1;
    ll cnt = n;
    if(n%2==0){
        cout << -1 << endl;
        return;
    }
    while(cnt != 0){
        if(ans[p] != 0){
            p--;
            continue;
        }
        ans[p] = cnt;
        p -= 2;
        p += n;
        p %= n;
        cnt--;
    }
    for(ll i = 0; i < n; i++){
        cout << ans[i] << " \n"[i == n-1];
    }

        

    //1 2 3 4 5 
    //3 1 4 2 5

    //1 2 3 4 
    //
}

int main(){

    ll t;
    cin >> t;
    while(t--)solve();
}


