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
    sort(all(arr));
    cout << arr[n-1] - arr[0] << '\n';
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}

