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
using db = long double; 
using str = string; 

int main() {
	// read read read
	int n;
    cin >> n;
    int prev = -1e9;
    int curCount = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num > prev){
            curCount++;
        }
        else{
            if(curCount >= 3){
                ans++;
            }
            curCount = 1;
        }
        prev = num;
    }
    cout << ans;

	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/