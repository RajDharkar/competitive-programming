#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int dp[301][301];
    for(int i = 1; i <= n; i++)dp[i][i] = arr[i-1]; //base case(length of 1)
    for(int i = 2; i <= n; i++){ //all possible lengths
        for(int j = 1; j <= n - i + 1; j++){ //all starting positions of subarray w/ said length
            dp[j][i+j-1] = 1e9;
            for(int x = j; x < i+j-1; x++){
                dp[j][i+j-1] = min(dp[j][i+j-1], max(dp[j][x], dp[x+1][i+j-1])+1);
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            ans += dp[i][j];
        }
    }
    cout << ans;
}

