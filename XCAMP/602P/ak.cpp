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

vvi adj;
vvi floyd;

int main(){
    int n, m;
    cin >> n >> m;    
    floyd.resize(n, vi(n, -1e9));
    adj.resize(n, vi(n));
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b  >> c;
        adj[a][b] = c;
        floyd[a][b] = c;
    }

    for(int i = 0; i < n; i++)floyd[i][i] = 0;


}

