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
    ll arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    ll a = arr[0];
    ll b = arr[1];
    ll c = arr[2];
    string ans = "NO";
    if(a * b == c || b * c == a || a * c == b){
        ans = "YES";
    }
    for(int i = 1; i < 3; i++){
        if(a == b || a == c || c == b){
            ans = "YES";
        }
    }
    for(int i = 0; i < 3; i++){
        if(arr[i] == 0){
            ans = "YES";
        }
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
