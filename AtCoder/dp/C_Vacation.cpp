#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);  

typedef long long ll;
typedef pair<ll, ll> pii;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second
#define vi vector<ll>
#define vvi vector<vi>
#define res(x, n) (x).resize(n)
void solve(){
    fastio;
    int n;
    cin >> n;
    vvi dp(n+1, vi(3));
    for(int i = 1; i <= n; i++){
        //DP[i][0,1,2] = the maximum amount of money that we will gain if we CHOOSE to take 0, 1, 2
        for(int c = 0; c < 3; c++){
            int x;
            cin >> x;
            for(int other = 0; other < 3; other++){
                if(other != c){
                    dp[i][c] = max(dp[i][c], dp[i - 1][other] + x);
                }
            }
        }
    }
    ll mx = 0;
    for(int i = 0; i < 3; i++){
        mx = max(mx, dp[n][i]);
    }
    cout << mx << '\n';
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}

