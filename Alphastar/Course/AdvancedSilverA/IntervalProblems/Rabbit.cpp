#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define sz(x) (ll)(x).size()
#define f first
#define s second

struct Rabbit {
    ll x;
    bool spots;
};
bool cmp(Rabbit a, Rabbit b) {
    return a.x < b.x;
}
int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<Rabbit> rs(n);
    for (ll i = 0; i < n; i++) {
        string st;
        ll pos;
        cin >> st >> pos;
        rs[i].spots = (st == "S");
        rs[i].x = pos;
    }
    sort(rs.begin(), rs.end(), cmp);

    ll preEndX = -1;
    ll res = 0;
    ll x1 = 0;
    ll x2 = 0;
    if(rs[0].spots){
        x2 = rs[0].x + (rs[1].x - rs[0].x)/2;

        if(x2 >= a){
            x1 = max(x1, a);
            res+=x2 - x1 + 1;
            preEndX = x2;
        }
    }

    for(int i = 1; i < n - 1; i++){
        if(!rs[i].spots){
            continue;
        }
        ll prevD = rs[i].x - rs[i-1].x;
        ll nextD = rs[i+1].x - rs[i].x;

        x1 = rs[i].x - prevD;
        x2 = rs[i].x + nextD;

        res+=x2 - x1 + 1;

        if(x1 == preEndX){
            res--;
        }
        preEndX = x2;

        if(x2 >= a){
            res -= x2 - a;
            break;
        }
    }

    if(x2 < a && rs[n-1].spots){
        ll prevD = (rs[n-1].x - rs[n-2].x)/2; 
        res += prevD;
        if(rs[n-1].x - prevD == preEndX){
            res--;                                              
        }
    }
    cout << res << endl;

    // vector<pii> intervals;
    // if(rs[0].spots){
    //     ll right = (rs[0].x + rs[1].x)/2;
    //     intervals.push_back({0, right});
    // }
    // if(rs[n-1].spots){
    //     ll left = rs[n-1].x-rs[n-2].x;
    //     left/=2;
    //     left = rs[n-1].x - left;
    //     intervals.push_back({left, 1e9});
    // }
    // for(ll i = 1; i < n - 1; i++){
    //     if(rs[i].spots){
    //         ll left = rs[i].x-rs[i-1].x;
    //         left/=2;
    //         left = rs[i].x - left;
    //         ll right = (rs[i].x + rs[i+1].x)/2;
    //         intervals.push_back({left, right});
    //     }
    // }
    // ll ans = 0;
    // for(ll i = 0; i < sz(intervals); i++){
    //     if(intervals[i].s >= b && intervals[i].f >= b){
    //         continue;
    //     }
    //     if(intervals[i].f <= a && intervals[i].s <= a){
    //         continue;
    //     }
    //     //cout << min(b, intervals[i].s) - max(a, intervals[i].f) + 1 << endl;
    //     ans+=min(b, intervals[i].s) - max(a, intervals[i].f) + 1;
    // }
    // cout << ans << endl;

}
