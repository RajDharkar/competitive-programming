#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, m;
    cin >> n >> m;
    
    vector<ll> arr(n);
    for(auto &score : arr) 
        cin >> score;
    
    ll bitLen = (m == 0 ? 1 : 64 - __builtin_clzll(m));
    
    const ll BIT_MAX = 70;
    vector<vector<ll>> choose(BIT_MAX, vector<ll>(BIT_MAX, 0));
    
    auto initChoose = [&](){
        for (ll i = 0; i < BIT_MAX; i++){
            choose[i][0] = 1;
            choose[i][i] = 1;
            for (ll j = 1; j < i; j++){
                choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
            }
        }
    };
    initChoose();
    
    auto countOnes = [&](ll X, ll target, ll bits) -> ll {
        if(X < 0) return 0;
        ll cnt = 0; 
        ll onesCount = 0;
        for (ll i = 0; i < bits; i++){
            ll bit = (X >> (bits - 1 - i)) & 1;
            if(bit){
                ll remaining = bits - i - 1;
                ll need = target - onesCount;
                if(need >= 0 && need <= remaining)
                    cnt += choose[remaining][need];
                onesCount++;
                if(onesCount > target) break;
            }
        }
        if(onesCount == target) cnt++;
        return cnt;
    };
    
    auto findNext = [&](ll low, ll target, ll bits, ll lim) -> ll {
        ll high = (1LL << bits) - 1;
        if(low > high) return -1;
        ll base = (low > 0 ? countOnes(low - 1, target, bits) : 0);
        if(countOnes(high, target, bits) - base <= 0) return -1;
        ll lo = low, hi = high, ans = -1;
        while(lo <= hi){
            ll mid = lo + (hi - lo) / 2;
            if(countOnes(mid, target, bits) - base > 0){
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    };
    
    vector<map<ll, ll>> dp(n + 1);
    const ll NEG_INF = -LLONG_MAX;
    function<ll(ll, ll)> solve = [&](ll idx, ll low) -> ll {
        if(idx == n) return 0;
        if(dp[idx].count(low)) return dp[idx][low];
        ll best = NEG_INF;
        for (ll ones = 0; ones <= bitLen; ones++){
            ll candidate = findNext(low, ones, bitLen, m);
            if(candidate == -1 || candidate > m) continue;
            ll nextVal = solve(idx + 1, candidate + 1);
            if(nextVal == NEG_INF) continue;
            best = max(best, arr[idx] * ones + nextVal);
        }
        return dp[idx][low] = best;
    };
    
    cout << solve(0, 0) << "\n";
    return 0;
}
