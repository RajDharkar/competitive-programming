#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second
#define vi vector<ll>
#define vvi vector<vi>
#define res(x, n) (x).resize(n)

void solve() {
    ll n, si;
    string a, b;
    vi k;
    cin >> n >> a;
    b = a; sort(b.begin(), b.end());
    char c = 'a';
    for (ll i = n - 1; i >= 0; i--) {
        if (ll(a[i]) >= ll(c)) {
            k.push_back(i);
            c = a[i];
        }
    }
    si = k.size();

    for (ll i = 0; i < si / 2; i++){
        swap(a[k[i]], a[k[si - 1 - i]]);
    }

    bool works = a == b;
    ll ans = si;
    if(!works){
        cout << "-1\n";
        goto end;
    }

    for (int i = 0; i < sz(k); i++) {
        ans -= a[k[i]] == a[k[0]];
    }
    cout << ans << "\n";
    end:;
}

int main() {
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
