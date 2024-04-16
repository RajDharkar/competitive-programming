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
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<int> arr;
    for(int i=0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }   
    sort(all(arr));
    int cap;
    cin >> cap;
    int ft;
    cin >> ft;
    int wt;
    cin >> wt;
    ll ans = 0;
    if(wt <= ft){
        for(int i = 0; i < n; i++){
            ans+=wt*arr[i];
        }
        cout << ans << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            if(i < n-cap){
                ans+=wt*arr[i];
            }
            else{
                ans+=ft*arr[i];
            }
        }
        cout << ans << endl;
    }

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
