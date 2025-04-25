#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

ll ceil(ll a, ll  b){
    return (a + b - 1) / b;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if(n % 2 == 1){
        if(k % 2 == 1){
            ans++;
            n -= k;
        } 
        ans += ceil(n, k-1);
    } else{
        if(k % 2 == 0){
            ans += ceil(n, k);
        } else{
            ans += ceil(n, k-1);
            // cout << ceil(6, 2) << endl;
        }
    }
    cout << ans << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}

