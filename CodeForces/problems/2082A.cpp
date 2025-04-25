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
    vector<string> arr;
    for(ll i = 0; i < n; i++){
        string k;
        cin >> k;
        arr.pb(k);
    }
    // cout << n << " " << m << endl;
    // assert(1 == 2);
    ll r = 0;
    ll c = 0;
    for(ll i = 0; i < n; i++){
        ll k = (arr[i][0] == '1');
        for(ll x = 1; x < m; x++){
            k ^= (arr[i][x] == '1');
        }
        // assert(1 == 2);
        if(k == 1)r++;
    }
    for(ll i = 0; i < m; i++){
        ll k = arr[0][i] == '1';
        // cout << k << " ";
        for(ll j = 1; j < n; j++){
            k ^= (arr[j][i] == '1');
            // cout << arr[j][i] << " ";
        }
        // cout << endl;
        c += k == 1;
    }

    // cout << r << " " << c << endl;
    cout << max(r, c) << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}

