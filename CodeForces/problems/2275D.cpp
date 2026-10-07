#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> s(n);
        vector<ll> p(n);
        ll lo = 5e18;

        for (int i = 0; i < n; i++) {
            ll a,b,c; 
            cin >> a >> b >> c;
            s[i] = a + b + c;

            lo = min(lo, s[i]);

            if (a == b && b == c) {
                p[i] = -1;}
            else if (a > b || a > c || b > c) {
                p[i] = 0;}
            else {
                ll q = b - a + 1;
                if (a < b) {
                    q = min(c - b + 1, q);
                }
                p[i] = q + q;
            }
        }

        auto check = [&](ll x) {
            ll v = 0;
            for (int i = 0; i < n; i++) 
                if (s[i] < x) {
                    if (p[i] == -1) return false;
                    
                    v += x - s[i] + p[i]; 
                    if (v > k) return false;
                }
            return true;
        };

        ll r = lo + k + 1;
        while (lo + 1 < r) {
            ll mid = lo + (r - lo) /2;
            if(check(mid))
                lo = mid;
            else
                r = mid;
        }
        cout << lo << '\n';
    }
}

