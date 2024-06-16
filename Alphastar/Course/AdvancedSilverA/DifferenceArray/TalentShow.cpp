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
#define sz(x) (int)(x).size()


int main() {
	// read read read
	ll n, m;
    cin >> n >> m;
    vector<pl> pairs;
	vector<ll> ans(2 * m + 2, 0);
	vector<ll> startPos(m + 1, 0);
	vector<ll> endPos(m +1, 0);
    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        pairs.push_back({a, b});
		startPos[a]++;
		endPos[b]++;
    }
	for(int i = 0; i < sz(startPos); i++){
		for(int j = 0; j < sz(startPos); j++){
			ans[i+j]+=startPos[i]*startPos[j];
			ans[i+j+1]-=endPos[i] * endPos[j];
		}
	}
	long num = 0;
	for(ll i = 0; i <= 2 * m; i++){
		num+=ans[i];
		ans[i] = num;
	}
	for(int i = 0; i <= 2 * m; i++){
		cout << ans[i] << endl;
	}
	
	//a + c <= k <= b + d

	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/