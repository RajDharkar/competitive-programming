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

vector<int> pfactors(int n){
    vector<int> ret;
    for(int x = 2; x * x <= n; x++){
        while(n % x == 0){
            ret.push_back(x);
            n/=x;
        }
    }
    if (n > 1) { ret.push_back(n);}
    return ret;
}

int main() {
    // int n;
    // cin >> n;
    // vector<int> factors = pfactors(n);

    // for(int i = 0; i < int(factors.size()); i++){
    //     cout << factors[i] << " ";
    // }
    // cout << endl;
	// // read read read
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 1; i * i <= n; i++){
            if (n % i == 0){
                ans += i * i == n ? 1 : 2;
            }
        }
        cout << ans << '\n';
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