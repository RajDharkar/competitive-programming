#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

const ll depth = 20;
map<string, ll> mp;
ll mid;
ll n, m, k;
ll grid[depth+1][depth+1];

void dfs(ll x, ll y, ll val, ll d){ //pos, 
    if(x < 0 || y < 0 || x >= n || y >= m){
        return;
    }

    val^=(grid[x][y]);
    // cout << x << " " << y << " " << val << " " << d << '\n';
    string store = to_string(x)+"_"+ to_string(y) +"_"+ to_string(val);
    // cout << store << '\n';
    mp[store]++;
    if(d==mid){
        return;
    }
    dfs(x+1, y, val, d+1);
    dfs(x, y+1, val, d+1);
}

ll ans = 0;

void dfs2(ll x, ll y, ll val, ll d){ //pos, 
    if(x < 0 || y < 0 || x >= n || y >= m){
        return;
    }
    // cout << d << " " << (n+m-2) - mid << '\n';
    if(d == ((n+m-2) - mid)){
        // cout << x << " " << y << " " << val <<'\n';
        string store = to_string(x)+"_"+ to_string(y) +"_"+ to_string(k^val);
        ans += mp[store];
        return;
    }
    val^=(grid[x][y]);
    // cout << x << " " << y << " " << val << " " << d << '\n';
    // string store = to_string(x)+"_"+ to_string(y) +"_"+ to_string(val);
    // cout << store << '\n';
    dfs2(x-1, y, val, d+1);
    dfs2(x, y-1, val, d+1);
}


int main(){
    cin >> n >> m >> k;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    mid = (n + m - 2) / 2; 

    dfs(0, 0, 0, 0);

    // for(auto &[a, b] : mp){
    //     cout << a << " " << b << '\n';
    // }

    dfs2(n-1, m-1, 0, 0);
    cout << ans << '\n';
}

