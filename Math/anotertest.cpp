#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    ll k;
    cin >> k;
    int ans = 1e9;
    ll count = 1000;
    ll t = k;
    while(count--){
        ll n = t;
        // string s = "";
        // do{
        //     if(n&1){
        //         s.append("1");
        //     } else{
        //         s.append("0");
        //     }
        // } while(n /= 2);
        // reverse(all(s));
        // cout << s << endl;
        ans = min(__popcount(n), ans);
        if(ans == 2){
            cout << n << endl;
        }
        t+=k;
    }
    cout << ans << endl;
}