#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

ll ceil(ll a, ll b){
    return (a + 1) / b;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(auto &x : arr){
        cin >> x; 
    }   

    ll ans= 0;
    for(ll i = 0; i < n-1; i++){
        ans += arr[i] > arr[i+1];
    }
    cout << ceil(ans, 2) << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}

