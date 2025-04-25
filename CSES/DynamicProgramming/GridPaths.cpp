#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int dp[1001][1001];

int main(){
    ll mod = 1e9 + 7;

    ll n;
    cin >> n;

    for(ll i = 1; i <= n; i++){
        fill(dp[i], dp[i] + n, 0);
    }

    dp[1][0]=1;
    for(ll i = 1; i <= n; i++){
        string line;
        cin >> line;
        for(ll j = 1; j <= n; j++){
            if(line[j-1] =='*'){
                dp[i][j] = 0;
            } else{
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]);
                dp[i][j] %= mod;
            }
        }
    }

    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][n] % mod << endl;
}

