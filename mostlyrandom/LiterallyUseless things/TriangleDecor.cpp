#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

using ll = long long;
using pl = pair<ll, ll>;

struct Event {
    int x;
    int id;
    bool isLeft;
};

bool cmp(Event a, Event b) {
    if (a.x == b.x) return a.isLeft > b.isLeft;
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;
    vector<pl> peaks(n);
    vector<Event> points(2 * n);

    for (int i = 0; i < n; i++) {
        cin >> peaks[i].first >> peaks[i].second;
    }

    for (int i = 0; i < n; i++) {
        points[2 * i] = {peaks[i].first - peaks[i].second, i, true};
        points[2 * i + 1] = {peaks[i].first + peaks[i].second, i, false};
    }

    sort(points.begin(), points.end(), cmp);

    int lapped = 0;
    int activeIntervals = 0;
    unordered_set<int> activeIds;

    for (int i = 0; i < 2 * n; i++) {
        if (points[i].isLeft) {
            if (!activeIds.empty() && activeIds.count(points[i].id)) {
                lapped++;
            }
            activeIntervals++;
            activeIds.insert(points[i].id);
        } else {           
            activeIntervals--;
            activeIds.erase(points[i].id);
        }
    }

    cout << n - lapped << endl;

    return 0;
}
