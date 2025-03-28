#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    int t;
    cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        if(x==y){cout << -1 << endl;continue;}
        ll ans = (1LL << 59);
        ans -= max(x, y);
        // assert(x+y+ans*2 == ((x + ans) ^ (y+ans))); 
        cout << ans << '\n';

        // cout << (2 + 576460752303423483) + (5 + 576460752303423483) << endl;
        // cout << ((2 + 576460752303423483) ^ (5 + 576460752303423483)) << endl;
    }
}

