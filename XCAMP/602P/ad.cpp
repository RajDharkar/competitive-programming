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
vector<vector<ll>> adj;
vector<ll> wei;
vector<ll> dep;
vector<ll> sums;
vector<ll> answers;
void dfs(ll n, ll p){
    sums[n] = wei[n];
    for(auto &x : adj[n]){
        if(x == p)continue;
        dep[x] = dep[n]+1;
        dfs(x, n);
        sums[n] += sums[x];
    }
}

void dfs2(ll n, ll p){
    for(auto &x : adj[n]){
        if(x==p)continue;
        answers[x] = answers[n];
        answers[x] -= sums[x];
        answers[x] += (sums[0] - sums[x]);
        dfs2(x, n);
    }
}
int main(){
    ll n;
    cin >> n;
    adj.resize(n);
    wei.resize(n);
    dep.resize(n);
    sums.resize(n);
    for(auto &x : wei)cin >> x;
    for(ll i = 0; i < n-1; i++){
        ll a, b; cin >> a >> b;
        a--;b--;adj[a].pb(b); adj[b].pb(a);
    }
    dfs(0,-1);
    answers.resize(n);
    for(ll i = 0; i < n; i++){
        answers[0] += dep[i] * wei[i];
    }
    dfs2(0,-1);
    cout << *max_element(all(answers)) << '\n';
}