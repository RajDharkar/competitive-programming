#include <algorithm>
#include<bits/stdc++.h>
#include <queue>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main() {
    ll t;
    cin >> t;
    while(t--){
       ll x, y, r;
       cin >> x >> y >> r;
       cout << x - r << " " << y << '\n';
    }
}
