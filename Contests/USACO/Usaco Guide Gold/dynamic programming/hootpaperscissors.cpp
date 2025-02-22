#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define f first
#define s second
// #include "C:\Users\rajve\Documents\GitHub\competitive-programming\debugging.h"


//HOOF = 0, PAPER = 1, SCISSORS = 2, so to check if a beats b we do a-b mod 3 == 1

int amax(int a, int b, int c){
    return max(c, max(a, b));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int dp[n+1][25][3] = {0};
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=k+1;j++){
    //         for(int k=0;k<3;k++){
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    // cout << dp << endl;
    for(int i = 1; i <= n; i++){
        char a;
        cin >> a;
        int move=0;
        if(a=='P')move=1;
        if(a=='S')move=2;
        for(int j = 1; j <= k+1; j++){
            //cout << dp[i][j][0];
            int wonthisone = ((0-move)+3) % 3 == 1;
            dp[i][j][0] = amax(dp[i-1][j][0], dp[i-1][j-1][1], dp[i-1][j-1][2]) + wonthisone;
            wonthisone = ((1-move)+3) % 3 == 1;
            dp[i][j][1] = amax(dp[i-1][j][1], dp[i-1][j-1][0], dp[i-1][j-1][2]) + wonthisone;
            wonthisone = ((2-move)+3) % 3 == 1;
            dp[i][j][2] = amax(dp[i-1][j][2], dp[i-1][j-1][1], dp[i-1][j-1][0]) + wonthisone;
        }
    }
    int ans = 0;
    for(int i = 1; i <= k+1; i++){
        ans = max(ans, amax(dp[n][i][0], dp[n][i][1], dp[n][i][2]));
    }
    cout << ans << endl;
}

