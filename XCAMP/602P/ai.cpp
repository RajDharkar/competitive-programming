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
    ll n; cin >> n;
    vi arr;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        if(x == 0)continue;
        arr.pb(x);
    }
    n = sz(arr);
    if(n < 3)cout << -1 << '\n';
    else if(n > 140)cout << 3 << '\n';
    else{
        vvi floyd(n, vi(n));
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                if(arr[i]&arr[j] && i != j){
                    floyd[i][j]=1;
                } else if(i != j){
                    floyd[i][j]=1e9;
                } else{
                    floyd[i][j]=0;
                }
                floyd[j][i] = floyd[i][j];
            }
        }
        ll ans = 1e9;
        for(ll u = 0; u < n; u++){
            for(ll v = u+1; v < n; v++){
                if(floyd[u][v] == 1){  
                    auto copy = floyd;
                    floyd[u][v] = 1e9, floyd[v][u] = 1e9;
                    for(ll k = 0; k < n; k++){
                        for(ll i = 0; i < n; i++){
                            for(ll j = 0; j < n; j++){
                                if(floyd[i][k] + floyd[k][j] < floyd[i][j]){
                                    floyd[i][j] = floyd[i][k] + floyd[k][j];
                                }
                            }
                        }
                    }
                    if(floyd[u][v] != 1e9){
                        ans = min(ans, floyd[u][v] + 1);
                    }
                    floyd = copy;
                }
            }
        }
        cout << (ans == 1e9 ? -1 : ans) << '\n';
    }
}
