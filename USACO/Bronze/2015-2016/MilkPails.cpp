#include <bits/stdc++.h>
using namespace std;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
    setIO("pails");
    int x, y, m;
    cin >> x >> y >> m;
    int sum = 0;
    int ans = 0;
    for(int i = 0; i < (m+x-1)/x; i++){
        for(int j = 0; j < (m+y-1)/y; j++){
            sum = x*i+j*y;
            if(sum<=m){
                ans = max(ans, sum);
            }
        }
    }
    cout << ans;
}
