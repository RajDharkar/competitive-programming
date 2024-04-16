#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <climits>
using namespace std;

using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python!

// vectors
// oops size(x), rbegin(x), rend(x) need C++17

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)

int main() {
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout << 0 << endl;
        return 0;
    }
    int wins = a-b;
    int split = b+1;
    int ans = wins/split;
    if(wins % split != 0){
        ans++;
    }
    cout << ans << endl;
	// read read read
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
