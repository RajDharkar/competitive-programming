#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9+7

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> dp(n + 1, INF);
        dp[0] = 0; 

        deque<pair<int, int>> dq;

        for (int i = 1; i <= n; i++) {
            while (!dq.empty() && dq.front().second < i - k) {
                dq.pop_front();
            }
            if (!dq.empty()) {
                dp[i] = dq.front().first;
            }
            if ((s[i - 1] == 'R' && dp[i] != INF) || (s[i - 1] == 'B' && dp[i] == INF)) {
                dp[i] = min(dp[i], a[i - 1]);
            }
            while (!dq.empty() && dq.back().first > dp[i]) {
                dq.pop_back();
            }
            dq.push_back({dp[i], i});
        }

        cout << (dp[n] == INF ? 0 : dp[n])<< endl;
    }
}
