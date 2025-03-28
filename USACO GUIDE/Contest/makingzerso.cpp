#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){


    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        unordered_map<ll, ll> memo;
        auto encode = [&](int i, int len, int add) -> ll {
            return (((ll)i << 40) | ((ll)len << 20) | (((unsigned int)(add + 1000000)) & ((1LL << 20) - 1)));
        };
        auto divFloor = [&](int a, int b) -> int {
            return (a >= 0) ? a / b : -(( -a + b - 1) / b);
        };
        function<ll(int, int, int)> dp = [&](int i, int len, int add) -> ll {
            ll key = encode(i, len, add);
            if(memo.count(key)) return memo[key];
            if(len == 1) return memo[key] = llabs((ll)A[i] + add);
            int half = len / 2;
            int blockMin = INT_MAX, blockMax = INT_MIN;
            for (int j = i; j < i + len; j++){
                int val = A[j] + add;
                blockMin = min(blockMin, val);
                blockMax = max(blockMax, val);
            }
            int loX = divFloor(blockMin, len) - 1;
            int hiX = divFloor(blockMax, len) + 1;
            ll best = LLONG_MAX;
            for (int X = loX; X <= hiX; X++){
                ll cost = llabs(X);
                int newAdd = add - X * len;
                cost += dp(i, half, newAdd) + dp(i + half, half, newAdd);
                best = min(best, cost);
            }
            return memo[key] = best;
        };
        cout << dp(0, n, 0) << "\n";
    }
    return 0;
}
