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

#define sz(x) int(x.size())

int main() {
	// read read read
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        bool ok = 0;
        if(x < y){
            if(y == x+1){
                ok = 1;
            }
        }
        else{
            if((x - y) % 9 == 8){
                ok = 1;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
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