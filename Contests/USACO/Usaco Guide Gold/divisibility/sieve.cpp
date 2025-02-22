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
//largest prime that goes into i
const int max_n = 1e6;
int sieve[max_n + 1];

//this is way faster in fact 2x faster than normal

int main() { 
    for(int i = 2; i <= max_n; i++){
        if(sieve[i] == 0){
            for(int j = i; j <= max_n + 1; j += i){
                sieve[j] = i;
                //using a sieve to determine if its 
            }
        }
    }
    // for(int i = 1; i <= 100; i++){
    //     cout << sieve[i] << " ";
    // }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 1;
        while(n != 1){
            int max_div = sieve[n];
            int prime_count = 0;
            while(n % max_div == 0){
                prime_count++;
                n /= max_div;
            }
            ans *= prime_count + 1;
        }
        cout << ans << '\n';
    }
	// read read read
//	setIO();
	
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/