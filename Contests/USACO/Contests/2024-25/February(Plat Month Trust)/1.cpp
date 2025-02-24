#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int N;
vector<int> a;
vector<ll> cost;
vector<int> state;

ll dfs(int cur) {
    vector<int> cycle;
    while (state[cur] == 0) {
        state[cur] = 1;
        cycle.push_back(cur);
        cur = a[cur];
    }

    if (state[cur] == 1) { // Found a cycle
        ll minCost = 1e9;
        int x = cur;
        do {
            minCost = min(minCost, cost[x]);
            state[x] = 2;
            x = a[x];
        } while (x != cur);
        return minCost;
    }

    for (int node : cycle) state[node] = 2;
    return 0;
}

int main() {
    cin >> N;
    a.resize(N + 1);
    cost.resize(N + 1);
    state.assign(N + 1, 0);

    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> cost[i];

    ll totalCost = 0;
    for (int i = 1; i <= N; i++) {
        if (state[i] == 0) {
            totalCost += dfs(i);
        }
    }

    cout << totalCost << "\n";
    return 0;
}
