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
typedef pair<ll, ll> pll;
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        pll arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i].second;
        }   
        
        for(int i = 0; i < n; i++){
            cin >> arr[i].first;
        }
        int groups = 1;
        sort(arr, arr + n);
        // for(int i =0; i < n; i++){
        //     cout << arr[i].first << " " << arr[i].second << endl;
        // }
        for(int i = 1; i < n; i++){
            if(arr[i-1].first < arr[i].first && arr[i-1].second <= arr[i].second || arr[i-1].first <= arr[i].second && arr[i-1].second < arr[i].second){
                groups++;
            }
            else{
                arr[i].first = arr[i-1].first;
                arr[i].second = arr[i-1].second;
            }
        }
        cout << groups << endl;
    }
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
