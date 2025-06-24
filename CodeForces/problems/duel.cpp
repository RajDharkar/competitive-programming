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
    ll n;
    cin >> n;
    vi arr(n);
    for(auto &x : arr)cin >> x;
    cout << n-1 << '\n';
    if(n > 1) {
        cout << 1 << ' ' << n << '\n';
    }
    ll use = 0;
    if((arr[0] + arr[n - 1]) % 2 == 1){
        use = arr[0];
    } else {
        use = arr[n-1];
    }
    for(ll i = 1; i < n - 1; i++) {
        if((use + arr[i]) % 2 == 0) {
            cout << i + 1 << " " << n << '\n';
        }
        else {
            cout << 1 << " " << i + 1<< '\n';
        } 
    }
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}

