#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int n, m;
 
int main() {
	cin >> n >> m;
    ll heights[n];
	for (int i = 0; i < n; i++) cin >> heights[i];
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		int l = 0;
		for (int j = 0; j < n && l < x; j++) {
			int diff = max(0, (int)min(heights[j], (ll)x)-l);
			heights[j] += diff;
			l += diff;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << heights[i] << '\n';
	}
}