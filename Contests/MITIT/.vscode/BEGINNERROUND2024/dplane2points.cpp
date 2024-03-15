#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i, n) for (int i = 0; (i) < int(n); ++ (i)
#define ALL(x) begin(x), end(x)

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    REP(i, n) cin >> a[i].first >> a[i].second;

    vector<pair<int, int>> b(n);
    REP(i, n) cin >> b[i].first >> b[i].second;

    sort(ALL(a));
    sort(ALL(b));

    vector<int> by;
    int result = 0;

    while (!a.empty()) {
        int ax, ay;
        tie(ax, ay) = a.back();
        a.pop_back();

        while (!b.empty() && ax < b.back().first) {
            by.push_back(b.back().second);
            b.pop_back();
        }

        int j = -1;
        REP(i, by.size()) if (ay < by[i]) {
            if (j == -1 || by[i] < by[j]) {
                j = i;
            }
        }

        if (j != -1) {
            by.erase(by.begin() + j);
            result += 1;
        }
    }

    cout << result << endl;
    return 0;
}
