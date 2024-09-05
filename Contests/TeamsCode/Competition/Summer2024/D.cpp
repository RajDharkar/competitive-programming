#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;
ll MOD = 1e9 + 7;
int main() {
    int n;
    cin >> n;

    set<int> cur;
    for (int i = 1; i <= 2 * n; ++i) {
        cur.insert(i);
    }
    cur.erase(1);

    vector<int> a = {1};
    vector<int> b;
    ll tot = 2;

    for (int i = 0; i < n; ++i) {
        int t, v;
        cin >> t >> v;
        if (a.size() == 1 && b.size() == 0) {
            if (t == 1){
                b.push_back(v - 1);
                cur.erase(v - 1);
            }
            else if(t == 2) {
                b.push_back(v + 1);
                cur.erase(v + 1);
            } else {
                b.push_back(v);
                cur.erase(v);
            }
            continue;
        }
        int smallest = *cur.begin();
        if (smallest > a.back() && smallest > b.back()) {
            tot *= 2;
            tot %= MOD;
        }
        a.push_back(smallest);
        cur.erase(smallest);
        if (t == 1) {
            b.push_back(v - smallest);
            cur.erase(v - smallest);
        } else if (t == 2) {
            b.push_back(smallest + v);
            cur.erase(smallest + v);
        } else {
            b.push_back(v);
            cur.erase(v);
        }
    }

    cout << tot << endl;

    return 0;
}
