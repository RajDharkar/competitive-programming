#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    // freopen("cbarn2.in", "r", stdin);
    // freopen("cbarn2.out", "w", stdout);

    ll n, k;
    cin >> n >> k;
    deque<ll> arr(n);
    for(auto &x : arr)cin >> x;
    ll ans = 1e9;
    for(ll start = 1; start <= n; start++){ //all starting points for this circular array
        ll dp[n+1][k+1];
        for(ll i = 0;i <= n;i++){
            for(ll j = 0; j <= k; j++){
                dp[i][j] = 1e9; 
            }
        }
        dp[0][0]=0;
        for(ll doornum = 1; doornum <= k; doornum++){
            for(ll j = 1; j <= n; j++){ //ALL SPOTS FOR THE NEW DOOR
                ll doorans = 0; //sliding window approach kinda? we just go through it and find
                // keep track of the distance of [[a, b, c, d],[e, d, f, g, h, i, j, k]] works
                for(ll z = j+1; z <= n; z++){// ALL SPOTS FOR THE LAST DOOR 
                    doorans += arr[z-1] * (z - j);
                if (dp[doornum - 1][j - 1] != 1e9){
                        dp[doornum][z] = min(dp[doornum][z], doorans + dp[doornum-1][j-1]);
                    //
                } 
            }
        }
        ans = min(ans, dp[k][n]); //wait why zero i dont understand
        arr.push_back(arr.front()); arr.pop_front();
    }
    cout << ans << endl;
}