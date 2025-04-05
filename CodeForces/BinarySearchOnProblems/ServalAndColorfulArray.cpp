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
    vector<ll> arr(n);
    for(auto &x : arr)cin >> x;

    //goal is to find the smallest distance for all k elements next to mid
    //with k being from 1 -> k
    //some sort of ds problem, would be nice if we could compute all distances, wait lets see how distances evolve as we iterate through the array
    //lets code nk sol first

    ll ans = 1e18;
    for(ll i = 0; i < n; i++){
        ll l = i;
        ll r = i;

        set<ll> seen;
        seen.insert(arr[i]);

        ll sum = 0;
        // ll cnt=0;
        ll lcount = 1, rcount = 1;
        while((l >= 0 || r < n)){
            // cnt++;
            if(!seen.count(arr[l])){
                sum += abs(i-lcount-l);
                seen.insert(arr[l]);
                lcount++;
            }
            if(!seen.count(arr[r])){
                sum += abs(r-(i+rcount));
                seen.insert(arr[r]);
                rcount++;
            }
            // cout << l << " " << r << endl;
            if(l>0)l--;
            if(r<n-1)r++;
            if(sz(seen)==k){
                // cout << "here" << " " << i << endl;
                break;
            }
        }
        ans = min(ans, sum);
    }

    cout << ans << '\n';
}

int main(){

    ll t;
    cin >> t;
    while(t--)solve();
}


