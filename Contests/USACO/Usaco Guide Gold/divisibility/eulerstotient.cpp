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


int totient(int x){
    //if x is prime totient is x - 1
    //if p is prime then 
    //totient( p^q) = p^q - p^q-1 = p^q-1 (p - 1)
    //n = p1 ^ q2 * p2 ^ q2 ... pK ^ qK 
    //totient(n) = totient(p1 ^ q1) * totient(p2 ^ q2) * (totient(pK ^ qK))
    //p1^(q1 - 1)(p1 - 1) * p2^(q2 - 1)(p2 - 1) * pK^(qK - 1)

    int ans = x;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            while(x % i == 0){x /= i;}
            ans -= ans / i;
        }
    } 
    if(x > 1){ans -= ans / x;}
    return ans;
}

const int max_n = 1e6;
int phi[max_n];
void precompute(){
    for(int i = 1; i <= 1e6; i++){
        phi[i] = i;
    }
    for(int i = 2; i <= 1e6; i++){
        for(int j = i; j <= 1e6; j += i){
            phi[j] -= phi[j] / i;
        }
    }
    for(int i = 1; i <= 20; i++){
        cout << i << " " << phi[i] << endl; 
    }
}
int main() {
	// read read read
    //totient has multiplicative properties as long as n, and m are coprime

    // int x;
    // cin >> x;
    // x+=1;
    // while(x--){
    //     cout << x << " " << totient(x) << endl;
    // }
precompute();

    //say on skibidi
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/