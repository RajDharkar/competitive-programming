#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(auto &x : arr)cin >> x;
    sort(arr.begin(), arr.end());
    map<ll, ll> mp;
    for(auto x : arr){
        mp[x]++;
    }

    ll ans = 0;
    for(auto &[a, b] : mp){
        ans += min(2LL, b - b % 2);
    }
    if(mp[arr[n-1]]==1){
        ans++;
    }
    else{
        ll b = mp[arr[n-1]];
        ans -= min(2LL, b - b % 2);
        ans++;
    }
    end:;
    cout << ans << '\n';
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}

