#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(auto &x : arr)cin >> x;
        vector<pair<ll, ll>> ans;
        ll s = n;
        for(ll i = n/2; i < n; i++){
            if(arr[i] == 0){
                ans.pb({1+n/2, n});
                s -= (n - (1 + n/2));
                break;
            }
        }
        for(ll i = 0; i<n/2; i++){
            if(arr[i] == 0){
                ans.pb({1, n/2});
                s -= (n/2 - 1);
                break;
            }
        }
        ans.pb({1, s});
        cout << sz(ans) << endl;
        for(const auto &[x, y] : ans){
            cout << x << " " << y << '\n';
        }
    }
}

