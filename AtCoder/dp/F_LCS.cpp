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

int main(){
    fastio;
    string s, t;
    cin >> s >> t;
    ll n = sz(s);
    ll m = sz(t);
    vector<vector<pair<int, char>>> dp(n+1, vector<pair<int, char>>(m+1));
    vector<vector<pii>> prev(n+1, vector<pii>(m+1, {-1,-1}));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(s[i] == t[j]){
                if(dp[i+1][j+1].f < dp[i][j].f+1){
                    dp[i+1][j+1] = {dp[i][j].f+1, s[i]};
                    prev[i+1][j+1] = {i, j};
                }
            } else{
                if(dp[i][j+1].f > dp[i+1][j].f){
                    dp[i+1][j+1] = {dp[i][j+1].f, '_'};
                    prev[i+1][j+1] = {i, j+1};
                } else{
                    dp[i+1][j+1] = {dp[i+1][j].f, '_'};
                    prev[i+1][j+1] ={i+1, j};
                }
            }
        }
    }
    pii pos = {n, m};
    string ret = "";
    while(pos.f >= 1 && pos.s >= 1){
        if(dp[pos.f][pos.s].s != '_'){
            ret += dp[pos.f][pos.s].s;
        }
        pos = prev[pos.f][pos.s];
    }
    reverse(all(ret));
    cout << ret << '\n';
}

