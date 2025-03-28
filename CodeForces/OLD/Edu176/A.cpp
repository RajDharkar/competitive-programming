
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll keven = !(k&1) ? k : k-1;
        ll kodd = (k&1) ? k : k-1;
        ll ans = 0;
        if(n&1){
            n -= kodd;
            ans++;
        }
        if(n==0){
            cout << ans << '\n';
            continue;
        }

        
    }
}

