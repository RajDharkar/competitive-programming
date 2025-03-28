#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    int n, m;
    cin >> n >> m;
    ordered_set ost;
    for (int i=0; i<n; i++) {
        ll k;cin >> k;
        ost.insert({k, i});  
    }
    while (m--) {
        ll k;cin >> k;
        auto it = ost.upper_bound({k, LLONG_MAX});  
        if (it == ost.begin()) {
            cout << -1 << endl;
        } else {
            cout << (*--it).first << endl;
            ost.erase(it);  
        }
    }
}
