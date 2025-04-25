#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back


//buh thought this was dp for a sec
int main(){
    ll t;
    cin >> t;
    ll c = 0;
    while(t--){
        c++;
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(auto &x : arr)cin >> x;
        sort(all(arr));
        vector<ll> b(n);
        for(auto &x : b)cin >> x;
        sort(all(b));
        reverse(all(b));

        ll ans = 0;
        for(ll i = 0; i < n; i++){
            ans += arr[i] * b[i];
        }
        cout << "Case #" << c << ": ";
        cout << ans << '\n';
    }
}

