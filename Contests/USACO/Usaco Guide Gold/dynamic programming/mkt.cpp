#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define f first
#define s second

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> score(n);
        for(auto &a : score)cin >> a;
        vector<vector<ll>> dp(2, vector<ll>(n + 1, 1e9));
        dp[1][0] = 0; //partner goes first
        for(int i=0;i<n;i++){
            dp[0][i+1]=min(dp[0][i+1], dp[1][i] + score[i]);
            dp[1][i+1]=min(dp[1][i+1], dp[0][i]);

            if(i <= n-2){
                dp[0][i+2]=min(dp[0][i+2], dp[1][i] + score[i] + score[i+1]);
                dp[1][i+2]=min(dp[1][i+2], dp[0][i]);
            }
        }

        // for(int i=0;i<=n;i++){
        //     cout << dp[0][i] << " " << dp[1][i] << endl;
        // }
        cout << min(dp[0][n], dp[1][n]) << endl;
    }
}

