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
    ll n, m, k;
    cin >> n >> m >> k;

    ll mx = k / n + (k % n != 0);
    ll btm = min(m, m - mx + 1);

    // cout << mx << " " << btm << endl;

    cout << ((btm + mx - 1) / btm) << '\n';
        
}

int main(){

    ll t;
    cin >> t;
    while(t--)solve();
}


