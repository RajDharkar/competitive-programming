#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;k++;
        vector<ll> arr(n); 
        for(auto &x : arr)cin >> x;

        // priority_queue<ll, vector<ll>, greater<ll>> pq;
        priority_queue<ll> pq;
        ll ans = 0;
        for(ll i = 0; i < n; i++){
            pq.push(arr[i]);
            ll dist = n-1 - i;
            dist++;

            if(dist % k == 0){
                ans += pq.top();pq.pop();
            }
        }
        cout << ans << '\n';

        //
    }
}