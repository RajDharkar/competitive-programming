#include <bits/stdc++.h>
using namespace std;
 

int main() {
	// read read read
	int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    int ans = min(b,d) - max(a,c);
	if(ans < 0){ans = 0;}
    int total = b - a + d - c;
	cout << total - ans;
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/