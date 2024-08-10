#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> moves(m);
    for (int i = 0; i < m; ++i) {
        cin >> moves[i].first >> moves[i].second;
    }

    vector<pair<int, int>> trolMoves(q);
    for (int i = 0; i < q; ++i) {
        cin >> trolMoves[i].first >> trolMoves[i].second;
    }

    vector<int> s = a;
    sort(s.begin(), s.end());

    // Apply moves in reverse order
    reverse(moves.begin(), moves.end());
    for (auto& [a, b] : moves) {
        swap(s[a], s[b]);
    }

    for (int i = 0; i < q; ++i) {
        swap(s[trolMoves[i].first], s[trolMoves[i].second]);
        if (s == a) {
            ans.push_back("Y");
        } else {
            ans.push_back("N");
        }
    }

    for (const auto& res : ans) {
        cout << res;
    }

    return 0;
}
