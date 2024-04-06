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

// pairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
#define mp make_pair
#define f first
#define s second
void solve(){
    ll y, x;
    cin >> y >> x;
    ll square = max(y, x);
    bool maxX = false;
    if(square % 2 == 0){
        maxX = true;
    }
    ll x2, y2;
    if(maxX){
        x2 = 0;
        y2 = square;
    }
    else{
        x2 = square;
        y2 = 0;
    }
    // pr(x2, y2);
    // cout << endl;
    ll ans = abs(x2 - x) + abs(y2 - y);
    ll squared = square*square;
    cout << squared - ans + 1<< '\n';    
}
int main() {
	// read read read
	int t;
    cin >> t;
    while(t--){
        solve();
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