#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

vector<vector<ll>> adj;
vector<ll> dp;

ll dfs(ll node, ll parent){
    ll cnt = 0;
    for(auto x : adj[node]){
        if(x != parent){
            cnt++;
        }
    }

    if(cnt == 0){
        dp[node]=0;
        return 0;

    } else{
        for(auto x : adj[node]){
            if(x != parent){
                dp[node] = max(dp[node], 1+dfs(x, node));
            }
        }
        return dp[node];
    }
}

ll dfs2(ll node, ll parent){
    ll cnt = 0;
    ll firstmin = 0; ll secondmin = 0;
    ll mx = 0;
    for(auto x : adj[node]){
        if(x != parent){
            cnt++;
            if(dp[x] > firstmin){
                secondmin = firstmin;
                firstmin = dp[x];
            } else if(dp[x] > secondmin) {
                secondmin = dp[x];
            }
            mx = max(dfs2(x, node), mx);
        }
    }
    return max(firstmin+secondmin+min(cnt, 2LL), mx);
}

int main(){
    ll n;
    cin >> n;
    adj.resize(n);
    dp.resize(n);

    for(ll i = 0; i < n-1; i++){
        ll a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1);
    cout << dfs2(0, -1);
}

