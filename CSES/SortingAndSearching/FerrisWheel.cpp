#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> ab(n);
    for(auto& x : ab)cin >> x;
    sort(ab.begin(), ab.end());
    ll l = 0;
    ll r = n-1;
    ll ans = 0;
    while(l<=r){
        // cout << ab[l] << " " << ab[r] << " " << ans << endl;
        if(ab[l]+ab[r]<=x){
            ans++;
            l++;
            r--;
        }
        else{
            if(ab[r]<=x){
                ans++;
            }
            // ans += (a[r]<=x);
            r--;
        }
    }
    // cout << l << " " << r << " " << ans << endl;
    cout << ans << endl;
}