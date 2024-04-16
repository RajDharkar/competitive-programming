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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int grid[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }
        int topLeft = grid[0][0];
        int topRight = grid[0][n-1];
        int bottomLeft = grid[n-1][0];
        int bottomRight = grid[n-1][n-1];
        bool works = false;
        if(topLeft == topRight || topRight == bottomRight || bottomRight == bottomLeft || bottomLeft == topLeft){
            works = true;
        }
        if(!works){
            cout << -1 << endl;
        }
        
    	// read read read
	}// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
