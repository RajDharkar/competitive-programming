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

// ll main(){
//     ll t;
//     cin >> t;
//     while(t--){
//         ll n;
//         cin >> n;
//         vi a(n), b(n);
//         for(auto &x : a)cin >> x;
//         for(auto &x : b)cin >> x;
//         sort(all(a));
//         sort(all(b), greater<ll>());
//         ll res = a[0] ^ b[0];
//         for(ll i = 1; i < n; i++){
//             ll x = a[i] ^ b[i];
//             res &= x;
//             // cout << x << " ";
//         }
//         cout << res << '\n';
//         // do{
//         //     ll res = a[0] ^ b[0];
//         //     for(ll i = 1; i < n; i++){
//         //         ll x = a[i] ^ b[i];
//         //         res &= x;
//         //     }
//         //     cout << res << '\n';
//         //     if(res == 2){
//         //         cout << "HEORWHOEHR\n";
//         //         for(auto x : b){
//         //             cout << x << " ";
//         //         }
//         //         cout << '\n';
//         //     }
//         // } while(next_permutation(all(b)));
//     }
// }


int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vi a, b;
        res(a, n); res(b, n);
        for(auto &x : a)cin >> x;
        for(auto &x : b)cin >> x;

        ll ans = 0;
        for(ll i=30; i >= 0; i--){
            ll cur = ans|(1<<i);
            vi num1, num2;
            for(ll j = 0; j < n; j++){
                num1.pb(cur & a[j]); num2.pb(cur & (~b[j]));
            }
            sort(all(num1)); sort(all(num2));
            bool works = 1;
            for(ll j = 0; j < n; j++){
                works &= num1[j] == num2[j];
            }
            if(works){
                ans |= (1 << i);
            }
        }
        cout << ans << '\n';
    }
}
