#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
vector<vector<ll>> adj;
// ll cnt = 0;
// bool visited[41];
// vector<vector<ll>> cycles;

// void dfs(ll node){
//     cycles[cnt].pb(node);
//     visited[node] = 1;
//     for(auto x : adj[node]){
//         if(!visited[x])dfs(x);
//     }
// }

// ll cliques[1LL<<20];
ll cliquepart1[1LL<<20];
bool cliquepart2[1LL<<20];

int main(){
    ll n, m;
    cin >> n >> m;
    adj.resize(n);
    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    // cycles.resize(41);
    // for(ll i = 0; i < n; i++){
    //     if(visited[i])continue;
    //     dfs(i);
    //     cnt++;
    // }

    // for(ll i = 0; i < 41; i++){
    //     for(ll j = 0; j < sz(cycles[i]); j++){
    //         cout << cycles[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    ll part1 = n/2;
    for(ll mask = 0; mask < 1LL << part1; mask++){
        cliquepart1[mask]=mask;
        for(ll ind = 0; ind < part1; ind++){
            ll bit = mask & (1LL << ind);
            if(bit == 0)continue;
            for(ll x : adj[ind]){
                if(mask & (1LL << x)){
                    cliquepart1[mask] = 0; goto end;
                }
            }
        }
        end:;
    }

    for(ll i = 0; i < part1; i++){
        for(ll mask = 0; mask < (1LL << part1); mask++){
            if(cliquepart1[mask ^ (1LL << i)] == 0)continue;
            if(mask & (1LL << i) && __builtin_popcount(cliquepart1[(mask ^ (1LL << i))]) > __builtin_popcount(cliquepart1[mask])){
                cliquepart1[mask] = cliquepart1[mask^(1LL<<i)];
            }
        }
    }

    for(ll mask = 0; mask < 1LL << (n-part1); mask++){
        cliquepart2[mask]=1;
        for(ll ind = 0; ind < n-part1; ind++){
            ll bit = mask & (1LL << ind);
            if(bit == 0)continue;
            for(ll x : adj[part1+ind]){
                if(x < part1)continue;
                if(mask & (1LL << (x-part1))){
                    cliquepart2[mask] = 0; goto end2;
                }
            }
        }
        end2:;
    }

    ll ans1, ans2;
    ll ans = 0;
    for(ll mask = 0; mask < 1LL << (n-part1); mask++){
        if(!cliquepart2[mask])continue; 
        ll ones = 1LL << part1; ones--;
        for(ll i = 0; i < (n-part1); i++){
            if(mask & (1LL << i)){
                for(ll x : adj[part1+i]){
                    if(x >= part1) continue;
                    if(ones & (1LL << x)){
                        ones ^= 1LL << x;
                    }
                }
            }
        }
        if (ans < __builtin_popcountll(mask)+__builtin_popcountll(cliquepart1[ones])){
            ans = (__builtin_popcountll(mask)+__builtin_popcountll(cliquepart1[ones]));
            ans1 = cliquepart1[ones];
            ans2 = mask;
        }
    }
    cout << ans << '\n';
    for(ll i = 0; i < part1; i++){
        if(ans1 & (1LL << i))cout << i << " ";
    }
    for(ll i = 0; i < n-part1; i++){
        if(ans2 & (1LL << i))cout << i+part1 << " \n"[i == n-part1-1];
    }
    // ll ans = 0;
    // for(ll i = 0; i < 41; i++){
    //     if(sz(cycles[i]) == 0)continue;
    //     ans += solve(cycles[i]);                             
    // }
}
