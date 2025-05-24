#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long double, long double> pii;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second

long double mabs(long double i){
    return i < 0 ? -i : i;
}

int main(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> bad(k);
    vector<ll> bl(n+m+1);
    for(auto &x : bad){
        cin >> x;
        bl[x]=1;
    }
    pii cursum = {0, 0};
    vector<pii> dp(n+m+1);
    for(int i = n - 1; i >= 0; i--){
        if(bl[i]){
            dp[i] = {1, 0};
        } else {
            dp[i] = {cursum.f / m, cursum.s / m + 1};
        }
        cursum.f += dp[i].f;
        cursum.s += dp[i].s;
        if(i + m < (ll)dp.size()) { 
            cursum.f -= dp[i + m].f;
            cursum.s -= dp[i + m].s;
        }
    }
    if(mabs(dp[0].f - 1) < 1e-6)cout << -1 << '\n';
    else{
        cout << fixed << setprecision(4) << (dp[0].second / (1 - dp[0].first)) << '\n';
    }
}