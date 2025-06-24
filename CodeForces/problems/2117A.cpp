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

void solve(){
    ll n, x;
    cin >> n >> x;
    vi arr(n); for(auto &x : arr)cin >> x;
    ll on = 0;
    bool works = 1;
    for(ll i = 0; i < n; i++){
        if(arr[i] && x > 0){
            on = x;
            x = 0;
        }

        if(arr[i]){
            works &= on > 0;
        }

        on = max(on - 1, 0LL);
    }

    cout << (works ? "YES" : "NO") << '\n';
}

int main(){
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}

