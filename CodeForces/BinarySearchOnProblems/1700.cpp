// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> ans;
        for(ll i = 0; i < n; i++){

            // for(ll j = 0; j < )
            ll level = n-1;
            // cout << (level ^ i) << " " << ((level | i) + ((level & i) << 1));
            // cout << level << " " << i << endl;
            // cout << level << "  " << i << " " << endl;
            // bool condition = level ^ i == ((level ^ i) + 2 * (level & i));
            bool condition = (level & i) == i;
            // cout << 
            if(condition){
                // cout << (level ^ i) << " " << ((level ^ i) + 2 * (level & i)) << endl;
                ans.push_back(k);
            } else{
                ans.push_back(0);
            }
            // ans.push_back((level & i == i) ? k : 0);
        }
        // cout << endl;
        for(ll i = 0; i < n; i++){
            cout << ans[i] << " \n"[i == n-1];
        }
    }
}
