#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main() {
    ll t;
    cin >> t;
    while(t--){
       ll n;
       cin >> n; ll ans = 0;
       vector<ll> arr(n);
       for(auto &x : arr){
            cin >> x;
       }
        vector<ll> sums(n-4);
        map<ll, ll> cnt;
        for(int i = 0; i < n-4; i++){
            sums[i] = arr[i] + arr[i + 2] - arr[i + 4];
            cnt[arr[i] + arr[i + 2] - arr[i + 4]]++;
        }

        for(auto &[a, b] : cnt){
            ans += b*(b - 1)/2;
        }

        for(ll i = 0; i < n - 4; i++){
            if(i < n -6 && sums[i] == sums[i + 2])
                ans--;
            if(i < n -8 && sums[i] == sums[i + 4])
                ans--;
        }
        cout << ans << '\n';
    }
}
