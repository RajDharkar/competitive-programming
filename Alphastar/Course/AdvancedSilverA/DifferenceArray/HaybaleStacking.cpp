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


int main() {
	// read read read
    int n, k;
    cin >> n >> k;
    vector<int> diff(n + 1, 0);
    // vector<int> brute(n, 0);
    while(k--){
        int a, b;
        cin >> a >> b;
        a--;b--;
        // for(int i = a; i <= b; i++){
        //     brute[i]++;
        // }
        diff[a]++;
        diff[b+1]--;
        // for(int i = 0; i < n + 1; i++){
        //     cout << diff[i] << " ";
        // }
        // cout << "BRUTE: ";
        // for(int i = 0; i < n + 1; i++){
        //     cout << brute[i] << " ";
        // }
        // cout << endl;
    }
    vector<int> ans;
    int start = 0;

    for(int i = 0; i < n; i++){
        start+=diff[i];
        ans.push_back(start);
    }
    sort(ans.begin(), ans.end());
    cout << ans[n/2] << endl;
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/