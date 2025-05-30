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

const ll N = 205;
ll adj[N][N];

int main(){
    ll n, m; cin >> n >> m;
    fill(&adj[0][0], &adj[0][0] + N*N, 1e9);
    vector<pii> edges;
    for(ll i = 0; i < n; i++) adj[i][i] = 0;
    for(ll i=0; i<m; i++){
        ll u, v; cin >> u >> v;
        edges.pb({--u, --v});
        ll t; cin >> t;
        if(t) {
            adj[u][v] = 1;
            adj[v][u] = -1;
        }
        else{
            adj[u][v] = adj[v][u] = 1;
        }
    }

    for(ll k = 0; k < n; k++){
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                if(adj[i][k] + adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }    
            }      
        }
    }
    bool works = 1;
    ll mx = -1e9;
    ll id = -1;
    for(ll i = 0; i < n; i++){
        if(adj[i][i] < 0) works = 0;
        for(ll j = 0; j < n; j++) {
            if(adj[i][j] > mx){
                mx = adj[i][j];
                id = i;
            }
        }
    }

    for(ll i = 0; i < m; i++) works &= adj[id][edges[i].f] != adj[id][edges[i].s];
    if(!works){
        cout << "NO" << '\n';
    } else{
        cout << "YES" << '\n' << mx << '\n';
        for(ll i = 0; i < n; i++){
            cout << adj[id][i] << " \n"[i == n-1];
        }
    }
}

