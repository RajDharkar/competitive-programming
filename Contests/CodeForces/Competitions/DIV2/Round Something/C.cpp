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
int main() {
    // read read read
    ll t;
    cin >> t;
    while(t--){
        ll n; 
        cin >> n;
        vector<int> arr(n);
        for(int i =0; i < n; i++){cin >> arr[i];}
        
        ll ans = min(arr[0], arr[1]);
        for(int i = 1; i < n - 1; i++){
            vector<ll> a(3);
            a[0] = arr[i-1];
            a[1] = arr[i];
            a[2] = arr[i+1];
            sort(a.begin(), a.end());
            ans = max(ans, a[1]); // a[1] will be the median of the three elements
        }
        cout << ans << endl;
        // you should actually read the stuff at the bottom
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/
