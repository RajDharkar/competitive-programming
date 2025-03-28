#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x : arr)cin >> x;
    int dp[n+1][n+1];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = -1e9;
        }
    }

    for(int len = 1; len <= n; len++){
        for(int l = 1; l <= n; l++){
            int r = l + len;
            l %= n;
            int ans = -1e9;
            for(int i = l; l < r; l++){
                for(int j = l+1; j < r; j++){
                    for(int k = j+1; k < r; k++){
                        ans = max(ans, dp[l][i-1] + dp[i+1][j-1] + dp[j+1][k-1] + dp[k+1][r] + (arr[i-1]*arr[j-1]*arr[k-1]));
                    }
                }
            }
            dp[l][r]=ans;
        }
    }
    int real = -1e9;
    for(int i = 0; i < n; i++){
        real = max(real, (dp[i+1][(i+n)%n]));
    }
    cout << real << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

