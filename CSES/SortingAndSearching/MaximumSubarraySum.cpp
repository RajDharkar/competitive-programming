#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

//KADANE'S ALGORITHM
int main(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto &x : arr)cin >> x;

    ll ans = -1e9;
    ll prevsum = 0; 
    ll x = -1;
    for(int i = 0; i < n; i++){
        // x = max(x, arr[i]);
        prevsum = max(prevsum+arr[i], arr[i]);
        ans = max(ans, prevsum);
    }
    cout << ans << endl;
}


