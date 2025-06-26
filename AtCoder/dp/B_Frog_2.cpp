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
    int n, k;
    cin >> n >> k;
    vi arr(n + 1);
    for(int i = 1; i <= n; i++)cin >> arr[i];
    vi dp(n + 1, 1e9);
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        int pnt = i; 
        while(--pnt >= 1 && abs(pnt - i) <= k){
            dp[i] = min(dp[pnt] + abs(arr[i] - arr[pnt]), dp[i]);
        }
    }
    cout << dp[n];
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}

