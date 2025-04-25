#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

const ll MAX = 2e5+1;
ll dp[MAX]; //dp[i] = the cost to traverse starting from node i at time 0
vector<ll> grow;
vector<vector<ll>> adj;
vector<ll> len;
vector<ll> sum;
bool cmp(ll p_0, ll p_1){
    // return (len[p_0] / sum[p_0]) < len[p_1] / sum[p_1]; //can also just be written like (below)
    return len[p_0] * sum[p_1] < len[p_1] * sum[p_0];
}

int main(){
    ll n, t;
    cin >> n >> t;
    adj.resize(n);
    grow.resize(n);
    len.resize(n, 1);
    sum.resize(n);
    // if(t == 0){
        for(ll i = 1; i < n; i++){
            ll x, y;
            cin >> x >> y;
            x--;
            adj[x].pb(i); //CHECK(ed loooooooool) it's understanded now. (trust grammar)
            grow[i] = y;
            sum[i] = y;
        }

        grow[0] = 0;
        for(ll i = n - 1; i >= 0; i--){
            for(auto &x : adj[i])sum[i]+=sum[x]; 
        }

        for(ll i = n - 1; i >= 0; i--){
            for(auto &x : adj[i])len[i]+=len[x];
        }

        //time = for all children sum of 2*(len[children]+numberOfChildren) (nvm just do dfs count which is (2 * amount of edges )
        //pastures = for pasture in order, sum of dp[pasture] * sum of pasture sizes so far
        //dp[p_0] + 0 * sum[p_0] + dp[p_1] + sz[p_0] * sum[p_1] + dp[p_2] + (sz[p_0] + sz[p_1]) * sum[p_2]...
        //exchange 
        //dp[p_1] + 0 * sum[p_1] + dp[p_0] + sz[p_1] * sum[p_0] + dp[p_2] + (sz[p_1] + sz[p_0]) * sum[p_2]...
        //sz[p_0] * sum[p_1] 
        //sz[p_1] * sum[p_0]
        //sz[p_0] * sum[p_1] _ sz[p_1] * sum[p_0]
        //sz[p_0] / sum[p_0] _ sz[p_1] / sun[p_1]; (remember you want to minimize so)
        //sz[p_)] / sum[p_0] < sz[p_1] / sum[p_1];

        // for(ll i = 0; i < n; i++){
        //     cout << sum[i] << " " << len[i] << '\n';
        // }
        sum[0] = 0;
        vector<ll> children;
        memset(dp, 0, sizeof dp);
        for(ll i = n-1; i >= 0; i--){
            children.clear();
            for(auto &x : adj[i])children.pb(x);
            sort(all(children), cmp);

            ll ret = 0;
            ll time = 1;
            for(auto child : children){
                ret += dp[child];
                ret += time * sum[child];
                time += 2*len[child]; //go down and back up
            }
            dp[i] = ret;
        }
        // for(auto &x : dp)cout << x << " ";
        // cout << endl;
        cout << 2 * (n - 1) << " " << dp[0] << '\n';
    // }
}

