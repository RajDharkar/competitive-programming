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

const ll N = 1e4+1;
ll dp[N+1];
int main(){
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    ll n, p;
    cin >> n >> p;
    vector<array<ll, 4>> event(p);
    for(auto &[a, b, c, d] : event)cin >> a >> b >> c >> d;
    sort(all(event));
    fill(dp, dp+N, 1e9);
    auto calc = [&](ll a, ll b) -> ll {
        ll dy = event[b][1] - event[a][3];
        ll dx = event[b][0] - event[a][2];
        if(dx < 0 || dy < 0)return 1e18;
        return dx + dy;
    };
    dp[0] = 0;
    for(ll i = 0; i < p; i++){
        dp[i+1] = event[i][0]+event[i][1];
        for(ll j = i; j >= 1; j--){
            dp[i+1] = min(dp[i+1], dp[j] + calc(j-1, i));
        }
    }
    ll mn = 1e18;
    for(ll i = 0; i < p; i++){
        mn = min(mn, dp[i+1] + n - event[i][2] + n - event[i][3]);
    }
    cout << mn << '\n';
}

