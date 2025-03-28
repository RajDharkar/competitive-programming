#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto &x : arr)cin >> x;
    sort(arr.begin(), arr.end());
    ll ans = 1e9;
    for(ll i = 0; i < 1 << n; i++){
        ll a=0;
        ll b=0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                a+=arr[j];
            } else{
                b+=arr[j];
            }
        }
        ans = min(abs(a-b), ans);
    }
    cout << ans;


}