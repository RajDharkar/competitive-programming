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
#include <unordered_set>
#include <stack>
using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python! 

// pairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
#define mp make_pair
#define f first
#define s second


int main() {
	// read read read
	int n, m;
    cin >> n >> m;
    vector<pi> pairs;
	vector<int> ans(2 * m + 1)
	vector<int> startPos(2 * m + 2);
	vector<int> endPos(2 * m + 2);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        pairs.pb({a, b});
		startPos[n]++;
		endPos[m]++;
    }
	for(int i = 0; i < sz(startPos); i++){
		
	}

	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/