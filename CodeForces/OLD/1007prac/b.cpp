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


ll sqrt_safe(ll val){
    ll ret = (ll)sqrt(val)-1LL;
    while((ret+1LL)*(ret+1LL)<=val){
        ret++;
    }
    return ret;
}

int main() {
	// read read read
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> ans(n);
        iota(ans.begin(), ans.end(), 1);
        ll sum = 0;
        ll r;
        bool found=0;
        for(int i = 0; i < n-1; i++){
            sum += ans[i];
            ll root = sqrt_safe(sum);
            if(root * root == sum){
                sum -= ans[i];
                swap(ans[i], ans[i+1]);
                sum += ans[i];
                root = sqrt_safe(sum);
                if(root*root==sum){
                    found=1;
                    break;
                }
            } 
        }
        if (!found){
            sum+=ans[n-1];
           // cout << sum << endl;
            ll r = sqrt_safe(sum);
            if(r*r==sum){
                cout << -1 << endl;
                continue;
            }
            else{
                cout << ans[0];
                for(int i = 1; i < n; i++){
                    cout << " " << ans[i];
                }
                cout << endl;
            }
        } else{
            cout << -1 << endl;
        }
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