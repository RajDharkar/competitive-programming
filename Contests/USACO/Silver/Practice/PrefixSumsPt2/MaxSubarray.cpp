#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// void setIO(string s) {
// 	freopen((s + ".in").c_str(), "r", stdin);
// 	freopen((s + ".out").c_str(), "w", stdout);
// }
int main() {
    int n;
	cin >> n;
    ll arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll p[n+1];
    for(int i = 0; i < n; i++){
        p[i + 1] = p[i] + arr[i];
    }
}
