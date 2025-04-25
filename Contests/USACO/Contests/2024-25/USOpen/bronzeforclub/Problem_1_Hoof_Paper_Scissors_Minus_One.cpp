#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> test(n, vector<ll>(n));
    for(ll i = 0; i < n; i++){
        string s;
        cin >> s;
        // cout << s << endl;
        for(ll j = 0; j <= i; j++){
            if(s[j] == 'W'){
                test[i][j] = 1;
            } else if(s[j] == 'D'){
                test[i][j] = 0;
            } else{
                test[i][j] = -1;
            }
            test[j][i] = test[i][j]*-1;
        }
    }
    while(m--){
        ll a, b;
        cin >> a >> b;
        a--;b--;

        ll count = 0;
        for(ll i = 0; i < n; i++){
            if(test[i][a]==1 && test[i][b]==1){
                count++;
            }
        }
        ll ans = count * n + (n - count) * count;
        cout << ans << endl;
    }
}

int main(){
    ll t;
    // cin >> t;
    t=1;
    while(t--){
        solve();
    }
}

