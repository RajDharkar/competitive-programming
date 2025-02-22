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
#define sz(x) int((x).size())

int main() {
	// read read read
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll prev = 0;
        ll ans = 1e9;
        for(int i = 1; i <= 9; i++){
            ll num = (prev+1) * 10 -1;
            prev = num;
            //cout << num << endl; 
            ll temp = n;
            for(ll j = 0; j < 10; j++){
                if(to_string(temp).find("7") != string::npos){
                    ans = min(ans, j);
                    continue;
                }
                temp += num;
            }
        }
        cout << ans << endl;
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