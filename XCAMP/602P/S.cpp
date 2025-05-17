#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second

const ll MAXN = 301;
ll dp[MAXN][MAXN];
ll vmp[MAXN][MAXN][MAXN]; //vmp[j][{l,r}]
int main(){
    // ios::sync_with_stdio(false); //makes streams have independant buffers or smth 
    // cin.tie(nullptr); //unties stream, doesn't automatically flush output
    freopen("pieaters.in", "r", stdin);
    freopen("pieaters.out", "w", stdout);


    ll n, m;
    cin >> n >> m;

    vector<pii> qs(m);
    vector<ll> weights(m);
    for(ll i = 0; i < m; i++){
        cin >> weights[i] >> qs[i].f >> qs[i].s;
        ll a = qs[i].f;
        ll b = qs[i].s;
        for(ll k = qs[i].f; k <= qs[i].s; k++)
            vmp[k][a][b] = max(vmp[k][a][b], weights[i]);
    }

    for(ll i = 1; i <= n; i++){
        dp[i][i] = vmp[i][i][i];
    }

    for(ll i = 1; i <= n; i++){
        for(ll l = i; l >= 1; l--){
            for(ll r = i; r <= n; r++){
                vmp[i][l][r] = max(l <= r-1 ? vmp[i][l][r-1] : 0, max(vmp[i][l][r], r >= l+1 ? vmp[i][l+1][r] : 0));
            }
        }
    }
    
    // for(ll len = 1; len <= m; len++){
    for(ll len = 1; len <= n; len++) {
        for(ll l = 1; l + len - 1 <= n; l++){
            ll r = l+len-1;
            for(ll k = l; k < r; k++) {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k+1][r]);
            }
            for(ll k = l; k <= r; k++){
                ll left  = (k > l) ? dp[l][k-1] : 0;
                ll right = (k < r) ? dp[k+1][r] : 0;
                dp[l][r] = max(dp[l][r], left + vmp[k][l][r] + right);
            }       
        }
    }  

    cout << dp[1][n];
}

