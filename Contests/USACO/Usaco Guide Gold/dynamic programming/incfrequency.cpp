#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define f first
#define s second
 
int main() {
    //cout << 6 << endl;
    ll n, c;
    cin >> n >> c;
    vector<ll> arr(n);
    ll k = 0;
    for(auto &x : arr){
        cin >> x;
        k += x==c;
    }    
    // cout << k << endl;
    ll count = 0;
    ll dp[500001] = {0};
    ll mx = k; 
    for(int i=0;i<n;i++){
        if(arr[i]==c){
            count++;
            continue;
        }    
 
        dp[arr[i]] = max(dp[arr[i]]+1, count+1);
        mx = max(mx, k-count + dp[arr[i]]);
    }
    cout << mx << endl;
}
 