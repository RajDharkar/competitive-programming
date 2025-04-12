#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

ll ceil(ll a, ll b){
    return (a + 1) / b;
}

void solve(){
    ll x, n, m;
    cin >> x >> n >> m;

    ll ans1 = x;  
    for(int i = 0; i < n; i++){
        ans1>>=1;
        if(ans1 == 0)break;
    }
    // assert(1 == 2);
    for(int i = 0; i < m; i++){
        ans1 = ceil(ans1, 2);
        if(ans1 <= 1)break;
    }

    ll ans2 = x;  
    for(int i = 0; i < m; i++){
        ans2 = ceil(ans2, 2);
        if(ans2 <= 1)break;

    }
    for(int i = 0; i < n; i++){
        ans2>>=1;
        if(ans2 == 0)break;
    }

    cout << ans2 << " " << ans1 << '\n';

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

