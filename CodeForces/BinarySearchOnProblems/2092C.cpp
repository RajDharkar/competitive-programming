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
    sort(all(arr), greater<ll>());  
    ll ans=0;
    for(ll i = 0; i < n; i++){
        if(arr[i]%2==0)ans += arr[i];
    }
    if(ans == accumulate(all(arr), 0LL) || ans == 0){
        cout << *max_element(all(arr)) << '\n';
        return;
    }

    for(ll i = 0; i < n; i++){
        if(arr[i]&1){
            ans += arr[i]-1;
        }
    }
    ans++;
    cout << ans << '\n';
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}

