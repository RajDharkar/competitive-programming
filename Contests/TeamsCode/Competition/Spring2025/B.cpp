#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

struct House {
    int r, c;
    int s, d;
};

int main() {
    int n;
    cin >> n;
    vector<House> houses(n);

    for (int i = 0; i < n; ++i) {
        cin >> houses[i].r >> houses[i].c;
        houses[i].s = houses[i].r + houses[i].c;
        houses[i].d = houses[i].c;
    }
    sort(houses.begin(), houses.end(), [](const House &a, const House &b) {
        if (a.s != b.s) return a.s > b.s;
        return a.d < b.d;
    });

    vector<bool> covered(n, false);
    vector<int> min_cost(n + 1, LLONG_MAX); 

    set<pair<int, int>> uncovered;
    for (int i = 0; i < n; ++i) {
        uncovered.emplace(houses[i].d, i);
    }

    int towers_used = 0;
    int total_cost = 0;
    while (!uncovered.empty()) {
        auto [d_min, idx] = *uncovered.begin();

        int best_idx = -1;
        int best_cover = 0;
        int min_r = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            if (covered[i]) continue;
            int r = houses[i].r, c = houses[i].c;
            int s_limit = r + c;

            int cover_count = 0;
            for (auto &[d, j] : uncovered) {
                if (houses[j].d >= c && houses[j].s <= s_limit) {
                    ++cover_count;
                }
            }

            if (cover_count > best_cover || (cover_count == best_cover && r < min_r)) {
                best_cover = cover_count;
                best_idx = i;
                min_r = r;
            }
        }

        int r = houses[best_idx].r, c = houses[best_idx].c;
        int s_limit = r + c;

        vector<int> to_remove;
        for (auto &[d, i] : uncovered) {
            if (houses[i].d >= c && houses[i].s <= s_limit) {
                covered[i] = true;
                to_remove.push_back(i);
            }
        }

        for (int i : to_remove) {
            uncovered.erase({houses[i].d, i});
        }

        total_cost += r;
        towers_used++;

        min_cost[towers_used] = total_cost;
    }

    for (int i = 1; i <= n; ++i) {
        if (min_cost[i] == LLONG_MAX) {
            min_cost[i] = min_cost[i - 1];
        } else {
            min_cost[i] = min(min_cost[i], min_cost[i - 1]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << min_cost[i] << " ";
    }
    cout << "\n";
}
